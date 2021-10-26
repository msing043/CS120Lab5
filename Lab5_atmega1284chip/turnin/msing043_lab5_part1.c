/*	Author: msing043
 *  Partner(s) Name: 
 *	Lab Section:
 *	Assignment: Lab #  Exercise #
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
    unsigned char tempA = 0x00;
    unsigned char tempB = 0x00;

	
while(1){
tempA=~PINA;
tempB=0x00;
if (((tempA&0x0F)==0x0F)||((tempA&0x0E)==0x0E)||((tempA&0x0D)==0x0D)) {
        tempB = 0x3F;
}
else if (((tempA&0x0C)==0x0C)||((tempA&0x0B)==0x0B)||((tempA&0x0A)==0x0A)) {
	tempB = 0x3E;
}
else if (((tempA&0x09)==0x09)||((tempA&0x08)==0x08)||((tempA&0x07)==0x07)) {
        tempB = 0x3C;
}
else if (((tempA&0x06)==0x06)||((tempA &0x05)==0x05)) {
	tempB=0x38;
}
else if (((tempA&0x04)==0x04)||((tempA&0x03)==0x03)) {
        tempB = 0x70;
}
else {
	tempB = 0x40; //empty gas tank?
}
PORTC=tempB;
}
return 1;
}
