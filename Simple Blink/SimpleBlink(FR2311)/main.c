#include <msp430.h> 


/**
 * main.c
 * Simple Blink (2311)
 */

int main(void)
{
    WDTCTL = WDTPW | WDTHOLD;               // Stop WDT

    // Configure GPIO
    P1OUT &= ~BIT0;                         // Clear P1.0 output latch for a defined power-on state
    P1DIR |= BIT0;                          // Set P1.0 to output direction

    //P5DIR &= ~BIT6;
    //P5REN |= BIT6;
   // P5OUT |= BIT6;

   // PM5CTL0 &= ~LOCKLPM5;                   // Disable the GPIO power-on default high-impedance mode
                                            // to activate previously configured port settings

    while(1)
    {
        P1OUT ^= BIT0;                      // No Toggle LED
        __delay_cycles(100000);
    }
}
