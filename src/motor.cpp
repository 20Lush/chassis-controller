#include "motor.hpp"

Motor::Motor(uint8_t const& pin_assign) : m_pin(pin_assign), m_inverted(false) {};

Motor::Motor(Motor const& orig) : m_pin(orig.m_pin), m_inverted(orig.m_inverted) {};

Motor& Motor::operator=(uint8_t const& rhs) {

    this->m_pin = rhs;

    return *this;
}

Motor& Motor::operator=(Motor const& rhs) {
    this->m_pin = rhs.m_pin;
    this->m_inverted = rhs.m_inverted;
    return *this;
}

Motor::~Motor() {

    m_servo.detach();

}

void Motor::Init() {

    m_servo.attach(m_pin);

    m_servo.writeMicroseconds(1500);
    
}

uint16_t Motor::Get_uSec() {
    return m_curr_microseconds;
}

void Motor::Set_uSec(uint16_t microseconds) {

    if(m_inverted) {
        microseconds = 3000 - microseconds;
    }

    m_curr_microseconds = microseconds;

    m_servo.writeMicroseconds(m_curr_microseconds);

}