/*
 * switch.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: COMPUTER SHOW
 */

#ifndef SWITCH_H_
#define SWITCH_H_

#define SWITCH1 0
#define SWITCH2 1

#include<avr/io.h>
#include<avr/interrupt.h>
#include<avr/delay.h>
#include"dio.h"

extern volatile uint8_t increase_value;

#define NULL_PTR ((void*)0)

#define ONE 1
#define ZERO 0

#define OK 1
#define NOK 0

void extInt_setCallBack(void(*a_ptr)(void));


/*uint8_t switches_init(void);
uint8_t getSwitchState(uint8_t switch_id,uint8_t * result);*/

#endif /* SWITCH_H_ */
