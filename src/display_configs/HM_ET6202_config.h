#ifndef ET6202_CONFIG_H
#define ET6202_CONFIG_H

/*
			 ----SEG1----
	     	|           |
      SEG6  |           |  SEG2
			|----SEG7---|
      SEG5  |           |  SEG3
			|           |
			 ----SEG4----     • SEG8

Flags for indicating individual segments of digit as shown above.  */

#define ET6202_SEG1 0
#define ET6202_SEG2 1
#define ET6202_SEG3 2
#define ET6202_SEG4 3
#define ET6202_SEG5 4
#define ET6202_SEG6 5
#define ET6202_SEG7 6
#define ET6202_SEG8 7

/*Note:- If you have turned On the SEG8, 
You need to either turn it off manually 
using .setSeg() or clear the display using .clear() . 
It won't be overwritten by .print() or .scroll() .*/


/*Flags for indicating LEDs. Add more or modify
as per the display. But make sure you specify address 
and value of LED in LED_ADDR[] & LED_VAL[] respectively at
defined index. */

#define ET6202_COLON 0
#define ET6202_LED 1

const byte ET6202_TOTAL_DIGITS = 4;
const byte ET6202_DISPLAY_RAM_SIZE = 14;

//                              COLON  LED
const byte ET6202_LED_ADDR[] = {0x04, 0x01};
const byte ET6202_LED_VAL[]  = {0x80, 0x08};

byte ET6202_buffer[ET6202_DISPLAY_RAM_SIZE];

const byte ET6202_DIGIT_ADDR[ET6202_TOTAL_DIGITS] = {
	0x06, //1st Digit from left
	0x04, //2nd Digit from left
	0x02, //3rd Digit from left
	0x00  //4th Digit from left
};

struct HMD_config ET6202_config(ET6202_TOTAL_DIGITS, ET6202_DISPLAY_RAM_SIZE, ET6202_LED_ADDR, ET6202_LED_VAL, ET6202_buffer, ET6202_DIGIT_ADDR);

#endif