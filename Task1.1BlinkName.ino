#include "arduino_secrets.h"
#include "thingProperties.h"

//defining the timing for morse code
const int dotLength = 250; // 1 unit of time
const int dashLength = 750; // 3 units of time
const int letterSpace = 750; //3 units of time

void setup() {
  // initialize serial and wait for port to open:
  Serial.begin(9600);
  // this delay gives the chance to wait for a Serial Monitor without blocking if none is found
  delay(1500);

  setDebugMessageLevel(2);
  ArduinoCloud.printDebugInfo();

  // defined in thingProperties.h
  initProperties();

  // connect to Arduino IoT Cloud
  ArduinoCloud.begin(ArduinoIoTPreferredConnection);
  
  // initialize digital pin LED_BUILTIN (Pin 13) as an output.
  pinMode(LED_BUILTIN, OUTPUT);
}

  // LED blink information stored here
void blinkLED(int duration) {
  digitalWrite(LED_BUILTIN, HIGH);
  delay(duration);
  digitalWrite(LED_BUILTIN, LOW);
  ArduinoCloud.update();
  delay(duration);
}
  //blink for a dot called from the blinkLED function
void dot() {
  blinkLED(dotLength);
}

//blink for a dash called from the blinkLED function
void dash() {
  blinkLED(dashLength);
}


//hardcoded functions to blink my name
void blinkT() {
  dash();
  delay(letterSpace);
}

void blinkI() {
  dot(); dot();
  delay(letterSpace);
}

void blinkM() {
  dash(); dash();
  delay(letterSpace);
}

void blinkO() {
  dash(); dash(); dash();
  delay(letterSpace);
}

void blinkH() {
  dot(); dot(); dot(); dot();
  delay(letterSpace);
}

void blinkY() {
  dash(); dot(); dash(); dash();
  delay(letterSpace);
}

void loop() {
  blinkT();
  blinkI();
  blinkM();
  blinkO();
  blinkT();
  blinkH();
  blinkY();
  
}

