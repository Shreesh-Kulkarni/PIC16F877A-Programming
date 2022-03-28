/*
 * File:   main.c
 * Author: Shreesh Kulkarni
 *
 * Created on March 28, 2022, 10:58 PM
 */


#include <xc.h>
#include "clcd.h"
#pragma config WDTE=OFF

static void init_config(void) {
    init_clcd();
}

void main(void) {
    init_config();

    while (1) 
    {
      	clcd_putch('4' , LINE1(5));
		clcd_print("Hello", LINE2(2));
    }
    return;
}
