#include "HM_Display.h"

HM_Display::HM_Display(const byte _stb,const byte _clk,const byte _data, const HMD_config& _config, byte (*_getFont) (char)) :
	M_Display(_stb, _clk, _data, _config, _getFont),
	DIGIT_ADDR(_config.DIGIT_ADDR) {}

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

void HM_Display::writeDigit(byte digit, byte data) {

    buffer[DIGIT_ADDR[digit]] = (buffer[DIGIT_ADDR[digit]] & 0x80) | FONT[data];
}

/*
void HM_Display::sendString(String str)
{
	for(int i = 0; i < TOTAL_DIGITS; i++)
	{
		for(int j = 0; j < 7; j++)
			bitWrite(buffer[DIGIT_ADDR[i]], j, bitRead(FONT[str[i]], j));
	}
	update();
}

size_t HM_Display::write(byte chr) {

    if(cursor_pos == TOTAL_DIGITS) clear();

    for(int j = 0; j < 7; j++) bitWrite(buffer[DIGIT_ADDR[cursor_pos]], j, bitRead(FONT[chr], j));
    cursor_pos++;
    update();

    return 1;
}

size_t HM_Display::write(const byte *buf, size_t size) {

    if(cursor_pos == TOTAL_DIGITS) clear();

    size_t n = 0;
    while(size--) {

        buffer[DIGIT_ADDR[cursor_pos]] = FONT[*buf++];
        cursor_pos++;
        n++;

        if(cursor_pos == TOTAL_DIGITS) {

            update();
            return n;
        }
    }

    update();
    return n;
}
*/
