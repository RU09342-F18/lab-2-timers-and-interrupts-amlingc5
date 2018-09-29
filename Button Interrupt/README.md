# Chris Amling
# Lab 2
# Button Interrupt
September 28, 2018


The button interrupt part of the lab entailed improving the “Button Blink” part of lab 1 to use interrupts instead of polling as a way to use a button to control a led.  The two boards used for this part of the lab are the MSP430G2553, and the MSP432P401R.


MSP430G2553

The LED on the board being used is located at P1.0. The code enables the button at P1.3 to toggle on and off the LED. This code used the msp430.h library.


MSP432P401R

The LED on the board being used is located at P1.0. The code enables the button at P1.1 to toggle on and off the LED. This code used the msp432.h library. This code was copied from the TI Resource Center.
