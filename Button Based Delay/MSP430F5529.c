#include <msp430.h>

volatile unsigned int TC1 = 0;  // Timer set to 0

int main(void)
{
    WDTCTL = WDTPW | WDTHOLD;   // Disable the watchdog timer

    P1DIR |= BIT0;  // Set P1.0 to output
    P1REN |= BIT1;   // Enable internal Resistor
    P1OUT |= BIT1;   // Enable PUll-up Resistor

    P1IE |= BIT1;    // Set P1.1 as interrupt 
    P1IES |= BIT1;   // Set P1.1 to interrupt on falling edge 

    TA0CCTL0 = CCIE;    // Capture Compare Interrupt Enable
    TA0CCR0 = 100;  // Set Register
    TA0CTL = TASSEL_1 + MC_1 + ID_3;    // TimerA0 Control: ACLK, Up mode


    __enable_interrupt();   // Enables interrupt

    for(;;){};  // continuous loop
}

#pragma vector=TIMER0_A0_VECTOR
__interrupt void Timer0_A0(void)
{
    P1OUT ^= BIT0;  // Toggle P1.0
}

#pragma vector = PORT1_VECTOR
__interrupt void Port_1(void)
{
    if(P1IES & BIT1){   // Port 1 Interrupt Edge Select (Falling Edge)

        TA0CTL = TACLR; // Clear timer
        TA0CTL = TASSEL_1 + MC_2 + ID_3;    // TimerA0 Control: ACLK, Continuous mode
        P1IES &= ~BIT1; // Set Rising Edge Interrupt
    }

    else{
        TA0CCR0 = TA0R;
        TA0CTL = TASSEL_1 + MC_1 +ID_3; // TimerA0 Control: ACLK, Up mode
        P1IES |= BIT1;  // Set Falling Edge Interrupt
    }

    P1IFG &= ~BIT1;    // Resets interrupt flag for P1.1

}
