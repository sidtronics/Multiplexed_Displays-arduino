#ifndef HM_DISPLAY_H
#define HM_DISPLAY_H

#include "main/M_Display.h"

class HM_Display : public M_Display
{
public:
//init
HM_Display(const byte _stb, const byte _clk, const byte _data, struct HMD_config& HMD, byte (*_getFont) (char) = DefaultFont);

void setSeg(bool isOn, byte seg, byte digit);
void toggleSeg(byte seg, byte digit);

protected:

void sendString(String str);

const byte*& DIGIT_ADDR;

};

#endif
