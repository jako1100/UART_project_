/*
 * keypad_input.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: COMPUTER SHOW
 */

#include"keypad_input.h"
#define BUTTON_DELAY 400

void get_keyPadInput(uint8 arr[],uint8 number_of_digits)
{
	sint8 i;
	uint8 key;

	for(i=0;i<number_of_digits;i++)
	{
		key = KeyPad_getPressedKey();
		LCD_goToRowColumn(0,10+i);
		LCD_intgerToString(key);
		_delay_ms(400);
	}
}
uint16 convertToNum(uint8 arr[],uint8 number_of_digits)
{
	uint16 num;
	if(number_of_digits == 3)
	{
		num = arr[0]*100 + arr[1]*10 + arr[2] * 1 ;
	}
	else if(number_of_digits == 2)
	{
		num = arr[0]*10 + arr[1]*1 ;
	}
	else if(number_of_digits == 1)
	{
		num = arr[0] ;
	}
	return num;
}
