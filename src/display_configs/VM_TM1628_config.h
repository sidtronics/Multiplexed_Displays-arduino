#ifndef TM1628_CONFIG_H
#define TM1628_CONFIG_H

/*Flags for indicating LEDs. Add more or modify
as per the display. But make sure you specify address 
and value of LED in LED_ADDR[] & LED_VAL[] respectively at
defined index. */
#define TM1628_D1 0
#define TM1628_D2 1
#define TM1628_D3 2
#define TM1628_D4 3
#define TM1628_D5 4
#define TM1628_D6 5
#define TM1628_USB 6
#define TM1628_PLY 7
#define TM1628_SD 8
#define TM1628_PAU 9
#define TM1628_U1 10
#define TM1628_L1 11
#define TM1628_CL1 12
#define TM1628_CL2 13
#define TM1628_MP3 14
#define TM1628_FM 15
#define TM1628_MHZ 16
#define TM1628_DD 17

/*
			 ----SEG1----
	    |           |
SEG6  |           |  SEG2
			|----SEG7---|
SEG5  |           |  SEG3
			|           |
			 ----SEG4----     • SEG8

Flags for indicating individual segments of digit as shown above.  */

#define TM1628_SEG1 0
#define TM1628_SEG2 1
#define TM1628_SEG3 2
#define TM1628_SEG4 3
#define TM1628_SEG5 4
#define TM1628_SEG6 5
#define TM1628_SEG7 6
#define TM1628_SEG8 7

const byte TM1628_TOTAL_DIGITS = 6;

const byte TM1628_DISPLAY_RAM_SIZE = 14;

//                               D1    D2    D3    D4    D5    D6   USB   PLY    SD   PAU    U1    L1    CL1   CL2   MP3   FM    MHz   DD
const byte TM1628_LED_ADDR[] = {0x0A, 0x02, 0x04, 0x08, 0x06, 0x0C, 0x00, 0x00, 0x06, 0x06, 0x0A, 0x04, 0x08, 0x08, 0x02, 0x0A, 0x04, 0x02};
const byte TM1628_LED_VAL[]  = {0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x10, 0x08, 0x10, 0x08, 0x10, 0x10, 0x10, 0x08, 0x08, 0x08, 0x08, 0x10};

byte TM1628_buffer[TM1628_DISPLAY_RAM_SIZE];

const byte TM1628_DIGIT_BITPOS[TM1628_TOTAL_DIGITS] = {
1, //bit position for 1st digit from left. 0 = LSB and 7 = MSB.
0,
7,
0,
1,
2
};

//                                   SEG1  SEG2  SEG3  SEG4  SEG5  SEG6  SEG7  SEG8
const byte TM1628_SEG_ADDR_SET1[] = {0x01, 0x03, 0x05, 0x07, 0x09, 0x0B, 0x0D};
const byte TM1628_SEG_ADDR_SET2[] = {0x00, 0x02, 0x04, 0x06, 0x08, 0x0A, 0x0C};

const byte* TM1628_SEG_ADDR[TM1628_TOTAL_DIGITS] = {
    TM1628_SEG_ADDR_SET1,   // Segment Addresses for First digit from left.
    TM1628_SEG_ADDR_SET1,
    TM1628_SEG_ADDR_SET2,
    TM1628_SEG_ADDR_SET2,
    TM1628_SEG_ADDR_SET2,
    TM1628_SEG_ADDR_SET2   // Segment Addresses for Last digit from left.
};
	

struct VMD_config TM1628_config(TM1628_TOTAL_DIGITS, TM1628_DISPLAY_RAM_SIZE, TM1628_LED_ADDR, TM1628_LED_VAL, TM1628_buffer, TM1628_DIGIT_BITPOS, TM1628_SEG_ADDR);

#endif