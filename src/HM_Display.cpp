#include "HM_Display.h"

HM_Display::HM_Display(const byte _stb,const byte _clk,const byte _data, struct HMD_config& HMD, byte (*_getFont) (char)) :
	M_Display(_stb, _clk, _data, &HMD, _getFont), 
	DIGIT_ADDR(HMD.DIGIT_ADDR) {}

void HM_Display::setSeg(bool isOn, byte seg, byte digit)
{
	if (isOn)
	{
		buffer[DIGIT_ADDR[digit]] |= bit(seg);
		sendData(DIGIT_ADDR[digit], buffer[DIGIT_ADDR[digit]]);
	}
	else
	{
		buffer[DIGIT_ADDR[digit]] &= (0xFF - bit(seg));
		sendData(DIGIT_ADDR[digit], buffer[DIGIT_ADDR[digit]]);
	}
}

void HM_Display::toggleSeg(byte seg, byte digit)
{
	buffer[DIGIT_ADDR[digit]] ^= bit(seg);
	sendData(DIGIT_ADDR[digit], buffer[DIGIT_ADDR[digit]]);
}

void HM_Display::sendString(String str)
{
	for(int i = 0; i < TOTAL_DIGITS; i++)
	{
		for(int j = 0; j < 7; j++)
			bitWrite(buffer[DIGIT_ADDR[i]], j, bitRead(FONT[str[i]], j));
	}
	update();
}
