#include <Adafruit_NeoPixel.h>
#include <Servo.h>

Adafruit_NeoPixel pixel(1, 25, NEO_GRB + NEO_KHZ800);


const int channel_1 = 5;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(channel_1, INPUT_PULLUP);

}

void loop() {
  // put your main code here, to run repeatedly:
  
  pixel.fill(0xFF0000);
  pixel.show();
  int val = pulseIn(channel_1, HIGH, 25000);
  Serial.println(val);
	delay(500);

  pixel.fill(0x000FF0);
  pixel.show();

  delay(500);

}
