#pragma once
#include <array>

#include <ServoInput.h>

namespace lush::chassis_controller {

    enum RX_STATES {
        INIT,
        IDLE,
        READ,
        STOP
    };

    struct ChannelsRX {
        // 9 = LB roller
        // 8 = LT 3 pos switch
        // 7 = RB button
        // 6 = RT 3 pos switch
        // 5 = left stick X
        // 4 = left stick Y
        // 3 = right stick Y
        // 2 = right stick X
        const int ch1, ch2, ch3, ch4, ch5, ch6, ch7;
        static const int num_channels = 7;

        std::array<int, num_channels> asArray();

        ChannelsRX();

        ChannelsRX(int pin1, int pin2, int pin3, int pin4, int pin5, int pin6, int pin7);

        ChannelsRX(ChannelsRX const& orig);

        ChannelsRX& operator=(ChannelsRX const& rhs);

        ~ChannelsRX();

    };

    class ReaderRX : ChannelsRX {

        public:

            ReaderRX();

            ReaderRX(int pin1, int pin2, int pin3, int pin4, int pin5, int pin6, int pin7);

            ReaderRX(ReaderRX const& orig);

            ReaderRX& operator=(ReaderRX const& rhs);

            ~ReaderRX();

            void Update();

            std::array<int, num_channels> GetReadingsRaw();

            std::array<int, num_channels> GetReadingsPercent();

            std::array<int, num_channels> GetReadingsAngle();

        private:

            RX_STATES m_state;

            std::array<int, num_channels> m_raw_readings;

            /** @brief 60s timeout to recieve first contact before ReaderRX complains
             * 
            */
            const int m_wait_timeout = 60000;

            bool f_wait_for_first();

        protected:
            ServoInputPin<ch1> m_input_1;
            ServoInputPin<ch2> m_input_2;
            ServoInputPin<ch3> m_input_3;
            ServoInputPin<ch4> m_input_4;
            ServoInputPin<ch5> m_input_5;
            ServoInputPin<ch6> m_input_6;
            ServoInputPin<ch7> m_input_7;

    };


}