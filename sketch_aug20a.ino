#include "FastLED.h"

#define sensor 0       
#define numLeds 8
#define dataPin 13
        
CRGB leds[numLeds];

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  FastLED.addLeds<NEOPIXEL, dataPin>(leds, numLeds); 
  FastLED.setBrightness(10);
  leds[1] = CRGB::Green;
  FastLED.show();
  delay(2000);
}

void loop() {
  // put your main code here, to run repeatedly:
  short Detect = analogRead(sensor);
  Serial.println(analogRead(sensor));
  
  if(Detect < 700) {
    for(int i = 0; i < numLeds; i++) {
      leds[i] = CRGB::Red;
      }
      FastLED.show();
    }

  if(Detect >= 700) {
    for(int i = 0; i < numLeds; i++) {
      leds[i] = CRGB::Green;
      }
    FastLED.show();
    }
}
