#include<reg51.h>

sbit sw = P3^1;

void delay(unsigned int d){
	int i,j;
	for(i=0;i<d;i++)
		for(j=0;j<1275;j++);
}

int leftRotate(int n){
	return (n << 1) | (n >> 7);
}
 
int rightRotate(int n){
	return (n >> 1) | (n << 7);
}
		
void main(){
	int i;
	/*while(1){
		if(sw==0){
			leftRotate(P2);
			delay(10);
		}else{
			rightRotate(P2);
			delay(10);
		}
	}*/
	
	for(i=0;;i++){
		if(sw==0){
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
	
	while(1);
}
