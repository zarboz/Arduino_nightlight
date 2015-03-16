#include <Adafruit_NeoPixel.h>
#define PIN 4
#define NUMPIXELS 16

const int onbuttonPin = 3;
//int buttonState1 = 0;
boolean currswitch1state = LOW;
boolean lastswitch1state = LOW;
boolean lampState = FALSE;

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
  if (currswitch1state == HIGH && lastswitch1state == LOW) 
  {
   lampState = !lampState;  // toggle the lamp state
  }
  if (lampState == true)
  {
     colorWipe(strip.Color(255, 255, 255), 25);  // lamp on
  }
  else
  {
     colorWipe(strip.Color(0, 0, 0), 25);  // lamp off
  }
  lastswitch1state = currswitch1state;
  lastswitch2state = currswitch2state;
}

