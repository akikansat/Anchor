/**
 * @file main.cpp
 * @brief モータPWM駆動用テストコード
 * @details 
 * @author M.Kato
 * @date 2019.7.23
 * @version 1.0
 * @note 
 */

#include "mbed.h"
#include "motordriver.h"
#include "Sequence.hpp"
#include "motordriver.h"

Motor motor1(p21, p24, p25, 0); // pwm, fwd, rev, can brake 
Motor motor2(p22, p29, p30, 0); // pwm, fwd, rev, can brake
 
int main() {    
    while(1){
        motor1.speed(0.5); 
        motor2.speed(0.5);
        setSeequence(1);
        wait(2);
        
        motor1.stop(0); 
        motor2.stop(0); 
        setSeequence(2);
        wait(2);

        motor1.speed(-0.5); 
        motor2.speed(-0.5);
        setSeequence(3);
        wait(2);

        motor1.stop(0); 
        motor2.stop(0);
        setSeequence(4);
        wait(2);
    }
}
