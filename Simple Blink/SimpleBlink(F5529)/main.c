#include <msp430.h> 


/**
 * main.c
 * Simple Blink (5529)
 */

int main(void)
{
    WDTCTL = WDTPW | WDTHOLD;               // Stop WDT
    P1DIR |= BIT0;                          // Set P1.0 to output direction
    P1OUT &= ~BIT0;                         // Clear P1.0 output 
    while(1)
    {
        P1OUT ^= BIT0;                      // Toggle P1.0
        __delay_cycles(100000);
    }
}
