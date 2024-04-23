#include <Servo.h>

class Motor {

    public:
        Motor(uint8_t const& pin_assign);

        Motor(Motor const& orig);

        Motor& operator=(uint8_t const& rhs);

        Motor& operator=(Motor const& rhs);

        ~Motor();

        void Init();

        uint16_t Get_uSec();

        void Set_uSec(uint16_t microseconds);

        void Set_Percent(float percent);

    private:

        Servo m_servo;

        uint8_t m_pin;

        uint16_t m_curr_microseconds;

        bool m_inverted;

};