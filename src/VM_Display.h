#ifndef VM_DISPLAY_H
#define VM_DISPLAY_H

#include "main/M_Display.h"

class VM_Display : public M_Display
{	
public:
//init
VM_Display(const byte _stb, const byte _clk, const byte _data, struct VMD_config& VMD, byte (*_getFont) (char) = DefaultFont);

void setSeg(bool isOn, byte seg, byte digit);
void toggleSeg(byte seg, byte digit);

protected:

void sendString(String str);

const byte*& DIGIT_BITPOS;
const byte**& SEG_ADDR;

};

#endif
