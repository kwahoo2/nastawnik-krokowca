// Test fixed-point multiply     
             
#include <inttypes.h>
#include <avr/io.h>
#include <avr/interrupt.h>
#include <stdio.h>
//#include <stdlib.h>

//set up the debugging utility ASSERT
#define __ASSERT_USE_STDERR
#include <assert.h>
#include "uart.h"


/* define CPU frequency in Mhz here if not defined in Makefile */
#ifndef F_CPU
#define F_CPU 16000000UL
#endif

/********************************************************************************
Macros and Defines
********************************************************************************/

#define BAUD 9600
#define MYUBRR F_CPU/16/BAUD-1

// UART file descriptor
// putchar and getchar are in uart.c
FILE uart_str = FDEV_SETUP_STREAM(usart_putchar, usart_getchar, _FDEV_SETUP_RW);

volatile uint8_t steps[4] = {0x09, 0x0C, 0x06, 0x03}; //4 full steps

int main(void)
{  
    
  DDRB = 0x0F;
  DDRC = 0x0F;
  DDRD = 0x3C; //PD0 and PD1 are uart
    
  //init the UART -- uart_init() is in uart.c
  usart_init ( MYUBRR );
  
  uint8_t iX = 0;
  uint8_t iY = 0;
  uint8_t iZ = 0;
  
  sei();
  while(1)
  {
    uint8_t step = usart_getchar();
    
    if (step & 0b00000001)
    {
        iX++;
        if (iX > 3) iX = 0;
    }
    if (step & 0b00001000)
    {
        if (iX > 0) 
        {
            iX--;
        }
        else
        {
            iX = 3;
        }
    }
    
    if (step & 0b00000010)
    {
        iY++;
        if (iY > 3) iY = 0;
    }
    if (step & 0b00010000)
    {
        if (iY > 0) 
        {
            iY--;
        }
        else
        {
            iY = 3;
        }
    }

    if (step & 0b00000100)
    {
        iZ++;
        if (iZ > 3) iZ = 0;
    }
    if (step & 0b00100000)
    {
        if (iZ > 0)
        {
            iZ--;
        }
        else
        {
            iZ = 3;
        }
    }

    PORTB = steps[iX];
    PORTC = steps[iY];
    PORTD = (steps[iZ] << 2);

  }
} 




