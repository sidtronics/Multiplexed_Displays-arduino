#ifndef MODULE_NAME_CONFIG_H
#define MODULE_NAME_CONFIG_H

/*Flags for indicating LEDs. Add more or modify
as per the display. But make sure you specify address 
and value of LED in LED_ADDR[] & LED_VAL[] respectively at
defined index. */
#define MODULE_NAME_DISC1 0
#define MODULE_NAME_DISC2 1
#define MODULE_NAME_DISC3 2
#define MODULE_NAME_DISC4 3
#define MODULE_NAME_DISC5 4
#define MODULE_NAME_DISC6 5
#define MODULE_NAME_USB 6
#define MODULE_NAME_PLY 7
#define MODULE_NAME_SD 8
#define MODULE_NAME_PAU 9
#define MODULE_NAME_U1 10
#define MODULE_NAME_L1 11
#define MODULE_NAME_CL1 12
#define MODULE_NAME_CL2 13
#define MODULE_NAME_MP3 14
#define MODULE_NAME_FM 15
#define MODULE_NAME_MHZ 16
#define MODULE_NAME_DD 17


/*
		    	 ----SEG1----
	    		|           |
          SEG6  |           |  SEG2
	    		|----SEG7---|
          SEG5  |           |  SEG3
         		|           |
                 ----SEG4----    • SEG8

Flags for indicating individual segments of digit as shown above.  */

#define MODULE_NAME_SEG1 0
#define MODULE_NAME_SEG2 1
#define MODULE_NAME_SEG3 2
#define MODULE_NAME_SEG4 3
#define MODULE_NAME_SEG5 4
#define MODULE_NAME_SEG6 5
#define MODULE_NAME_SEG7 6
#define MODULE_NAME_SEG8 7

const byte MODULE_NAME_TOTAL_DIGITS = <total 7 segment digits>;

const byte MODULE_NAME_DISPLAY_RAM_SIZE = <total number of bytes in display ram>;


const byte MODULE_NAME_LED_ADDR[] = {<array of display ram addresses of leds/special segments of display>};
const byte MODULE_NAME_LED_VAL[]  = {<array of display ram values of leds/special segments of display>};


byte MODULE_NAME_buffer[MODULE_NAME_DISPLAY_RAM_SIZE];

const byte MODULE_NAME_DIGIT_BITPOS[MODULE_NAME_TOTAL_DIGITS] = {
<array of bit position in a byte for 7-segment digits. 1st element is bit position of 1st digit from left of display.>
<0 = LSB, 7 = MSB>
};


const byte MODULE_NAME_SEG_ADDR_SET1[] = {<array of segment address for a group of digits>};
const byte MODULE_NAME_SEG_ADDR_SET2[] = {<array of segment address for different group of digits>};
//add more sets if your display has some more groups of digits. Remove SEG_ADDR_SET2 if your display has just 1 set.


//modify the order of address sets in following pointer array according to order of digits starting from leftmost digit on display.

const byte* MODULE_NAME_SEG_ADDR[MODULE_NAME_TOTAL_DIGITS] = {
    MODULE_NAME_SEG_ADDR_SET1,   // Segment Addresses for First digit from left.
    MODULE_NAME_SEG_ADDR_SET1,
    MODULE_NAME_SEG_ADDR_SET2,
    MODULE_NAME_SEG_ADDR_SET2,
    MODULE_NAME_SEG_ADDR_SET2,
    MODULE_NAME_SEG_ADDR_SET2   // Segment Addresses for Last digit from left.
};
	

struct VMD_config MODULE_NAME_config(MODULE_NAME_TOTAL_DIGITS, MODULE_NAME_DISPLAY_RAM_SIZE, MODULE_NAME_LED_ADDR, MODULE_NAME_LED_VAL, MODULE_NAME_buffer, MODULE_NAME_DIGIT_BITPOS, MODULE_NAME_SEG_ADDR);

#endif