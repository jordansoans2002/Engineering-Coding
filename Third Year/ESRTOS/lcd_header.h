#include <reg51.h>
#include <string.h>

void init();
void write(unsigned char );
void cmd(unsigned char );
void display(unsigned char *s,unsigned char len);
void delay(unsigned int );

sbit rs = P3^0;
sbit rw = P3^1;
sbit en = P3^2;
	

void init(){
	cmd(0x38);
	cmd(0x0E);
	cmd(0x01);
	cmd(0x06);
	cmd(0x80);
}

void cmd(unsigned char d){
	P2 = d;
	rs = 0;
	rw = 0;
	
	en = 1;
	delay(1);
	en = 0;
	delay(100);
}

void write(unsigned char d){
	P2 = d;
	rs = 1;
	rw = 0;
	
	en = 1;
	delay(1);
	en = 0;
}

void display(char *s,unsigned int len){
	unsigned int i;
	for(i=0;i<len;i++)
		write(s[i]);
}

void delay(unsigned int d){
	unsigned int a,b;
	for(a=0;a<d;a++)
		for(b=0;b<1275;b++);
}

void bus_display(){
	unsigned int i;
	char s[41] = "211 Bandra Station to Father Agnel Ashram";

	delay(100);
	init();
		
	
	for(i=0;i<69;i++){
		if(i==0){
			cmd(0x01);
			cmd(0x90);
			display("211 Bandra Station to",21);
		}
		if(i==32){
			cmd(0x01);
			cmd(0x88);
			display(" Father Agnel Ashram",20);
		}
		delay(10000);
		cmd(0x1C);
		//cmd(0x07);
	}
	
}