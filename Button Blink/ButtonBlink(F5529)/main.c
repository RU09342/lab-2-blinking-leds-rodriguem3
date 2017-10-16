#include <msp430.h> 


/**
 * main.c
 * ButtonBlink
 */
int main(void)
{
    WDTCTL = WDTPW | WDTHOLD;               // Stop WDT

    // Configure GPIO
    P1DIR |= BIT0;                          // Set P1.0 to output 
    P1OUT &= ~BIT0;                         // Clear P1.0 output 
    P4DIR |= BIT7;                          // Set p1.1 output 
    P4OUT &= ~BIT7;                        // Clear P1.1
    P2DIR &= ~BIT1;
    P2REN |= BIT1;
    P2OUT |= BIT1;

    int swap = 1;


    while(1){

    while(swap == 1)
    {
        P1OUT ^= BIT0;                      // Toggle LED
        __delay_cycles(500000);   //Adjust speed
        if(!(P2IN & BIT1)){
                       swap = 0;
                       P1OUT = ~BIT0;
            }
    }

    while(swap == 0){
        P4OUT ^= BIT7;                      //Toggle one of the two LED at different rate
        __delay_cycles(100000);             //Adjust speed
        if(!(P2IN & BIT1)){
                               swap = 1;
                               P4OUT = ~BIT7;
                    }
        }
    }

}
