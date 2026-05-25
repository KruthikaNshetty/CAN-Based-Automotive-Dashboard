
#include<xc.h>
#include "message_handlers.h"

void __interrupt() isr(void)
{
    static unsigned int count = 0;
    if(TMR0IF == 1)
    {
        TMR0 = TMR0 + 8;
        if(count++ == 20000)
        {
            count = 0;
            led_state = !led_state;
        }

        if(status == e_ind_left)
        {
            RIGHT_IND_OFF();
            if(led_state)
                LEFT_IND_ON();
            else
                LEFT_IND_OFF();
        }
        else if(status == e_ind_right)
        {
             LEFT_IND_OFF();
            if(led_state)
                RIGHT_IND_ON();
            else
                RIGHT_IND_OFF();
        }
        else if(status == e_ind_haz)
        {
            if(led_state){
                RIGHT_IND_ON();
                LEFT_IND_ON();
            }
            else{
                RIGHT_IND_OFF();
                LEFT_IND_OFF();
            }
        }
        else
        {
            RIGHT_IND_OFF();
            LEFT_IND_OFF();
        }


        TMR0IF = 0;
    }
}

