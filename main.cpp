#include "mbed.h"
#include "Sequence.hpp"

DigitalOut melt_rover(p20);

int main() {
    while(1) {
        melt_rover = 1;
        setSeequence(1);
        wait(1.0);
        
        melt_rover = 0;
        setSeequence(2);
        wait(1.0);
    }
}