#include <msp430.h>

int main(void)
    {
  WDTCTL = WDTPW + WDTHOLD;                 // Stop QD
  P1DIR |= BIT0;                            // Set P1.0 to output direction
  P1DIR |= BIT6;                          // Set P1.6 to output direction


  for (;;)
  {

    volatile unsigned int i;
    volatile unsigned int j;
    P1OUT ^= BIT0;


    i = 10000;
    do (i--);
    while (i != 0);
    j++;
        if(j % 8 == 0)
            {
                P1OUT ^= BIT6;                      // Toggle P1.6
            }
    }
}
