#include <Arduino.h> //for "byte"

byte DefaultFont(char asciiChar) {
    
    switch(asciiChar) {

        case ' ' : return 0b00000000;
        case '!' : return 0b00001110;
        case '"' : return 0b00100010;
        case '#' : return 0b01111110;
        case '$' : return 0b01101101;
        case '%' : return 0b00101101;
        case '\'': return 0b00100000;
        case '(' : return 0b00110000;
        case ')' : return 0b00000110;
        case '*' : return 0b01100011;
        case ',' : return 0b00010000;
        case '-' : return 0b01000000;
        case '.' : return 0b00001000;
        case '/' : return 0b01010010;
        case '0' : return 0b00111111;
        case '1' : return 0b00000110;
        case '2' : return 0b01011011;
        case '3' : return 0b01001111;
        case '4' : return 0b01100110;
        case '5' : return 0b01101101;
        case '6' : return 0b01111101;
        case '7' : return 0b00000111;
        case '8' : return 0b01111111;
        case '9' : return 0b01101111;
        case ':' : return 0b00001001;
        case ';' : return 0b00000101;
        case '<' : return 0b01000110;
        case '=' : return 0b01001000;
        case '>' : return 0b01110000;
        case '?' : return 0b01010011;
        case '@' : return 0b01011111;
        case 'A' : return 0b01110111;
        case 'B' : return 0b01111100;
        case 'C' : return 0b00111001;
        case 'D' : return 0b01011110;
        case 'E' : return 0b01111001;
        case 'F' : return 0b01110001;
        case 'G' : return 0b00111101;
        case 'H' : return 0b01110110;
        case 'I' : return 0b00110000;
        case 'J' : return 0b00001110;
        case 'K' : return 0b01110101;
        case 'L' : return 0b00111000;
        case 'M' : return 0b01010101;
        case 'N' : return 0b01010100;
        case 'O' : return 0b01011100;
        case 'P' : return 0b01110011;
        case 'Q' : return 0b01100111;
        case 'R' : return 0b01010000;
        case 'S' : return 0b01101101;
        case 'T' : return 0b01111000;
        case 'U' : return 0b00111110;
        case 'V' : return 0b00101010;
        case 'W' : return 0b01101010;
        case 'X' : return 0b00010100;
        case 'Y' : return 0b01101110;
        case 'Z' : return 0b01011011;
        case '[' : return 0b00111001;
        case '\\': return 0b01100100; 
        case ']' : return 0b00001111;
        case '_' : return 0b00001000;
        
        default : return 0b00000000;
    }
}
