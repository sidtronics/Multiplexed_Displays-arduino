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
#include "MD_config.h"
#include "MD_settings.h"

//flags for turn on/off
#define ON true
#define OFF false

class M_Display
{
  public:
		
	void mode(byte mode);
	void setDisplay(bool isOn, byte intensity = 7);
	void clear();
	void print(String str);
	template <class T> void print(T value, byte baseORdecimalPlaces);
	void error(int code);
	void error();
	void scroll(String str, float lag = 0.5, byte loop = 1);
	void toggleLed(byte led);
	void setLed(bool isOn, byte led);
	virtual void toggleSeg(byte seg, byte digit) = 0;
	virtual void setSeg(bool isOn, byte seg, byte digit) = 0;

  protected:

	M_Display(

            const byte _stb,
            const byte _clk,
            const byte _data,
            const HMD_config& _config,
            byte (*_getFont) (char)
    );

    M_Display(

            const byte _stb,
            const byte _clk,
            const byte _data,
            const VMD_config& _config,
            byte (*_getFont) (char)
    );

	void sendCmd(byte cmd);
	void sendData(byte addr, byte dat);
	virtual void sendString(String str) = 0;
	void update();

    byte buffer[MD_DISPLAY_RAM_SIZE];

	const byte TOTAL_DIGITS;
	const byte* const& LED_ADDR;
	const byte* const& LED_VAL;

    const DisplayFont FONT;

	const byte stb;
	const byte clk;
	const byte data;	
};

#endif
