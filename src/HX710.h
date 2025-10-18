/*
 * HX710 Pressure Sensor Interface
 * Based on vendor reference implementation
 * Refactored and documented by me
 */

#ifndef HX710_H
#define HX710_H

#include <Arduino.h>

// === Pin Definitions ===
#define HX710_SCK_PIN 2
#define HX710_DT_PIN  3

// === Calibration Coefficient ===
// Adjust this based on your own sensor calibration
// Larger value -> smaller reading; smaller value -> larger reading
static float HX710_SCALE = 7.35f;   

// === Global Variables ===
static long tareValue = 0;

// === Function Declarations ===
void initHX710();
void tareHX710();
unsigned int readHX710();
unsigned long readHX710Raw();

#endif
