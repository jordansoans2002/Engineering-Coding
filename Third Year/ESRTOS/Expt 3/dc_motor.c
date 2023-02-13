#include <timer.h>
#include <reg51.h>

sbit wr = P3^0;
sbit rd = P3^1;
sbit intr = P3^2;

sbit sw = P3^7;

sbit in11 = P2^0;
sbit in12 = P2^1;
sbit en1 = P2^2;

sbit en2 = P2^5;
sbit in21 = P2^6;
sbit in22 = P2^7;
void delay(unsigned int d){
	unsigned int i,j;
	for(i=0;i<d;i++)
		for(j=0;j<637;j++);
}


void turn_motor(unsigned int val){
	while(1){
		if(sw==0){ // if switch is pressed
			//turn motor clockwise
			in11 = 1; 
			in12 = 0;
			in21 = 1;
			in22 = 0;
		}else{
			//turn motor anticlockwise
			in11 = 0;
			in12 = 1;
			in21 = 0;
			in22 = 1;
		}
		en1 = 1;
		en2 = 1;
		delay(val);
		en1 = 0;
		en2 = 0;
		delay(val);
	}
}

void main(){
	turn_motor(10);		
}
