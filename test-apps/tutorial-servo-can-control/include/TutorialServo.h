#ifndef TUTORIAL_SERVO_H
#define TUTORIAL_SERVO_H

#include "mbed.h"

class TutorialServo {

public:
    // constructor to take pin and servo config info
    TutorialServo(PinName servo_pin, float servo_range_deg = 180.0, float min_pw_ms = 1.0, float max_pw_ms = 2.0);

    // setter method to set servo to a specific degree value
    void setPositionDeg(const float deg);
    
    // getter methods
    float getRangeInDeg() const;
    float getMinPwMs() const;
    float getMaxPwMs() const;

private:
    PwmOut m_servo_pwm_out;
    const float m_servo_range_deg;
    const float m_min_pulse_width_ms;
    const float m_max_pulse_width_ms;

};

#endif