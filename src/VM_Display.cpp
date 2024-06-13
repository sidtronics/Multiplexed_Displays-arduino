#include "VM_Display.h"

VM_Display::VM_Display(const byte _stb, const byte _clk, const byte _data, const VMD_config& _config, byte (*_getFont) (char)) :
	M_Display(_stb, _clk, _data, _config, _getFont),
	DIGIT_BITPOS(_config.DIGIT_BITPOS),
	SEG_ADDR(_config.SEG_ADDR) {}

void VM_Display::setSeg(bool isOn, byte seg, byte digit)
{
	if (isOn)
	{
		buffer[SEG_ADDR[digit][seg]] |= bit(DIGIT_BITPOS[digit]);
		sendData(SEG_ADDR[digit][seg], buffer[SEG_ADDR[digit][seg]]);
	}
	else
	{
		buffer[SEG_ADDR[digit][seg]] &= (0xFF - bit(DIGIT_BITPOS[digit]));
		sendData(SEG_ADDR[digit][seg], buffer[SEG_ADDR[digit][seg]]);
	}
}

void VM_Display::toggleSeg(byte seg, byte digit)
{
	buffer[SEG_ADDR[digit][seg]] ^= bit(DIGIT_BITPOS[digit]);
	sendData(SEG_ADDR[digit][seg], buffer[SEG_ADDR[digit][seg]]);
}

void VM_Display::sendString(String str)
{
	for(int i = 0; i < TOTAL_DIGITS; i++)
	{
		for(int j = 0; j < 7; j++)
			bitWrite(buffer[SEG_ADDR[i][j]], DIGIT_BITPOS[i], bitRead(FONT[str[i]], j));
	}
	update();
}

