CODE: SELECT ALL | TOGGLE FULL SIZE
#include <Adafruit_NeoPixel.h>
#define PIN 4
#define NUMPIXELS 16

const int onbuttonPin = A0;
int buttonState1 = 0;

const int offbuttonPin = A4;
int buttonState2 = 0;

Adafruit_NeoPixel strip = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  Serial.begin(9600);
  strip.begin();
  strip.show();
  pinMode(onbuttonPin, INPUT);
  pinMode(offbuttonPin, INPUT);
}

void loop() {
  buttonState1 = analogRead(onbuttonPin);
  buttonState2 = analogRead(offbuttonPin);
  if (buttonState1 == 1) {
  Serial.println("Lights on");
  Serial.println(buttonState1);
  colorWipe(strip.Color(255, 255, 255), 75);
  }
   if (buttonState2 == 1) {
     Serial.println("Switch 2 on");
  Serial.println(buttonState2);
  colorWipe(strip.Color(0, 0, 0), 100); 
   }
}

void colorWipe(uint32_t c, uint8_t wait) {
  for(uint16_t i=0; i<strip.numPixels(); i++) {
      strip.setPixelColor(i, c);
      strip.show();
      delay(wait);
  }
}
