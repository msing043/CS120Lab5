/*	Author: msing043
 *	Assignment: Lab #5  Exercise #2
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

enum stateMachine{Begin,Standby,Initializer,Reset,Addition,Subtraction,Increment,Decrement}SM;
void buttonMachine() {
	switch(SM) {
	case Begin:
		PORTC=0x07;
		SM=Initializer;
		break;
	case Standby:
		SM=Initializer;
		break;
			
	case Initializer:
		if((PINA&0x03)==0x03) {
                        SM=Reset;
                }
		else if((PINA&0x01)==0x01) {
			SM=Increment;
		}
		else if((PINA&0x02)==0x02) {
                        SM=Decrement;
                }
		else if(PINA==0){
			SM=Standby;
		}
		break;

	case Reset:
		if((PINA & 0x03)==0x03) {
			SM=Reset;
		}
		else{
			SM=Begin;
		}
		break;
		
	case Addition:
		if((PINA & 0x01)==0x01) {
	        	SM=Addition;
                }
                else{
        	        SM=Reset;
                }
                break;

	case Increment:
		SM=Addition;
		break;
			
	case Subtraction:
                if((PINA & 0x02)==0x02) {
    	            SM=Subtraction;
                }
                else{
     	           SM=Reset;
                    }
                break;
	
	case Decrement:
		SM=Subtraction;
		break;
			
	default:
		SM=Begin;
		break;
	}
	
	
	switch(SM){
	case Begin:
	PORTC=0x07;
	break;
			
	case Standby:
	break;

	case Initializer:
	break;

	case Addition:
	break;

	case Subtraction:
	break;

	case Increment:
	if(PORTC<0x09){
        PORTC=PORTC+1;
	}
        break;	
			
	case Decrement:
	if(PORTC>0x00){ 
        PORTC=PORTC-1;
	}
        break;
			
	case Reset:
	PORTC=0x00;
	break;
	
	default:
	PORTC=0x07;
	break;
	}
}
int main() {
    DDRA=0x00; PORTA=0xFF;
    DDRC=0xFF; PORTC=0x00;
    while (1) {
	buttonMachine();
   	 }
   	 return 1;
	}
