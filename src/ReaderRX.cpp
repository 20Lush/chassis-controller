#include "ReaderRX.hpp"

#include <algorithm>

namespace lush::chassis_controller {

    std::array<int, ChannelsRX::num_channels> ChannelsRX::asArray() {
        return std::array<int, ChannelsRX::num_channels> {
            ch1, ch2, ch3, ch4, ch5, ch6, ch7
        };
    }

    ChannelsRX::ChannelsRX() :  ch1(2),
                                ch2(3),
                                ch3(4),
                                ch4(5),
                                ch5(6),
                                ch6(7),
                                ch7(8)
    {}

    ChannelsRX::ChannelsRX(int pin1, int pin2, int pin3, int pin4, int pin5, int pin6, int pin7)
        :   ch1(pin1),
            ch2(pin2),
            ch3(pin3),
            ch4(pin4),
            ch5(pin5),
            ch6(pin6),
            ch7(pin7)
    {}

    ChannelsRX::ChannelsRX(ChannelsRX const& orig) 
        :   ch1(orig.ch1),
            ch2(orig.ch2),
            ch3(orig.ch3),
            ch4(orig.ch4),
            ch5(orig.ch5),
            ch6(orig.ch6),
            ch7(orig.ch7)

    {}

    ChannelsRX& ChannelsRX::operator=(ChannelsRX const& rhs)
    {
        return *this;
    }

    ChannelsRX::~ChannelsRX() {}

    ReaderRX::ReaderRX() : ChannelsRX(), m_state(INIT) {
        std::fill(std::begin(m_raw_readings), std::end(m_raw_readings), 0);

        // thread blocking for timeout determined by m_wait_timeout
        bool received_signal = f_wait_for_first();

        if(!received_signal) {
            Serial.println("Failed to get first contact from RXer!");
            m_state = STOP;
        }

        m_state = IDLE;

    }

    ReaderRX::ReaderRX(int pin1, int pin2, int pin3, int pin4, int pin5, int pin6, int pin7)
        :   ChannelsRX(pin1, pin2, pin3, pin4, pin5, pin6, pin7) {

        std::fill(std::begin(m_raw_readings), std::end(m_raw_readings), 0);
        
        // thread blocking for timeout determined by m_wait_timeout
        bool received_signal = f_wait_for_first();

        if(!received_signal) {
            Serial.println("Failed to get first contact from RXer!");
            m_state = STOP;
        }

        m_state = IDLE;
    }

    ReaderRX::ReaderRX(ReaderRX const& orig) : ChannelsRX(orig), m_state(INIT) {
        std::fill(std::begin(m_raw_readings), std::end(m_raw_readings), 0);
        
        // thread blocking for timeout determined by m_wait_timeout
        bool received_signal = f_wait_for_first();

        if(!received_signal) {
            Serial.println("Failed to get first contact from RXer!");
            m_state = STOP;
        }

        m_state = IDLE;
    }

    ReaderRX& ReaderRX::operator=(ReaderRX const& rhs) {
        return *this;
    }

    ReaderRX::~ReaderRX() {}


}