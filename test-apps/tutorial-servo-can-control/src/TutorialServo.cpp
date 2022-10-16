#include "TutorialServo.h"
#include "mbed.h"

TutorialServo::TutorialServo(PinName servo_pin, float servo_range_deg, float min_pw_ms, float max_pw_ms): 
    m_servo_pwm_out(servo_pin), m_servo_range_deg(servo_range_deg), m_min_pulse_width_ms(min_pw_ms), m_max_pulse_width_ms(max_pw_ms) {}

float TutorialServo::getRangeInDeg() const {
    return m_servo_range_deg;
}

float TutorialServo::getMinPwMs() const {
    return m_min_pulse_width_ms;
}

float TutorialServo::getMaxPwMs() const {
    return m_max_pulse_width_ms;
}

void TutorialServo::setPositionDeg(const float deg) {
    if (deg < 0 || deg > m_servo_range_deg) {
        return;
    } else {
        float position_proportion = deg/m_servo_range_deg;
        float delta_pw = m_max_pulse_width_ms - m_min_pulse_width_ms;
        // gives you a value in the pw ms domain of how much the increment from the minimum should be
        float pw_ms_proportion = delta_pw * position_proportion;
        // set the servo to this pwm reading
        m_servo_pwm_out.pulsewidth((m_min_pulse_width_ms + pw_ms_proportion) / 1000.0);
    }
}