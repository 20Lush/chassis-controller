#pragma once
#include <array>

#include <ServoInput.h>

struct EIGHT_CHANNEL {
    uint16_t ch1;
    uint16_t ch2;
    uint16_t ch3;
    uint16_t ch4;
    uint16_t ch5;
    uint16_t ch6;
    uint16_t ch7;
    uint16_t ch8;
};

struct R8EF {

    static constexpr int num_channels = 8;
    static constexpr std::array<uint8_t, num_channels> pin_array = { 2, 3, 4, 5, 6, 7, 8, 9 };

    void Init();

    EIGHT_CHANNEL getRaw();

    std::array<float, num_channels> getAngles();

    std::array<long, num_channels> getPercents();

    ServoInputPin<pin_array[0]> SIP_ch1;
    ServoInputPin<pin_array[1]> SIP_ch2;
    ServoInputPin<pin_array[2]> SIP_ch3;
    ServoInputPin<pin_array[3]> SIP_ch4;
    ServoInputPin<pin_array[4]> SIP_ch5;
    ServoInputPin<pin_array[5]> SIP_ch6;
    ServoInputPin<pin_array[6]> SIP_ch7;
    ServoInputPin<pin_array[7]> SIP_ch8;

};