#include <msp430.h>

int main(void)
{
	WDTCTL = WDTPW | WDTHOLD;// Disable watchdog timer
    P1DIR = BIT0;           // Set P1.0 as output
    P1REN = BIT3;           // Enable resistor
    P1OUT = BIT3;           // Enable Pull-up Resistor

    P1IE = BIT3;            // Set P1.3 as interrupt pin
    P1IFG &= ~BIT3;

    __enable_interrupt();   // Enables interrupt 

    for(;;){};  // Continuos Loop
}

#pragma vector = PORT1_VECTOR  
__interrupt void Port_1(void)
{
    P1OUT ^= (BIT0);    // Toggle P1.0
    P1IFG = ~BIT3;      // Reset interrupt flag for P1.3
}
