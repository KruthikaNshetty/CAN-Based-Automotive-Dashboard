
#include "digital_keypad.h"
#include<xc.h>
void init_digital_keypad(void)
{
    TRISC=TRISC|0X0F;//initialize  trisb
    
}
unsigned char read_digital_keypad(unsigned char trigger)
{
    static int once=1;// variable used to detect key is pressed only once
    if(trigger==LEVEL)//check if the level trigger
    {
        return PORTC & 0X0F; 
    }
    else if(trigger==EDGE)//check if the level trigger
    {
        if(((PORTC & 0X0F)!= ALL_RELEASED)&&(once==1)) //If any key is pressed and not already detected
        {
            once=0;//marl key is pressed already
            return PORTC & 0X0F;
        }
        else if((PORTC & 0X0F)== ALL_RELEASED)
        {
            once=1;
        }
        return  ALL_RELEASED;//if no key  is pressed
    }
    
}


