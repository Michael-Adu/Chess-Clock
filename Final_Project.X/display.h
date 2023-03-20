/* 
 * File:   display.h
 * Author: Michael Nimdea-Gyan Adu
 *
 * Created on 04 March 2023, 13:36
 */

#ifndef DISPLAY_H
#define	DISPLAY_H

#include <p18cxxx.h>
#include <xlcd.h>
#include <stdlib.h>
#include <stdio.h>
#include "uart.h"



void lcdDisplay(char *data, int row);
void lcdCommand(unsigned int command);
void initLCD(void);
void lcdClear();

#endif	/* DISPLAY_H */

