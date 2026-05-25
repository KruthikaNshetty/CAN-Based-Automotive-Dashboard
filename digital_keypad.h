/* 
 * File:   digital_keypad.h
 * Author: kruthika
 *
 * Created on 24 March, 2026, 2:29 PM
 */
#ifndef DIGITAL_KEYPAD_H
#define	DIGITAL_KEYPAD_H

void init_digital_keypad(void);
unsigned char read_digital_keypad(unsigned char trigger);

//switch macros
#define SW1 0x0E
#define SW2 0x0D
#define SW3 0x0B
#define SW4 0x07
 
#define LEVEL 1
#define EDGE  0
#define ALL_RELEASED 0X0F

#endif	/* DIGITAL_KEYPAD_H */






