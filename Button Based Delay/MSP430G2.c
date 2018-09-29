#include <msp430.h>

volatile unsigned int TC1 = 0;  // Timer set initialized to 0

int main(void)
{
	WDTCTL = WDTPW | WDTHOLD;   // Disable the watchdog timer
	BCSCTL3 = LFXT1S_2;         // Enables internal oscillator

	P1DIR |= BIT6;  // Set P1.6 to output
    	P1REN |= BIT3;   // Enable internal resistor
    	P1OUT |= BIT3;   // Enable Pull-up Resistor

    	P1IE |= BIT3;    // Set P1.3 as interrupt pin
    	P1IES |= BIT3;   // Set P1.3 to interrupt on falling edge

 	TACCTL0 = CCIE; // Capture Compare Interrupt Enabled
  	TACCR0 = 100;   // Set Register
  	TACTL = TASSEL_1 + MC_1 + ID_3; // Timer A Control: ACLK, Up Mode, Internal Divider


    __enable_interrupt();   // Enables interrupt algorithm
    for(;;){};  //Continuous loop
}

#pragma vector=TIMER0_A0_VECTOR
__interrupt void Timer_A(void)
{
    P1OUT ^= BIT6;  // Toggle P1.6
}

#pragma vector = PORT1_VECTOR
__interrupt void Port_1(void)
{
    if(P1IES & BIT3){   //Interrupt falling Edge

        TACTL = TACLR;  // Clear Timer
        TACTL = TASSEL_1 + MC_2 + ID_3; // Timer A Control: ACLK, Continuous mode, Internal Divider
        P1IES &= ~BIT3; // Set Rising Edge nterrupt
    }

    else{
        TACCR0 = TA0R;  // Sets register
        TACTL = TASSEL_1 + MC_1 +ID_3;  // Timer A Control: ACLK, Up mode, Internal Divider
        P1IES |= BIT3;  // Set Falling Edge Interrupt 
    }

    P1IFG &= ~BIT3;    // Resets interrupt flag for P1.3

}
