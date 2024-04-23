#include "R8EF.hpp"

void R8EF::Init() {
    SIP_ch1.attach();
    SIP_ch2.attach();
    SIP_ch3.attach();
    SIP_ch4.attach();
    SIP_ch5.attach();
    SIP_ch6.attach();
    SIP_ch7.attach();

}

EIGHT_CHANNEL R8EF::getRaw() {
    return {
            SIP_ch1.getPulse(),
            SIP_ch2.getPulse(),
            SIP_ch3.getPulse(),
            SIP_ch4.getPulse(),
            SIP_ch5.getPulse(),
            SIP_ch6.getPulse(),
            SIP_ch7.getPulse()
    };
}

std::array<float, R8EF::num_channels> R8EF::getAngles() {
    return {
            SIP_ch1.getAngle(),
            SIP_ch2.getAngle(),
            SIP_ch3.getAngle(),
            SIP_ch4.getAngle(),
            SIP_ch5.getAngle(),
            SIP_ch6.getAngle(),
            SIP_ch7.getAngle()
    };
}

std::array<long, R8EF::num_channels> R8EF::getPercents() {
    return {
            SIP_ch1.map(-100, 100),
            SIP_ch2.map(-100, 100),
            SIP_ch3.map(-100, 100),
            SIP_ch4.map(-100, 100),
            SIP_ch5.map(-100, 100),
            SIP_ch6.map(-100, 100),
            SIP_ch7.map(-100, 100)
    };
}