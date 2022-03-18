/*
 * File:   main.c
 * Author: Shreesh Kulkarni
 *
 * Created on March 18, 2022, 10:10 PM
 */


#include <xc.h>
#include "main.h"
#pragma config WDTE=OFF
static void init_config(void) {
    PORTD = 0x00; // All LEDs are OFF 
    TRISD = 0x00;
    //LED1 = OFF;
    //LED1_DDR = 0;
    SW1_DDR = 1;
}

void main(void) {
    int once = 1;
    
    init_config();

    while (1) {
        if ((SW1 == PRESSED) && once)  //RB0 == 0
        {
            LED1 = !LED1;
            
            once = 0;
        }
        else if (SW1 == RELEASED) // RB0 == 1
        {
            once = 1;
        }
    }
    return;
}
