/*
 * switch.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: COMPUTER SHOW
 */

#include"switch.h"

#define ONE 1
#define ZERO 0

#define OK 1
#define NOK 0


volatile uint8_t increase_value = 0;
/* Global variables to hold the address of the call back function in the application */
static volatile void (*g_callBackPtr)(void) = NULL_PTR;

/* External INT2 Interrupt Service Routine */
ISR(INT2_vect)
{
	if(g_callBackPtr != NULL_PTR)//condition to make sure the callback is set
	{
		/* Call the Call Back function in the application after the edge is detected */
		(*g_callBackPtr)(); /* another method to call the function using pointer to function g_callBackPtr(); */
	}
}

/* External INT1 enable and configuration function */
void INT2_Init(void)
{
	SREG  &= ~(1<<7);      // Disable interrupts by clearing I-bit
	DDRB  &= (~(1<<PB2));  // Configure INT1/PD3 as input pin
	PORTB |= (1<<PB2);     // Enable the internal pull up resistor at PD3 pin
	GICR  |= (1<<INT2);    // Enable external interrupt pin INT1
	// Trigger INT1 with the falling edge
	MCUCSR &= ~(1<<ISC2);
	SREG  |= (1<<7);       // Enable interrupts by setting I-bit
}



void extInt_setCallBack(void(*a_ptr)(void))
{
	/* Save the address of the Call back function in a global variable */
	g_callBackPtr = a_ptr;
}
