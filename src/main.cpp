#include <Adafruit_NeoPixel.h>
#include <sstream>
#include <string>
#include <Servo.h>
#include <cmath>

#include "motor.hpp"
#include "R8EF.hpp"

Adafruit_NeoPixel pixel(1, 25, NEO_GRB + NEO_KHZ800);

R8EF rx;
EIGHT_CHANNEL raw_inputs;

// Left, Right, Back
const unsigned int NUM_MOTORS = 3;
std::array<Motor, NUM_MOTORS> motors = {Motor(A2), Motor(A1), Motor(A3)};

const double sqrt3div2 = sqrt(3)/2;

double fmap(double x, double in_min, double in_max, double out_min, double out_max)
{
  return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}
/////////////////////////// CORE 1 ///////////////////////////
///       FOR TIME IN-SENSITIVE OVERHEAD OPERATIONS        ///
//////////////////////////////////////////////////////////////
void setup() {
  Serial.begin();
  
  for(Motor& motor : motors) {

    motor.Init();

  }

  delay(1500);

}

void loop() {
  double X = fmap(raw_inputs.ch4, 1000, 2000, -1, 1);
  double Y = fmap(raw_inputs.ch3, 1000, 2000, -1, 1);
  double R = fmap(raw_inputs.ch1, 1000, 2000, -1, 1);

  motors[0].Set_uSec((((-0.5 * X) - (sqrt3div2 * Y) - R) * 500) + 1500);
  motors[1].Set_uSec((((-0.5 * X) + (sqrt3div2 * Y) - R) * 500) + 1500);
  motors[2].Set_uSec((( X - R) * 500) + 1500);

}

/////////////////////////// CORE 2 ///////////////////////////
///    FOR HIGH FREQUENCY DATA COLLECTION & PROCESSING     ///
//////////////////////////////////////////////////////////////
void setup1() {

  rx.Init();

}

void loop1() {

  raw_inputs = rx.getRaw();

}
