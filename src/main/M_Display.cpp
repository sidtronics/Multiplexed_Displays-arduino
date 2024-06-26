#include "M_Display.h"


M_Display::M_Display(const byte _stb, const byte _clk, const byte _data, struct MD_config* MD, byte (*_getFont) (char)) :
	  stb(_stb),
    clk(_clk),
    data(_data),
    TOTAL_DIGITS(MD->TOTAL_DIGITS),
    DISPLAY_RAM_SIZE(MD->DISPLAY_RAM_SIZE),
    LED_ADDR(MD->LED_ADDR),
    LED_VAL(MD->LED_VAL),
    buffer(MD->buffer),
    FONT(_getFont)

{
	pinMode(stb, OUTPUT);
	pinMode(clk, OUTPUT);
	pinMode(data, OUTPUT);

	digitalWrite(stb, HIGH);
	digitalWrite(clk, LOW);
}

void M_Display::sendCmd(byte cmd)
{
	delay(1);
	digitalWrite(clk, LOW);
	digitalWrite(stb, LOW);
	shiftOut(data, clk, LSBFIRST, cmd);
	delayMicroseconds(10);
	digitalWrite(stb, HIGH);
	delay(1);
}

void M_Display::sendData(byte addr, byte dat)
{
	sendCmd(0x44);  //Fixed Address
	digitalWrite(clk, LOW);
	digitalWrite(stb, LOW);
	shiftOut(data, clk, LSBFIRST, 0xC0 | addr);
	shiftOut(data, clk, LSBFIRST, dat);
	delayMicroseconds(10);
	digitalWrite(stb, HIGH);
	delay(1);
}

void M_Display::mode(byte mode)
{
	sendCmd(mode);
}

void M_Display::setDisplay(bool isOn, byte intensity)
{
	sendCmd(0x80 | (isOn ? 8 : 0) | min(7, intensity));
}

void M_Display::clear()
{
	for (int i = 0; i < DISPLAY_RAM_SIZE; i++)
		buffer[i] = 0x00;

	update();
}

void M_Display::update()
{
	sendCmd(0x40);  //Incremental Address
    digitalWrite(clk, LOW); 
	digitalWrite(stb, LOW);
	shiftOut(data, clk, LSBFIRST, 0xC0);

	for (int i = 0; i < DISPLAY_RAM_SIZE; i++)
		shiftOut(data, clk, LSBFIRST, buffer[i]);

	delayMicroseconds(10);
	digitalWrite(stb, HIGH);
	delay(1);
}

void M_Display::print(String str)
{
	if (str.length() > TOTAL_DIGITS)
	{
		scroll(str);
		return;
	}

	str.toUpperCase();

	while (str.length() != TOTAL_DIGITS)
		str = " " + str;

	sendString(str);
}

template <class T>
void M_Display::print(T value, byte baseORdecimalPlaces)
{
	String temp = String(value, baseORdecimalPlaces);
	print(temp);
}
template void M_Display::print<int8_t>(int8_t, byte);
template void M_Display::print<int16_t>(int16_t, byte);
template void M_Display::print<int32_t>(int32_t, byte);
template void M_Display::print<byte>(byte, byte);
template void M_Display::print<uint16_t>(uint16_t, byte);
template void M_Display::print<uint32_t>(uint32_t, byte);
template void M_Display::print<short>(short, byte);
template void M_Display::print<float>(float, byte);
template void M_Display::print<double>(double, byte);

void M_Display::error(int code)
{
	print("ERROR " + String(code));
}

void M_Display::error()
{
	print("ERROR");
}

void M_Display::scroll(String str, float lag, byte loop)
{
	str.toUpperCase();
	String str_temp = str;

	for (int i = 0; i < loop; i++)
	{
		str_temp = str;

		for (int i = 0; i < TOTAL_DIGITS; i++)
			str_temp = " " + str_temp + " ";

		while (str_temp.length() >= TOTAL_DIGITS)
		{
			sendString(str_temp);
			str_temp.remove(0, 1);
			delay(1000 * min(3.0, lag)); //Change maximum lag time here, By default it is 3 seconds.
		}
	}
}

void M_Display::toggleLed(byte led)
{
	buffer[LED_ADDR[led]] ^= LED_VAL[led];
	sendData(LED_ADDR[led], buffer[LED_ADDR[led]]);
}

void M_Display::setLed(bool isOn, byte led)
{
	if (isOn)
	{
		buffer[LED_ADDR[led]] |= LED_VAL[led];
		sendData(LED_ADDR[led], buffer[LED_ADDR[led]]);
	}
	else
	{
		buffer[LED_ADDR[led]] &= (0xFF - LED_VAL[led]);
		sendData(LED_ADDR[led], buffer[LED_ADDR[led]]);
	}
}
