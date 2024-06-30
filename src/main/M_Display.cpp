#include "M_Display.h"


M_Display::M_Display( 

    const byte _stb,
    const byte _clk,
    const byte _data,
    const HMD_config& _config,
    byte (*_getFont) (char)
) :
	
    stb(_stb),
    clk(_clk),
    data(_data),
    TOTAL_DIGITS(_config.TOTAL_DIGITS),
    LED_ADDR(_config.LED_ADDR),
    LED_VAL(_config.LED_VAL),
    FONT(_getFont)

{
	pinMode(stb, OUTPUT);
	pinMode(clk, OUTPUT);
	pinMode(data, OUTPUT);

	digitalWrite(stb, HIGH);
	digitalWrite(clk, LOW);
}

M_Display::M_Display( 

    const byte _stb,
    const byte _clk,
    const byte _data,
    const VMD_config& _config,
    byte (*_getFont) (char)
) :
	
    stb(_stb),
    clk(_clk),
    data(_data),
    TOTAL_DIGITS(_config.TOTAL_DIGITS),
    LED_ADDR(_config.LED_ADDR),
    LED_VAL(_config.LED_VAL),
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
	for (int i = 0; i < MD_DISPLAY_RAM_SIZE; i++)
		buffer[i] = 0x00;
    
    cursor_pos = 0;
    frame_beg = 0;

	update();
}

void M_Display::update()
{
	sendCmd(0x40);  //Incremental Address
    digitalWrite(clk, LOW); 
	digitalWrite(stb, LOW);
	shiftOut(data, clk, LSBFIRST, 0xC0);

	for (int i = 0; i < MD_DISPLAY_RAM_SIZE; i++)
		shiftOut(data, clk, LSBFIRST, buffer[i]);

	delayMicroseconds(10);
	digitalWrite(stb, HIGH);
	delay(1);
}

size_t M_Display::write(byte chr) {

    if(cursor_pos == MD_STRING_BUFFER_SIZE)
        return 0;

    str_buffer[cursor_pos] = chr;

    if(cursor_pos >= frame_beg && cursor_pos < frame_beg + TOTAL_DIGITS)
        updateFrame();

    cursor_pos++;

    return 1;
}

size_t M_Display::write(const byte *buf, size_t size) {

    if(cursor_pos == MD_STRING_BUFFER_SIZE)
        return 0;

    byte n = size < MD_STRING_BUFFER_SIZE - cursor_pos ? size : MD_STRING_BUFFER_SIZE - cursor_pos;

    memcpy(str_buffer + cursor_pos, buf, n);

    if(!(cursor_pos + n <= frame_beg || frame_beg + TOTAL_DIGITS <= cursor_pos)) 
        updateFrame();

    cursor_pos += size;

    return n;
}

void M_Display::updateFrame() {

    for(int i = 0; i < TOTAL_DIGITS; ++i) {

        if(i + frame_beg < 0 || i + frame_beg >= MD_STRING_BUFFER_SIZE)
            writeDigit(i, ' ');
        else
            writeDigit(i, str_buffer[frame_beg+i]);
    }

    update();
}

void M_Display::scroll(bool dir, byte len) {

    dir ? frame_beg += len : frame_beg -= len;

    if(frame_beg < -MD_STRING_BUFFER_SIZE) frame_beg = -MD_STRING_BUFFER_SIZE;
    else if(frame_beg > MD_STRING_BUFFER_SIZE) frame_beg = MD_STRING_BUFFER_SIZE;

    updateFrame();
}

/*
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
*/
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
