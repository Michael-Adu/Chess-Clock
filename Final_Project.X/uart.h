/*
 * File:   display.h
 * Author: Michael Nimdea-Gyan Adu
 *
 * Created on 03 March 2023, 11:46
 */

#ifndef UART_H
#define UART_H

#include <p18cxxx.h>
#include <delays.h>
#include <usart.h>
#include <stdlib.h>
#include <stdio.h>

extern void initUART(void);
extern void sendMessage(char *data);

#endif
