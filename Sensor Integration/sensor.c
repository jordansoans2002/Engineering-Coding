#include <reg51.h>
#include "lcd_header.h"
#define adc_input P1

sbit wr = P2^5;
sbit rd = P2^6;
sbit intr = P2^7;

void convert_display(unsigned char val)
{
  unsigned char x1,x2,x3;
  cmd(0x86);  //set cursor position
  x1=(val/10)+0x30;//tens place digit
  x2=val%10+0x30;//units place digit
  x3=0xDF;     //degree(°) symbol
  write(x1);  
  write(x2);
  write(x3);
  write('C');
}

void main(){
	unsigned char val,i=0;
	init();

	intr = 1;
		
	while(1){
		rd=1;
		delay(10);
		wr = 1;
		delay(1); 
		wr = 0; //start conversion
		//intr=0 means conversion is over
		while(intr == 1); 
		rd = 0; //rd low to read data
		val = P1;
		convert_display(val);
		//write(++i +48);
		delay(10);
	}
		
}
