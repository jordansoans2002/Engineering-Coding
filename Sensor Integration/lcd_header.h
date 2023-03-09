#include <reg51.h>
#include <string.h>

void init();
void write(unsigned char );
void cmd(unsigned char );
void display(unsigned char *s,unsigned char len);
void delay(unsigned int );

sbit rs = P2^0;
sbit rw = P2^1;
sbit en = P2^2;


void init(){
	cmd(0x38);
	cmd(0x0E);
	cmd(0x01);
	cmd(0x06);
	cmd(0x80);
}

void cmd(unsigned char d){
	P3 = d;
	rs = 0;
	rw = 0;
	
	en = 1;
	delay(1);
	en = 0;
	delay(10);
}

void write(unsigned int d){
	P3 = d;
	rs = 1;
	rw = 0;
	
	en = 1;
	delay(1);
	en = 0;
}

void display(char *s,unsigned char len){
	unsigned int i;
	for(i=0;i<len;i++){
		write(s[i]);
		delay(1);
	}
}

void rev_display(char *s,unsigned int len){
	unsigned int i;
	cmd(0x01);
	cmd(0x80);
	for(i=len-1;i>=0;i--){
		write(s[i]);
		delay(1);
	}
}

void delay(unsigned int d){
	unsigned int a;
	unsigned int b;
	for(a=0;a<d;a++)
		for(b=0;b<1275;b++);
}