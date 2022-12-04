#ifndef DISPLAY_FONT_H
#define DISPLAY_FONT_H

#include "Arduino.h"

class DisplayFont {
    public:
        
        DisplayFont(byte (*_getFont) (char)) :
            getFont(_getFont) {}

        byte operator[] (char asciiChar) {
            return getFont(asciiChar);
        }

    private:

        byte (*getFont) (char);
};

#endif
