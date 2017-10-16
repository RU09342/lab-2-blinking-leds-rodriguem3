# Multiple Blink
## Author: Matthew Rodriguez, Austin Huang, Shea Plunkett
## Summary
This program will make two LEDs blink at different rates.
## Notes
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

The program is run in an infinite loop using while(1). Toggling the LED between the delays allows for different toggle rates.
Example:
```c
 while(1)									//Creates an infinite loop so the program will repeat forever.
    {
        P1OUT ^= BIT0;                      //Toggle LED1 on and off.
        P1OUT ^= BIT1;                      //Toggle LED2 on and off.
        __delay_cycles(500000);             //Adjust speed
        P1OUT ^= BIT1;                      //Toggle LED2 at a different rate
        __delay_cycles(500000);             //Adjust speed
    }
```


## Differences between boards
Primarily the MPS430g2553 and MSP430f5529 does not use __delay_cycles to cause a delay, it instead uses a for loop with variable i to loop a certain amount of time.
i is required to be declared as a volatile unsigned int. 
The MSP430g2553 uses for(;;) to initalize an infinite loop instead of while(1)
All the boards have different pin assignments.
## Implementation
Use a C compiler to run the code and upload it to an MSP430. Now watch as the LEDs blink for you!
