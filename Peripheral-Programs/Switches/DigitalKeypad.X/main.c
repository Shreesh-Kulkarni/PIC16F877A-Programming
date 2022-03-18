/*
 * File:   main.c
 * Author: Shreesh Kulkarni
 *
 * Created on March 18, 2022, 10:40 PM
 */


#include <xc.h>
#include "main.h"
#include "digital_keypad.h"

#pragma config WDTE = OFF        // Watchdog Timer Enable bit (WDT enabled)

static void init_config(void) {
    LED_ARRAY1 = OFF;
    LED_ARRAY1_DDR = 0x00;
    
    init_digital_keypad();
}

void main(void) {
    unsigned char key;
    
    init_config();

    while (1) {
        key = read_digital_keypad(STATE); // SW1 SW2 SW3 SW4 SW5 SW6 ALL_RELEASED
       
        // switch 4 is  pressed toggle LED1
		if(key == SW4)
		{
			LED1 = !LED1;
            for(unsigned int delay = 50000; delay--; );
		}
        /*if (key != ALL_RELEASED)
        {
            LED_ARRAY1 = key;  //0011 1011
        }*/

       
    }
    return;
}
