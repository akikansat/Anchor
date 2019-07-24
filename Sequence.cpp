#include "Sequence.hpp"

DigitalOut l1(LED1);
DigitalOut l2(LED2);
DigitalOut l3(LED3);
DigitalOut l4(LED4);

void setSeequence(int num)
{
    
    switch (num)
    {
        case 1:
            l1 = 1;
            l2 = 0;
            l3 = 0;
            l4 = 0;
            break;
        case 2:
            l1 = 0;
            l2 = 1;
            l3 = 0;
            l4 = 0;
            break;
        case 3:
            l1 = 0;
            l2 = 0;
            l3 = 1;
            l4 = 0;
            break;
        case 4:
            l1 = 0;
            l2 = 0;
            l3 = 0;
            l4 = 1;
            break;
        default:
            l1 = 1;
            l2 = 1;
            l3 = 1;
            l4 = 1;
            break;
    }
}
