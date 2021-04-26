/*	Author: msing043
 *  Partner(s) Name: 
 *	Lab Section:023
 *	Assignment: Lab #5  Exercise #1
 *	Exercise Description: [optional - include for your own benefit]
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

int main(void) {

    DDRA = 0x00; PORTA = 0xFF;
    DDRC = 0xFF; PORTC = 0x00;
    unsigned char tmpA = 0x00;
    unsigned char tmpB = 0x00;

while(1){
tmpA=~PINA;
tmpB=0x00;
if (((tmpA & 0x0F) == 0x0F) || ((tmpA & 0x0E) == 0x0E) || ((tmpA & 0x0D) == 0x0D)) {
                tmpB = 0x3F;
}
else if (((tmpA & 0x0C) == 0x0C) || ((tmpA & 0x0B) == 0x0B) || ((tmpA & 0x0A) == 0x0A)) {
                tmpB = 0x3E;
}
else if (((tmpA & 0x09) == 0x09) || ((tmpA & 0x08) == 0x08) || ((tmpA & 0x07) == 0x07)) {
                tmpB = 0x3C;
}
else if (((tmpA & 0x06) == 0x06) || ((tmpA & 0x06) == 0x06)) {
                tmpB = 0x38;
}
else if (((tmpA & 0x04) == 0x04) || ((tmpA & 0x03) == 0x03)) {
                tmpB = 0x70;
}
else if (((tmpA & 0x02) == 0x02) || ((tmpA & 0x01) == 0x01)) {
		tmpB = 0x60;
}
else {
	tmpB = 0x40;
}
PORTC=tmpB;
}
return 1;
}
