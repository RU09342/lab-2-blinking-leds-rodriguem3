#include <msp430.h> 


/**
 * main.c
 * Multiple Blink
 */
int main(void)
{
    WDTCTL = WDTPW | WDTHOLD;               // Stop WDT

    P1OUT &= ~BIT0;                         // Clear P1.0 output
    P1DIR |= BIT0;                          // Set P1.0 to output 
    P1OUT &= ~BIT6;                        // Clear P1.1 output latch
    P1DIR |= BIT6;                          // Set p1.1 output latch

    while(1)
    {
        P1OUT ^= BIT0;                      // Toggle LED
        P1OUT ^= BIT6;                      //Toggle LED
        __delay_cycles(300000);             //delay
        P1OUT ^= BIT6;                      //Toggle LED different rate
        __delay_cycles(300000);             /delay
    }
}
