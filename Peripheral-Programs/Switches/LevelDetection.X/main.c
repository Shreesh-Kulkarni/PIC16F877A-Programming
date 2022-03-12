/*
 * File:   main.c
 * Author: Shreesh Kulkarni
 *
 * Created on March 12, 2022, 5:31 PM
 */


#include <xc.h>
#include "main.h"
#pragma config WDTE = OFF//watchdog timer disabled
static void init_config(void){
    TRISD = 0;//setting DDR for PORTD as output
    PORTD = 0x00; // All LEDS OFF 
    SW1_DDR = 1; //Input //TRISB0 = 1

}

void main(void) {
    init_config();
    while(1){
        if(SW1 == PRESSED){
            LED1=!LED1;
            for(unsigned long int delay=0;delay<50000;delay++);
        }
    }
    return;
}
