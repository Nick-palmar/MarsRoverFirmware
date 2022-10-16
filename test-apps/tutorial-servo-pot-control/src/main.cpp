#include "mbed.h"
#include <chrono>
#include <thread>

// define pins
AnalogIn pot_voltage_in(PA_0);
PwmOut servo_pwm_out(PB_3);

const float MAX_VOLT_IN = 3.3;
const float MIN_PWM_MS = 1.0;

using namespace std::chrono_literals;

int main() {
    // set servo pwm to 50 hz (20ms)
    servo_pwm_out.period_ms(20);

    while (1) {
        // input from 0V to 3.3V
        // float pot_voltage = pot_voltage_in.read();
        // map duty cycle range to pulsewidth of 1ms to 2ms (as a recommened standard)
        // servo_pwm_out.pulsewidth((MIN_PWM_MS + pot_voltage/MAX_VOLT_IN) / 1000.0);


        servo_pwm_out.pulsewidth(0.5 / 1000);
        ThisThread::sleep_for(1000ms);
        servo_pwm_out.pulsewidth(1.0 / 1000);
        ThisThread::sleep_for(1000ms);
        servo_pwm_out.pulsewidth(1.5 / 1000);
        ThisThread::sleep_for(1000ms);
        servo_pwm_out.pulsewidth(2.0 / 1000);
        ThisThread::sleep_for(1000ms);
        servo_pwm_out.pulsewidth(2.5 / 1000);
        ThisThread::sleep_for(1000ms);

        // for (int i = 0.5; i <=2.5; i+=0.5) {
        //     servo_pwm_out.pulsewidth_ms(i);
        //     std::ThisThread.sleep_for(1000ms);
        // }
    }
}