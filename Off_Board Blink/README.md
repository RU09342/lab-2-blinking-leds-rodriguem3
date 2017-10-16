# Off Board Blink
##Author: Matthew Rodriguez, Austin Huang, Shea Plunkett
##Summary
The Central Processing Unit of the MSP430 G2553 recives code to make two LEDs blink at different rates.
This is then placed on a bread board to make two external LEDs to blink.

## Explaination
The chip from the MSP430 G2553 is placed on a bread board and is powered by an arduino supplying 3.3V.
To avoid damage 1k resistors are placed in series with two LEDs.
A 10k resistor is placed in series with the VCC pin and the RST pin of the circuit thie safeguards the chip from resetting.

##Implementing
Run code using a C compiler and upload to the G2553 chip. Place this chip on a breadboard and follow the schematic given in the repository.
