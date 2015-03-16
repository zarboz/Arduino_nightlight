#include <Adafruit_NeoPixel.h>
#define PIN 4
#define NUMPIXELS 16

const int onbuttonPin = 3;
//int buttonState1 = 0;
boolean currswitch1state = LOW;
boolean lastswitch1state = LOW;

const int offbuttonPin = 2;
//int buttonState2 = 0;
boolean currswitch2state = LOW;
boolean lastswitch2state = LOW;

Adafruit_NeoPixel strip = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  Serial.begin(9600);
  strip.begin();
  strip.show();
  pinMode(onbuttonPin, INPUT);
  pinMode(offbuttonPin, INPUT);
}

void loop() {
  currswitch1state = digitalRead(onbuttonPin);
  currswitch2state = digitalRead(offbuttonPin);
  if (currswitch1state == HIGH && lastswitch1state == LOW) {
  Serial.println("Lights on");
  Serial.println(currswitch1state);
  colorWipe(strip.Color(255, 255, 255), 25);
  }
   if (currswitch2state == HIGH && lastswitch2state == LOW) {
     Serial.println("Switch 2 on");
  Serial.println(currswitch2state);
  colorWipe(strip.Color(0, 0, 0), 5); 
   }
}

void colorWipe(uint32_t c, uint8_t wait) {
  for(uint16_t i=0; i<strip.numPixels(); i++) {
      strip.setPixelColor(i, c);
      strip.show();
      delay(wait);
  }
  lastswitch1state = currswitch1state;
  lastswitch2state = currswitch2state;
}