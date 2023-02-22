#include <reg51.h>
#include "lcd_header.h"

sbit wr = P2^5;
sbit rd = P2^6;
sbit intr = P2^7;

void convert(unsigned char val){
	int i=0,j;
	unsigned char s[10];
	while(val>0){
		s[i++]=(val%10)+48;
		val=val/10;
	}
	cmd(0x01);
	display(s,i);
}
		
void main(){
	unsigned int value;
	init();
	
	intr = 1;
	
	while(1){
		rd=1;
		delay(1);
		wr = 1;
		delay(1); //high to low pulse on wr to start conversion
		wr = 0;
		while(intr == 1); // wait for conversion to finish
		rd = 0; //rd low to read data
		value = P1;
		cmd(0x01);
		convert(value);
		delay(1);
	}
		
}
