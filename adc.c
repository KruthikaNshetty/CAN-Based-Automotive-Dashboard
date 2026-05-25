#include<xc.h>
#include "adc.h"

void init_adc(void)
{
    ADON=1;//TURN O ADC
    
    PCFG0=0;
    PCFG1=0;
    PCFG2=0;
    PCFG3=0;//SELECT ALL CHANNELS AS ANALOG
    
    VCFG0=0; //TO SELECT DEFAULT REFERENCE VOLTAGE
    VCFG1=0;
    
    ADCS0=0;
    ADCS1=1;
    ADCS2=0 ;//TO SELECT 1TAD=1.6 uS
    
   
     ACQT0=0;
     ACQT1=1;
     ACQT2=0; //TO SELECT 4TAD AS ACQUISITION TIME
    
     ADFM=1;//TO SELECT RIGHT JUSTIFICATION
}

unsigned int read_adc(unsigned char channel)
{
    ADCON0=(ADCON0&0XC3)|(channel<<2);
    GO=1;//CONVERSION STARTED
    
    while(GO);
    return (ADRESH<<8)|ADRESL;
    
        
    
}