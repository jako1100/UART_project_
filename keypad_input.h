/*
 * keypad_input.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: COMPUTER SHOW
 */

#ifndef KEYPAD_INPUT_H_
#define KEYPAD_INPUT_H_
#include"keypad.h"
#include"lcd.h"


void get_keyPadInput(uint8 arr[],uint8 number_of_digits);
uint16 convertToNum(uint8 arr[],uint8 number_of_digits);


#endif /* KEYPAD_INPUT_H_ */
