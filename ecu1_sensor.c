//#include "matrix_keypad.h"
#include "adc.h"
#include "ecu1_sensor.h"
#include "can.h"
#include "msg_id.h"
 #include "digital_keypad.h"


uint16_t get_speed()
{
    unsigned char speed;
    speed=(read_adc(CHANNEL4))/10.23;
    return speed;
}
unsigned char get_gear_pos()
{
    static unsigned char flag=0,i=0;
    //unsigned char key = read_switches(EDGE);
    unsigned char key = read_digital_keypad(EDGE);
       if(key == SW1)
        {
            if(flag == 1)
            {
                i = 0;
                flag = 0;
            }
            else
            {
                if(i < 6)
                    i++;
            }
        }
        else if(key == SW2)
        {
            if(flag == 1)
            {
                i = 0;
                flag = 0;
            }
            else
            {
                if(i > 0)
                    i--;
            } 
        }
        else if(key == SW3)
        {
            flag = 1;
            i = 7;
        }
        return i; 
    
}
