#include <xc.h>
#include <string.h>
#include "message_handlers.h"
#include "msg_id.h"
#include "can.h"
#include "clcd.h"


volatile unsigned char led_state = LED_OFF, status = e_ind_off;
unsigned char gear[8][3] = {"N","1","2","3","4","5","R","_c"};
void handle_speed_data(uint8_t *data, uint8_t len)
{
    //Implement the speed function
    clcd_print("SP:",LINE1(0));
    clcd_putch((*data / 100) + '0',LINE1(4));
    clcd_putch((*data / 10) % 10 + '0',LINE1(5));
    clcd_putch((*data %10 ) + '0',LINE1(6));
}

void handle_gear_data(uint8_t *data, uint8_t len) 
{
    //Implement the gear function
    
    clcd_print("GEAR:",LINE1(8));
    clcd_print("  ",LINE1(14));
    clcd_print(gear[*data],LINE1(14));
}

void handle_rpm_data(uint16_t *data, uint8_t len) 
{
    //Implement the rpm function
     clcd_print("RPM:", LINE2(0));
    clcd_putch((*data / 1000) + '0', LINE2(4));
    clcd_putch((*data / 100) % 10 + '0', LINE2(5));
    clcd_putch((*data / 10) % 10 + '0', LINE2(6));
    clcd_putch((*data % 10) + '0', LINE2(7));
}


void handle_indicator_data(uint8_t *data, uint8_t len) 
{
    //Implement the indicator function
    
    clcd_print("Ind:", LINE2(9));
    
    if (*data == e_ind_left) {
        status = e_ind_left;
        if(led_state)
        clcd_print("<-  ", LINE2(13));
        else
          clcd_print("   ", LINE2(13));   
    } 
    else if (*data == e_ind_haz) {
        status = e_ind_haz;
         if(led_state)
        clcd_print("<-->", LINE2(13));
        else
          clcd_print("   ", LINE2(13)); 
        
    } 
    else if (*data == e_ind_right)
    {
        status = e_ind_right;
         if(led_state)
        clcd_print("->  ", LINE2(13));
         else
              clcd_print("   ", LINE2(13)); 
    } 
    else if (*data == e_ind_off) {
        status = e_ind_off;
             clcd_print("OFF", LINE2(13));
         
        
    }
}

void process_canbus_data() 
{   
    //process the CAN bus data
    
    unsigned int  msg_id, data;
     unsigned char len;
    can_receive(&msg_id, &data, &len);
    
    if(msg_id == SPEED_MSG_ID)
    {
        handle_speed_data(&data, len);
    }
    else if(msg_id == GEAR_MSG_ID)
    {
        handle_gear_data(&data, len);
    }
    else if(msg_id == RPM_MSG_ID)
    {
        handle_rpm_data(&data, len);
    }
    else if(msg_id == INDICATOR_MSG_ID)
    {
        handle_indicator_data(&data, len);
    }
}