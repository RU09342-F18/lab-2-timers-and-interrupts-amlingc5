#include <msp430.h>
void main(void)
{
    WDTCTL = WDTPW | WDTHOLD;   // Disable the watch dog timer
    BCSCTL3 = LFXT1S_2;       

    P1OUT |= BIT0;              // Enable P1.0
    P1OUT &= ~BIT6;             // Disable P1.6
    P1DIR |= (BIT0 + BIT6);     // Set P1.0 and P1.6 as outputs

    TA0CTL = TASSEL_1 + MC_1 + ID_2;    // Control for TimerA0: ACLK, Up mode, Internal Divider
    TA0CCTL0 = CCIE;                    // Capture Compare Interrupt Enabled
    TA0CCR0= 1000;                      // Set Register

    TA1CTL = TASSEL_1 + MC_1 + ID_2;    // Control for TimerA1: ACLK, Up mode, Internal Divider
    TA1CCTL0 = CCIE;                    // Capture Compare Interrupt Enabled
    TA1CCR0 = 3000;                      // Set Register

    __enable_interrupt();   // Enables interrupt
    for(;;);    // Continuous loop
}

#pragma vector = TIMER0_A0_VECTOR
__interrupt void TIMER_A0(void)
{
    P1OUT ^= BIT0;      // Toggle P1.0
}

#pragma vector = TIMER1_A0_VECTOR
__interrupt void TIMER_A1(void)
{
    P1OUT ^= BIT6;      // Toggle P1.6
}
