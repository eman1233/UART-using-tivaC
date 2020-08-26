#ifndef __FUN_H__
#define __FUN_H__
#include <stdint.h>
#define UART0 ((uint32_t)0x4000C000)
#define UARTDR   (*((uint32_t*)(UART0+0x000)))
#define UARTFR   (*((uint32_t*)(UART0+0x108)))
#define UARTIBRD (*((uint32_t*)(UART0+0x024)))
#define UARTFBRD (*((uint32_t*)(UART0+0x028)))
#define UARTLCRH (*((uint32_t*)(UART0+0X02c)))
#define UARTCTL  (*((uint32_t*)(UART0+0x030)))
//gpio
void disable (void);
void enable(void);
int read(void);
void write(int data,int data_length);
int frame_error(void);
int parity_error(void);
overun_error(void);
busy(int data);
boud_rate(int x,int y);
#endif
