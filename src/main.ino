#include "HX710.h"

#define RELAY_PIN 8
#define LED_PIN 13
#define SENSOR_PIN A0


void samplePhase(bool pumpOn, int samples, int interval_ms, float initialR);

void setup() {

  Serial.begin(9600);
  pinMode(RELAY_PIN, OUTPUT);
  pinMode(LED_PIN, OUTPUT);


  digitalWrite(RELAY_PIN, LOW);

  // Initialize HX710
  initHX710();
  tareHX710();

  // Initializing flexble sensor
  float v1 = analogRead(SENSOR_PIN) * (5.0 / 1023.0);
  delay(300);
  float v2 = analogRead(SENSOR_PIN) * (5.0 / 1023.0);
  delay(300);
  float v3 = analogRead(SENSOR_PIN) * (5.0 / 1023.0);

  float d1 = v2 - v1;
  float d2 = v2 - v3;

  if (-0.01 <= d1 && d1 <= 0.01 && -0.01 <= d2 && d2 <= 0.01) {
   
    digitalWrite(LED_PIN, HIGH);
    float initialR = 10000.0 * v2 / (5.0 - v2);
    Serial.println("-------------------- Initialization Successful --------------------");
    delay(1000);

    //Pressurization
    samplePhase(true,  10, 50,  initialR);

    //Depressurization
    samplePhase(false, 15, 100, initialR);

    Serial.println("************* Please Restart the Program Before Reuse *************");

    while (1);
  } else {

    digitalWrite(LED_PIN, HIGH);
    delay(300);
    digitalWrite(LED_PIN, LOW);
    Serial.println("------------------------- Initializing... -------------------------");
  }
}

void samplePhase(bool pumpOn, int samples, int interval_ms, float initialR) {
  digitalWrite(RELAY_PIN, pumpOn ? HIGH : LOW);

  for (int i = 0; i < samples; i++) {
 
    float v = analogRead(SENSOR_PIN) * (5.0 / 1023.0);
    float currentR = 10000.0 * v / (5.0 - v);
    float percentage = (currentR - initialR) / initialR * 100;


    int pressure = readHX710();

    Serial.print("Current Pressure = ");              
    Serial.print(pressure);
    Serial.println(" Pa");

    Serial.print("DeltaR/R = ");            
    Serial.print(percentage);
    Serial.println(" %");
    Serial.println("");

    delay(interval_ms);
  }
}

