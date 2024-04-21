#include "r8ts.hpp"

void R8TS::Init() {
    ch1.attach();
    ch2.attach();
    ch3.attach();
    ch4.attach();
    ch5.attach();
    ch6.attach();
    ch7.attach();

    while(!ServoInput.allAvailable()){
        Serial.println("Waiting for servo signals...");
		delay(500);
    }
}

std::array<int, R8TS::num_channels> R8TS::getRaw() {
    return {
            ch1.getPulse(),
            ch2.getPulse(),
            ch3.getPulse(),
            ch4.getPulse(),
            ch5.getPulse(),
            ch6.getPulse(),
            ch7.getPulse()
    };
}

std::array<int, R8TS::num_channels> R8TS::getAngles() {
    return {
            ch1.getAngle(),
            ch2.getAngle(),
            ch3.getAngle(),
            ch4.getAngle(),
            ch5.getAngle(),
            ch6.getAngle(),
            ch7.getAngle()
    };
}

std::array<int, R8TS::num_channels> R8TS::getPercents() {
    return {
            ch1.map(-100, 100),
            ch2.map(-100, 100),
            ch3.map(-100, 100),
            ch4.map(-100, 100),
            ch5.map(-100, 100),
            ch6.map(-100, 100),
            ch7.map(-100, 100)
    };
}