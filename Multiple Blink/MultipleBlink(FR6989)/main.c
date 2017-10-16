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
    P9OUT &= ~BIT7;                        // Clear P1.1 output latch
    P9DIR |= BIT7;                          // Set p1.1 output latch

    PM5CTL0 &= ~LOCKLPM5;                   // Disable the GPIO power-on default high-impedance mode
                                            // to activate previously configured port settings

    while(1)
    {
        P1OUT ^= BIT0;                      // Toggle LED
        P9OUT ^= BIT7;                      //Toggle LED
        __delay_cycles(300000);             //delay
        P9OUT ^= BIT7;                      //Toggle LED different rate
        __delay_cycles(300000);             /delay
    }
}
