/*
 * Exercise3.c
 *
 * Created: 4/14/2015 3:17:07 PM
 *  Author: Mohamed Tarek
 */


#include "keypad_input.h"
#include "timer1.h"
#include "uart.h"
#include "dio.h"

#define SPEED 0x55
#define TIME 0x60

volatile uint8 key_speed;
uint8 key_time;
uint8 g_distance;

void decrement_by_one(void)
{
	uint8 input=0;
	DIO_read (PORT_B,PIN3,&input);
	if( !input  )
	{
		_delay_ms(30);
		if( !input )
		{
			key_speed--;
			//_delay_ms(200);
		}
	}
}
void increment_by_one(void)
{
	key_speed++;
}
int main(void)
{
	DIO_init();
	LCD_init(); /* initialize LCD */
	UART_init();
	sei();
	INT2_Init();
	LCD_clearScreen();
	timer1_ctc_init(7813);
	LCD_displayStringRowColumn(0,0,"speed ");
	key_speed = KeyPad_getPressedKey(); // get it only once
	while(1)
	{
		UART_sendByte(key_speed);
		LCD_goToRowColumn(0,10);
		extInt_setCallBack(increment_by_one);
		LCD_intgerToString(key_speed);
		decrement_by_one();
		LCD_displayString("         ");
	}
}
