#include <msp430.h> 


/**
 * main.c
 * ButtonBlink
 */
int main(void)
{
    WDTCTL = WDTPW | WDTHOLD;               // Stop WDT

    // Configure GPIO
    P1OUT &= ~BIT0;                         // Clear P1.0 output latch for a defined power-on state
    P1DIR |= BIT0;                          // Set P1.0 to output direction
    P1OUT &= ~BIT1;                        // Clear P1.1 output latch
    P1DIR |= BIT1;                          // Set p1.1 output latch

    P5DIR &= ~BIT6;
    P5REN |= BIT6;
    P5OUT |= BIT6;

    PM5CTL0 &= ~LOCKLPM5;                   // Disable the GPIO power-on default high-impedance mode
                                            // to activate previously configured port settings
    int swap = 1;


    while(1){

    while(swap == 1)
    {
        P1OUT ^= BIT0;                      // Toggle LED
        __delay_cycles(500000);   //Adjust speed
        if(!(P5IN & BIT6)){
                       swap = 0;
                       P1OUT ^= ~BIT0;
            }
    }

    while(swap == 0){
        P1OUT ^= BIT1;                      //Toggle one of the two LED at different rate
        __delay_cycles(100000);             //Adjust speed
        if(!(P5IN & BIT6)){
                               swap = 1;
                               P1OUT ^= ~BIT1;
                    }
        }
    }

}
