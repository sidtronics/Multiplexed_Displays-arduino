#ifndef M_DISPLAY_H
#define M_DISPLAY_H
//M_Display.h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "Arduino.h"
#else
	#include "WProgram.h"
#endif


//#include "MD_Fonts.h"
#include "../DisplayFont.h"
#include "../fonts/Fonts.h"
#include "MD_config_structs.h"
#define MD_STRING_BUFFER_SIZE 26
//flags for turn on/off
#define ON true
#define OFF false

#define LEFT true
#define RIGHT false

class M_Display : public Print
{
  public:
		
	void mode(byte mode);
	void setDisplay(bool isOn, byte intensity = 7);
	void clear();
    /*
	void print(String str);
	template <class T> void print(T value, byte baseORdecimalPlaces);
	void error(int code);
	void error();
	void scroll(String str, float lag = 0.5, byte loop = 1);
    */
	void toggleLed(byte led);
	void setLed(bool isOn, byte led);
	virtual void toggleSeg(byte seg, byte digit) = 0;
	virtual void setSeg(bool isOn, byte seg, byte digit) = 0;
    void scroll(bool dir, byte len = 1);

  protected:

	M_Display(const byte _stb, const byte _clk, const byte _data, struct MD_config* MD, byte (*_getFont) (char));

	void sendCmd(byte cmd);
	void sendData(byte addr, byte dat);
	//virtual void sendString(String str) = 0;
    size_t write(byte chr) override;
    size_t write(const byte *buf, size_t size) override;
    void updateFrame();
	void update();

    virtual void writeDigit(byte digit, byte data) = 0;

	const byte& TOTAL_DIGITS;
	const byte& DISPLAY_RAM_SIZE;
	const byte*& LED_ADDR;
	const byte*& LED_VAL;

	byte*& buffer;
    byte str_buffer[MD_STRING_BUFFER_SIZE] = {0};
    byte cursor_pos = 0;
    byte frame_beg = 0;

    const DisplayFont FONT;

	const byte stb;
	const byte clk;
	const byte data;	
};

#endif
