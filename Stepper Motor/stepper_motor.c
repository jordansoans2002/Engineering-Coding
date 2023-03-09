#include<reg51.h>
sbit sw = P3^1;
void delay(unsigned int d){
	int i,j;
	for(i=0;i<d;i++)
		for(j=0;j<1275;j++);
}
		
void main(){
 	while(1){
		if(sw==0){//switch pressed
			//excite pins clockwise
			P2 = 0x08; //1000
			delay(10); 
			P2 = 0x0C; //1100 
			delay(10);
			P2 = 0x04; //0100
			delay(10);
			P2 = 0x06; //0110
			delay(10);
			P2 = 0x02; //0010
			delay(10);
			P2 = 0x03; //0011
			delay(10);
			P2 = 0x01; //0001
			delay(10);
			P2 = 0x09; //1001
			delay(10);
		}
		else{
			//excite pins anti-clockwise
			P2 = 0x08; //1000
			delay(10);
			P2 = 0x09; //1001
			delay(10);
			P2 = 0x01; //0001
			delay(10);
			P2 = 0x03; //0011
			delay(10);
			P2 = 0x02; //0010
			delay(10);
			P2 = 0x06; //0110
			delay(10);
			P2 = 0x04; //0100
			delay(10);
			P2 = 0x0C; //1100 
			delay(10);
		}
	}
}
