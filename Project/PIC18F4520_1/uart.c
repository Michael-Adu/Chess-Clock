
/*
 * File:   uart.c
 * Author: micha_5j3z6p3
 *
 * Created on 03 March 2023, 10:22
 */

#include "uart.h"
#include <stdio.h>


char *message[32] = "HELLO";
void initUART(void) {
    LATD = 0x00;
   TRISD = 0x00;
   OpenUSART(USART_TX_INT_OFF & USART_RX_INT_OFF & USART_ASYNCH_MODE & USART_EIGHT_BIT & USART_CONT_RX & USART_BRGH_HIGH, 64);
   
   sendMessage("Initialised");
}

void sendMessage(char *data){
    sprintf(message, "%s\r\n", data);
    putsUSART(message);
}
