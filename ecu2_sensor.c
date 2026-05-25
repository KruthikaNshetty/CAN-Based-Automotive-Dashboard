#include "ecu2_sensor.h"
#include "adc.h"
#include "can.h"
#include "msg_id.h"
//#include "matrix_keypad.h"
  #include "digital_keypad.h"

uint16_t get_rpm()
{
    unsigned int rpm;
    rpm=(read_adc(CHANNEL4)/10.23)*60;
    return rpm;
  
}
IndicatorStatus process_indicator()
{
    
    static unsigned char flag=4;
     //unsigned char key=read_switches(EDGE);
    unsigned char key=read_digital_keypad(EDGE);
     if(key==SW1)
         {
            flag=1; 
         } 
         else if(key==SW2)
         {
             flag=2;  
         }
          else if(key==SW3)
         {
             flag=3;  
         }
          else if(key==SW4)
         {
             flag=4;  
         }
     if(flag==1)
         return e_ind_left ;
    else if(flag == 2)
        return e_ind_haz;
    else if(flag == 3)
        return e_ind_right;
    else if(flag == 4)
        return e_ind_off;
}
