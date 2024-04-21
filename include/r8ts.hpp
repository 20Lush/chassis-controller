#pragma once
#include <array>

#include <ServoInput.h>

struct R8TS {

    static constexpr int num_channels = 7;
    static constexpr std::array<uint8_t, num_channels> pin_array = { 2, 3, 4, 5, 6, 7, 8 };

    void Init();

    std::array<int, num_channels> getRaw();

    std::array<int, num_channels> getAngles();

    std::array<int, num_channels> getPercents();

    ServoInputPin<pin_array[0]> ch1;
    ServoInputPin<pin_array[1]> ch2;
    ServoInputPin<pin_array[2]> ch3;
    ServoInputPin<pin_array[3]> ch4;
    ServoInputPin<pin_array[4]> ch5;
    ServoInputPin<pin_array[5]> ch6;
    ServoInputPin<pin_array[6]> ch7;

};