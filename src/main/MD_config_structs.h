#ifndef MD_CONFIG_STRUCTS_H
#define MD_CONFIG_STRUCTS_H

struct MD_config {

protected:

	MD_config(const byte& _TOTAL_DIGITS, const byte& _DISPLAY_RAM_SIZE, const byte* _LED_ADDR, const byte* _LED_VAL, byte* _buffer) :
	TOTAL_DIGITS(_TOTAL_DIGITS),
	DISPLAY_RAM_SIZE(_DISPLAY_RAM_SIZE),
	LED_ADDR(_LED_ADDR),
	LED_VAL(_LED_VAL),
	buffer(_buffer) {};

public:

    const byte& TOTAL_DIGITS;
	const byte& DISPLAY_RAM_SIZE;
    const byte* LED_ADDR;
    const byte* LED_VAL;
	 
	byte* buffer;
};

struct HMD_config : public MD_config {
	HMD_config(const byte& _TOTAL_DIGITS, const byte& _DISPLAY_RAM_SIZE, const byte* _LED_ADDR, const byte* _LED_VAL, byte* _buffer, const byte* _DIGIT_ADDR) :
	MD_config(_TOTAL_DIGITS, _DISPLAY_RAM_SIZE, _LED_ADDR, _LED_VAL, _buffer),
	DIGIT_ADDR(_DIGIT_ADDR) {};

    const byte* DIGIT_ADDR;  
};

struct VMD_config : public MD_config {
	VMD_config(const byte& _TOTAL_DIGITS, const byte& _DISPLAY_RAM_SIZE, const byte* _LED_ADDR, const byte* _LED_VAL, byte* _buffer, const byte* _DIGIT_BITPOS, const byte** _SEG_ADDR) :
	MD_config(_TOTAL_DIGITS, _DISPLAY_RAM_SIZE, _LED_ADDR, _LED_VAL, _buffer), 
	DIGIT_BITPOS(_DIGIT_BITPOS),
	SEG_ADDR(_SEG_ADDR) {};

    const byte* DIGIT_BITPOS;
    const byte** SEG_ADDR;
};

#endif