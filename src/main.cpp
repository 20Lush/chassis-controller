#include <Adafruit_NeoPixel.h>
#include <Servo.h>
#include <sstream>
#include <string>

#include "r8ts.hpp"

Adafruit_NeoPixel pixel(1, 25, NEO_GRB + NEO_KHZ800);

R8TS r8ts;
std::array<int, R8TS::num_channels> inputs;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);

}

void loop() {
  // put your main code here, to run repeatedly:

  inputs = r8ts.getPercents();

}
