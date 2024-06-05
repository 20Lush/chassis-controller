#include <Adafruit_NeoPixel.h>
#include <sstream>
#include <string>
#include <Servo.h>
#include <cmath>

#include "motor.hpp"
#include "R8EF.hpp"
#include "lights.hpp"

Adafruit_NeoPixel pixel(1, 25, NEO_GRB + NEO_KHZ800);

const size_t PCB_LIGHTS_BRIGHTNESS = 50;
Adafruit_NeoPixel pcb_lights(1, 21, NEO_GRB + NEO_KHZ800);

R8EF rx;
EIGHT_CHANNEL raw_inputs;

// Left, Right
const unsigned int NUM_MOTORS = 2;
std::array<Motor, NUM_MOTORS> motors = {Motor(A2), Motor(A1)};

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
  rx.Init();

  for(Motor& motor : motors) {
    motor.Init();
  }

  delay(1500);
}

void loop() {

  raw_inputs = rx.getRaw();

  // example mapping the raw inputs from the rxer to float percentage
  // double X1 = fmap(raw_inputs.ch4, 1000, 2000, -1, 1);
  // double Y1 = fmap(raw_inputs.ch3, 1000, 2000, -1, 1);
  // double X2 = fmap(raw_inputs.ch1, 1000, 2000, -1, 1);
  // double Y2 = fmap(raw_inputs.ch2, 1000, 2000, -1, 1);

  // these channel assignments might be wrong idk
  uint16_t X1 = raw_inputs.ch4;
  uint16_t X2 = raw_inputs.ch1;

  // motor setter routine. 1000-2000, so 1500 corresponds to zero.
  motors[0].Set_uSec(X1);
  motors[1].Set_uSec(X2);


}

/////////////////////////// CORE 2 ///////////////////////////
///    FOR HIGH FREQUENCY DATA COLLECTION & PROCESSING     ///
//////////////////////////////////////////////////////////////
void setup1() {

  pcb_lights.begin();
  pcb_lights.show();
  pcb_lights.setBrightness(PCB_LIGHTS_BRIGHTNESS);
}

void loop1() {

  
  colorWipe(pcb_lights, pcb_lights.Color(255,   0,   0)     , 50); // Red
  colorWipe(pcb_lights, pcb_lights.Color(  0, 255,   0)     , 50); // Green
  colorWipe(pcb_lights, pcb_lights.Color(  0,   0, 255)     , 50); // Blue
}
