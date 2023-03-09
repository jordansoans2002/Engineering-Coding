#include "lcd_header.h"
#define adc_input P1

sbit wr = P2^5;
sbit rd = P2^6;
sbit intr = P2^7;

void setup() {
  // put your setup code here, to run once:
  init();
  
  intr = 1;
  rd = 1;
  wr = 1;
}

void loop() {
  // put your main code here, to run repeatedly:
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
