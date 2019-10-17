/*
 * timer1.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: COMPUTER SHOW
 */

#include"timer1.h"

//extern volatile uint8_t second;
volatile uint8_t second;
ISR(TIMER1_COMPA_vect)
{
	second++;
}


void timer1_ctc_init(uint16_t compare)
{
		TCNT1 = 0;
		OCR1A = compare;
		TCCR1A |= ( (1<<FOC1A)|(1<<FOC1B) );
		TCCR1B |= ( (1<<WGM12)|(1<<CS12)|(1<<CS10) );
		TIMSK |= (1<<OCIE1A);
		second = 0;
}

void timer_stop(void)
{
	TCNT1 = 0;
	OCR1A = 0;
	TCCR1A = 0;
	TCCR1B = 0;
	TIMSK = 0;
}
