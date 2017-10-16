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
    P4OUT &= ~BIT7;                        // Clear P1.1 output latch
    P4DIR |= BIT7;                          // Set p1.1 output latch
    P1DIR &= ~BIT1;
    P1REN |= BIT1;
    P1OUT |= BIT1;


    while(1)
    {
        P1OUT ^= BIT0;                      // Toggle LED
        P4OUT ^= BIT7;                      //Toggle LED
        __delay_cycles(300000);             //delay
        P4OUT ^= BIT7;                      //Toggle LED different rate
        __delay_cycles(300000);             //delay
    }
}

