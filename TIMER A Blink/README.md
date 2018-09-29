# Chris Amling
# Lab 2
# Timer A Blink
September 28, 2018
TIMER A Blink
The objective for this part of the lab was to use Timer A to control the blink rate of two LEDs. This is almost identical to the functionality of the multiple blink, except a timer is used to control the blink rate rather than if statements. This exercise was designed to interface with the Timer A peripheral and gain a better understanding of how to configure it.
The button interrupt part of the lab entailed improving the “Multiple Blink” part of lab 1 to use a timer to control the blink rate of two LEDs. The two boards used for this part of the lab are the MSP430G2553, and the MSP430FR2311.


MSP430G2553

The LEDs on the board being used are located at P1.0 and P1.6. This code used the msp430.h library.

MSP430FR2311

The LEDs on the board being used are located at P1.0 and P2.0. This code used the msp430.h library.
