/*
 * WS2812B LED strip on hand rail for stairs. Sensors at the top
 * and the bottom.
 */

#include <FastLED.h>

#define NUM_LEDS 164
#define DATA_PIN 13
#define BRIGHTNESS 40
#define LED_TYPE WS2812B
#define COLOR_ORDER GRB
CRGB leds[NUM_LEDS];

int sensorPin0 = A0;
int sensorPin1 = A1;
int ledPin = 13;
int sensorValue0 = 0;
int sensorValue1 = 0;

void setup() {
  delay(3000);
  FastLED.addLeds<WS2812B, DATA_PIN, RGB>(leds, NUM_LEDS);
  FastLED.setBrightness(BRIGHTNESS);
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  do {
    sensorValue0 = analogRead(sensorPin0);
    sensorValue1 = analogRead(sensorPin1);
    Serial.println(sensorValue0, DEC);
    Serial.println(sensorValue1, DEC);
  } while(sensorValue0 < 600 && sensorValue1 < 600);
  
  if (sensorValue0 > 600) {
    Serial.println("----- Sensor 0 ACTIVE-----");
    for (int i = 0; i < NUM_LEDS; i++) {
      leds[i] = CRGB(255, 255, 200);
    }
  }
  
  if (sensorValue1 > 600) {
    Serial.println("----- Sensor 1 ACTIVE-----");
    for (int i = 0; i < NUM_LEDS; i++) {
      leds[i] = CRGB(255, 255, 200);
    }
  }

  FastLED.show();
  delay(7000); // time LEDs are on
  for (int i = 0; i < NUM_LEDS; i++) {
    leds[i] = CRGB::Black;
  }
  FastLED.show();
  delay(5000); // delay to prevent second sensor fram triggering LEDs to turn on again
}
