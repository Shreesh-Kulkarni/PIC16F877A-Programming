/*
 * File:   main.c
 * Author: Shreesh Kulkarni
 *
 * Created on March 11, 2022, 2:29 PM
 */


#include <xc.h>
#pragma config WDTE = OFF//watchdog timer disabled so that microcontroller doesnt get resetted
void init_config(void){
    //setting PORTB register as an output
    TRISB=0;
    //turning all leds off
    PORTB=0x00;
    
}
void main(void) {
    unsigned int delay;
    init_config();
    while (1){
        //turn on the leds
        PORTB=0x0F;
        for(delay=0;delay<50000;delay++);//delay
        PORTB=0xF0;
        for(delay=0;delay<50000;delay++);//delay
        // PIC16F877A Configuration Bit Settings
    }
}