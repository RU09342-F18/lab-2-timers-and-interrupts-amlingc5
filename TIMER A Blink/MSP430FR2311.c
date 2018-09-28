#include <msp430.h>
void main(void)
{
    WDTCTL = WDTPW | WDTHOLD;   // Disable the watch dog timer
    PM5CTL0 &= ~LOCKLPM5;   //Disable the default high-impedance mode

    P1DIR |= BIT0;  // Set P1.0 to output
    P2DIR |= BIT0;  // Set P2.0 to output

    TB0CTL = TBSSEL_1 + MC_1 + ID_3;    // TimerB0 Control: ACLK, Up Mode, Internal Divider
    TB0CCTL0 = CCIE;    // Capture Compare Interrupt Enabled
    TB0CCR0= 1000;  // Set Register 

    TB1CTL = TBSSEL_1 + MC_1 + ID_3;    // TimerB1 Control: ACLK, Up Mode, Internal Divider
    TB1CCTL0 = CCIE;    // Capture Compare Interrupt Enabled
    TB1CCR0 = 5000; // Set Register 

    __enable_interrupt();   // Enables interrupt

    for(;;);    // COntinuous loop
}

#pragma vector = TIMER0_B0_VECTOR
__interrupt void TB0_ISR(void)
{
    P1OUT ^= BIT0;      // Toggle P1.0

#pragma vector = TIMER1_B0_VECTOR
__interrupt void TB1_ISR(void)
{
    P2OUT ^= BIT0;      // Toggle P2.0 
}
