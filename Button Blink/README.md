# Button Blink(Extra)
##Author: Matthew Rodriguez, Austin Huang, Shea Plunkett
## Summary 
Initially an LED is powered and turned on and blinking, when a button is pressed the LED that is being powered will turn off and a different LED with a different
color will turn on and blink.
##Notes
Because this program was and can be run on different MSP430 boards that use different pins, the specific pin numbers will be replaced with the variable "X" (i.e. PXOUT ^= BITX;)
The first thing this program does is stop the watch dog timer, this is done to ensure that the processor will not reset. This is done with the following statement:
```c
	WDTCTL = WDTPW + WDTHOLD or WDTCTL = WDTPW | WDTHOLD
```
The pins are first initialized to determine which are inputs and outputs. 
Example:
```c
	//Inputs:
	PXDIR &= ~BITX; //Sets this pin as an input.
    PXREN |= BITX;  //Sets this pin to use a pull up/down resistor.
    PXOUT |= BITX;  //Sets this pin to use a pull up resistor.
	//Outputs:
	PXOUT &= ~X; //Clears this pin(for safety).
    PXDIR |= BITX;  //Sets this pin as an output.
```
##How the code works
To check whether or not the button has been pressed this program uses polling. This means that the bulk of the code is in an infinite while loop.
when the button is pressed the loop will reach an if statement checking if the button is pressed and execute the code to turn on the LED.
Example:
```can while(1){

    while(lSelect == 1)//This while loop will continuously loop allowing the bottom if statement to constantly check if the button is being pressed.
    {
        P1OUT ^= BIT0;            //Toggle the LED on or off.
        __delay_cycles(500000);   //Speed of the LED blinking on and off.
        if(!(P5IN & BIT6)){		  //Checks if the button has been pressed.
             lSelect = 0;	  
             P1OUT &= ~BIT0;      //Turns off the LED;
            }
    }

	//The following works the same as the above code.
    while(lSelect == 0){
        P1OUT ^= BIT1;            
        __delay_cycles(100000);             
        if(!(P5IN & BIT6)){
                 lSelect = 1;
                 P1OUT &= ~BIT1;
                }
        }
    }
```

##Differences between boards
Primarily the MPS430g2553 and MSP430f5529 does not use __delay_cycles to cause a delay, it instead uses a for loop with variable i to loop a certain amount of time.
i is required to be declared as a volatile unsigned int. 
The MSP430g2553 uses for(;;) to initalize an infinite loop instead of while(1)
All the boards have different pin assignments.
##Implementation
Use a C compiler to run the code and upload it to an MSP430. An LED will be blinking initially, press the button to switch which LED is blinking.