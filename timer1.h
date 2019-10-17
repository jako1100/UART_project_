/*
 * timer1.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: COMPUTER SHOW
 */

#ifndef TIMER1_H_
#define TIMER1_H_

#include <avr/io.h>
#include <avr/interrupt.h>

extern volatile uint8_t second;
//extern volatile uint8_t second;
void timer1_ctc_init(uint16_t compare);
//void timer_start(void);
void timer_stop(void);

#endif /* TIMER1_H_ */
