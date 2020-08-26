#include "fun.h"
void disable (void){
	UARTCTL&=~0x301;
	UARTCTL|=0x10;
	//gpio
}
void enable(void){
	UARTLCRH &=~0x10;
	UARTCTL|=0x301;

}
int read(void){
	int data;
	while((UARTFR&0x10)!=0)
	    data=UARTDR;
	return data;
}
void write(int data,int data_length){
	UARTLCRH|=data_length;
	while((UARTFR&0x20)!=0)
	    UARTDR = data;
}
int frame_error(void){
	int error;
	if(UARTDR&0x100)
		error=1;
	else
		error=0;
	return error;
}
int parity_error(void){
	int error;
	if(UARTDR&0x200)
		error=1;
	else
		error=0;
	return error;
}
int overun_error(void){
	int error;
	if(UARTDR&0x800)
		error=0;
	else
		error=1;
	return error;
}
void busy(int data){
	while((UARTFR&0x8)==0)
		write(data);
}
int boud_rate(int x,int y){
	UARTIBRD = x;
	UARTFBRD =y;

}
