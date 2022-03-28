/*
 * File:   main.c
 * Author: Shreesh Kulkarni
 *
 * Created on March 28, 2022, 8:29 PM
 */


#include <xc.h>
#include "adc.h"
#include "main.h"
#pragma config WDTE=OFF

void glow_led(unsigned short adc_reg_val)
{
    if (adc_reg_val >= 512)
    {
        LED1 = ON;
    }
    else
    {
        LED1 = OFF;
    }
}

static void init_config(void) {
    LED_ARRAY1 = OFF;
    LED_ARRAY1_DDR = 0x00;
    
    init_adc();
}

void main(void) {
    unsigned short adc_reg_val; //0 to 1023
    
    init_config();

    while (1) {
        adc_reg_val = read_adc();//10 bits -> 0 to 1023
        
        glow_led(adc_reg_val);
    }
    return;
}

