#ifndef MODULE_NAME_CONFIG_H
#define MODULE_NAME_CONFIG_H

//Use Find & Replace to Replace MODULE_NAME to whatever you want.

/*
			 ----SEG1----
	     	|           |
      SEG6  |           |  SEG2
			|----SEG7---|
      SEG5  |           |  SEG3
			|           |
			 ----SEG4----     • SEG8

Flags for indicating individual segments of digit as shown above.  */

#define MODULE_NAME_SEG1 0
#define MODULE_NAME_SEG2 1
#define MODULE_NAME_SEG3 2
#define MODULE_NAME_SEG4 3
#define MODULE_NAME_SEG5 4
#define MODULE_NAME_SEG6 5
#define MODULE_NAME_SEG7 6
#define MODULE_NAME_SEG8 7

/*Note:- If you have turned On the SEG8, 
You need to either turn it off manually 
using .setSeg() or clear the display using .clear() . 
It won't be overwritten by .print() or .scroll() .*/


/*Flags for indicating LEDs. Add more or modify
as per the display. But make sure you specify address 
and value of LED in LED_ADDR[] & LED_VAL[] respectively at
defined index. */
#define MODULE_NAME_LED1 0
#define MODULE_NAME_LED2 1
#define MODULE_NAME_LED3 2
#define MODULE_NAME_LED4 3

const byte MODULE_NAME_TOTAL_DIGITS = <total 7 segment digits>;
const byte MODULE_NAME_DISPLAY_RAM_SIZE = <total number of bytes in display ram>;

const byte MODULE_NAME_LED_ADDR[] = {<array of display ram addresses of leds/special segments of display>};
const byte MODULE_NAME_LED_VAL[]  = {<array of display ram values of leds/special segments of display>};

byte MODULE_NAME_buffer[MODULE_NAME_DISPLAY_RAM_SIZE];

const byte MODULE_NAME_DIGIT_ADDR[MODULE_NAME_TOTAL_DIGITS] = {
<array of display ram addresses for 7 segment digits>
};

struct HMD_config MODULE_NAME_config(MODULE_NAME_TOTAL_DIGITS, MODULE_NAME_DISPLAY_RAM_SIZE, MODULE_NAME_LED_ADDR, MODULE_NAME_LED_VAL, MODULE_NAME_buffer, MODULE_NAME_DIGIT_ADDR);

#endif