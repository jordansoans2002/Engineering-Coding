#include <reg51.h>
#include "lcd_header.h"
#define adc_input P1

sbit wr = P2^5;
sbit rd = P2^6;
sbit intr = P2^7;

unsigned int value;

void convert_display(unsigned char value)
{
  unsigned char x1,x2,x3;
  cmd(0x86);  //set cursor position
  x1=(value/10)+0x30;//tens place digit
  x2=value%10+0x30;//units place digit
  x3=0xDF;     //degree(°) symbol
  write(x1);  
  write(x2);
  write(x3);
  write('C');
}

void main(){
	init();
	
	intr = 1;
	rd = 1;
	wr = 1;
	
	while(1){
		delay(10);
		wr = 1;
		delay(1); 
		wr = 0; //start conversion
		//intr=1 means conversion is over
		while(intr == 1); 
		rd = 0; //rd low to read data
		value = P1;
		convert_display(value*2);
		delay(10);
		rd = 1;
	}
		
}
