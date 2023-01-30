#include <reg51.h>
#include "lcd_header.h"
#define adc_input P1

sbit wr = P2^5;
sbit rd = P2^6;
sbit intr = P2^7;

unsigned char value;
void main(){
	init();
	
	P1 = 0xFF;
	P3 = 0x00;
	
	intr = 1;
	rd = 1;
	wr = 1;
	
	while(1){
		delay(10);
		wr = 1;
		delay(10); //high to low pulse on wr to start conversion
		wr = 0;
		while(intr == 1); // wait for conversion to finish
		rd = 0; //rd low to read data
		value = P1;
		write('1');
		delay(10);
		rd = 1;
		
	}
		
}