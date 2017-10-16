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
    P1OUT &= ~BIT1;                        // Clear P1.1 output latch
    P1DIR |= BIT1;                          // Set p1.1 output latch
    P5DIR &= ~BIT6;
    P5REN |= BIT6;
    P5OUT |= BIT6;

    PM5CTL0 &= ~LOCKLPM5;                   // Disable the GPIO power-on default high-impedance mode
                                            // to activate previously configured port settings

    while(1)
    {
        P1OUT ^= BIT0;                      // Toggle LED
        P1OUT ^= BIT1;                      //Toggle LED
        __delay_cycles(300000);             //delay
        P1OUT ^= BIT1;                      //Toggle LED different rate
        __delay_cycles(300000);             //delay
    }
}
