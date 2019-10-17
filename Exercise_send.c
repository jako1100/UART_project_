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
#include "SWITCH.h"

volatile uint8 key_speed;
uint8 key_time;
uint8 g_distance;


void speed_adjust(void)
{
	uint8 status_1=0,status_2=0;
	GET_SWITCH_STATUS(sw_1,&status_1);
	GET_SWITCH_STATUS(sw_2,&status_2);
	if (status_1)
	{
		key_speed++;
	}
	else if (status_2)
	{
		key_speed--;
	}
}

int main(void)
{
	DIO_init();
	LCD_init(); /* initialize LCD */
	UART_init();
	sei();
	LCD_clearScreen();
	timer1_ctc_init(7813);
	LCD_displayStringRowColumn(0,0,"speed ");
	key_speed = KeyPad_getPressedKey(); // get it only once
	while(1)
	{
		//UART_sendByte(key_speed);
		speed_adjust();

		_delay_ms(300);
	}
}
ISR(TIMER1_COMPA_vect)
{
	second++;
	UART_sendByte(key_speed);
	LCD_goToRowColumn(0,10);
	LCD_intgerToString(key_speed);
	LCD_displayString("         ");
	LCD_goToRowColumn(1,10);
	LCD_intgerToString(second);
	LCD_displayString("         ");
}
