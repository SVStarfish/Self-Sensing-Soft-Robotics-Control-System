#include "HX710.h"

// ---------------------------------------------------------------------------
// Initialize HX710 sensor pins
// ---------------------------------------------------------------------------
void initHX710() {
  pinMode(HX710_SCK_PIN, OUTPUT);
  pinMode(HX710_DT_PIN, INPUT);
}

// ---------------------------------------------------------------------------
// Tare / Zeroing function
// Reads current raw value and sets it as the reference
// ---------------------------------------------------------------------------
void tareHX710() {
  unsigned long raw = readHX710Raw();
  tareValue = raw / 100;
}

// ---------------------------------------------------------------------------
// Read weight/pressure value (in arbitrary units)
// Returns calibrated sensor value after tare and scaling
// ---------------------------------------------------------------------------
unsigned int readHX710() {
  unsigned long raw = readHX710Raw() / 100;
  long value = (long)raw - tareValue;

  // Apply scale factor (calibration)
  unsigned int calibrated = (unsigned int)((float)value / HX710_SCALE);
  return calibrated;
}

// ---------------------------------------------------------------------------
// Read 24-bit raw value from HX710 ADC
// Based on HX711 communication protocol
// ---------------------------------------------------------------------------
unsigned long readHX710Raw() {
  unsigned long count = 0;

  digitalWrite(HX710_DT_PIN, HIGH);
  delayMicroseconds(1);
  digitalWrite(HX710_SCK_PIN, LOW);
  delayMicroseconds(1);

  // Wait for data ready
  while (digitalRead(HX710_DT_PIN));

  // Read 24 bits of data
  for (byte i = 0; i < 24; i++) {
    digitalWrite(HX710_SCK_PIN, HIGH);
    delayMicroseconds(1);
    count <<= 1;
    digitalWrite(HX710_SCK_PIN, LOW);
    delayMicroseconds(1);
    if (digitalRead(HX710_DT_PIN)) count++;
  }

  // 25th pulse sets gain and completes the read
  digitalWrite(HX710_SCK_PIN, HIGH);
  count ^= 0x800000;  // Convert to signed 24-bit
  delayMicroseconds(1);
  digitalWrite(HX710_SCK_PIN, LOW);
  delayMicroseconds(1);

  return count;
}
