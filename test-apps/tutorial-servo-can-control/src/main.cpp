#include "mbed.h"
#include "CANMsg.h"
#include "TutorialServo.h"
#include <thread>
#include <chrono>

using namespace std::chrono_literals;

int main() {
    // set up the servo
    TutorialServo servo(PB_3, 180, 0.5, 2.5);
    
    // percentage of range of motion of servo as float
    float servo_rom_pct = 0;

    auto pct_to_deg = [] (TutorialServo servo, float rom_pct) {
        return servo.getRangeInDeg() * rom_pct;
    };

    // setup the CAN bus
    CAN servo_can_receiver(PB_8, PB_9);
    CANMsg servo_rx;

    servo_rx.setPayload(servo_rom_pct, sizeof(float));

    while (true) {
        // use the can bus to read in signals
        servo_can_receiver.read(servo_rx);
        servo_rx.getPayload(servo_rom_pct);

        // set to the new position
        servo.setPositionDeg(pct_to_deg(servo, servo_rom_pct));
        
    }
}