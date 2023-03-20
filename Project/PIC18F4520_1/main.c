#pragma config OSC=HS
#pragma config WDT=OFF
#pragma config LVP=OFF
#pragma config DEBUG=OFF

#include <p18cxxx.h>
#include <adc.h>
#include <stdlib.h>
#include <delays.h>
#include <adc.h>
#include "uart.h"

#define MASK(X) 0x01<<X

static enum chess_stages {
    DISABLED, CONFIGURATION, ACTIVE
} currentStage = CONFIGURATION;

struct playerTimer {
    int time;
} player1,player2;

char *echo[10];
char *buff[32] = "HELLO";
float knobTimer = 0;
void switchTC(void);

void main(void) {
    LATB = 0x00;
    TRISB = 0xFF;
    LATC = 0x00;
    TRISC = 0x00;
    TRISA = 0xFF;
    
    OpenADC(ADC_FOSC_32 & ADC_RIGHT_JUST & ADC_20_TAD, ADC_CH0 & ADC_INT_OFF & ADC_VREFPLUS_VDD & ADC_VREFMINUS_VSS, 0b0100);
    SetChanADC(ADC_CH0);
    
    initUART();
    sendMessage("Switching to Fischer BLITZ Mode");
   while (BusyADC());
    while (1) {
        if (PORTBbits.RB4 == 1) {
            switchTC();
            Delay10KTCYx(100);
        }
         ConvertADC();    
        if (knobTimer != ADRESL) {
            knobTimer=ADRESL;
            itoa(knobTimer,&echo);
            sendMessage(echo);
	    Delay10KTCYx(100);
        }
    }


}

void switchTC(void) {

    static enum tc_options {
        BLITZ, RAPID, FBLITZ, FRAPID
    } tc_option = BLITZ;
    switch (tc_option) {
        case BLITZ:
            tc_option = RAPID;
	    sprintf(buff, "Switching to RAPID Mode");
	    sendMessage(buff);
            break;
        case RAPID:
            tc_option = FBLITZ;
	    sprintf(buff, "Switching to Fischer BLITZ Mode");
	    sendMessage(buff);
            break;
        case FBLITZ:
            tc_option = FRAPID;
	    sendMessage("Switching to Fischer RAPID Mode");
            break;
        case FRAPID:
            tc_option = BLITZ;
	    sendMessage("Switching to BLITZ Mode");
            break;
        default:
            tc_option = BLITZ;
            break;
    }
}
