/*
 * Exercise3.c
 *
 * Created: 4/14/2015 3:17:07 PM
 *  Author: Mohamed Tarek
 */


#include "lcd.h"
#include "uart.h"
#include "SWITCH.h"
#include "timer1.h"
#include "dio.h"

uint8 flag=0;
uint8 val=0 ;
uint16 time=0 ;
uint8 measure_flag = 2 ;
uint32 Distance = 0 ;
uint8 reset = 2 ;

void measurment ()
{
	uint8 start_measurment = 0 ;
	uint8 stop_measurment = 0 ;
	GET_SWITCH_STATUS(sw_1,&start_measurment);
	GET_SWITCH_STATUS(sw_2,&stop_measurment);

	if(start_measurment==1)
	{
		measure_flag = 1 ;
	}
	else if (stop_measurment==1)
	{
		measure_flag = 0 ;
	}
}

void main (void)
{
	LCD_init();
	DIO_init();
	UART_init();
	LCD_clearScreen();
	SREG = (1 << 7);
	LCD_displayStringRowColumn(0,0,"Dis : ");
	LCD_displayStringRowColumn(0,12,"m");
	LCD_displayStringRowColumn(1,0,"Time : ");
	LCD_displayStringRowColumn(1,12,"sec");
	while(1)
	{
		measurment ();
	}
}

ISR(USART_RXC_vect)
{
	val = UDR;
	//LCD_clearScreen();
	//LCD_intgerToString(val);

	if (measure_flag==1)
	{
		if(reset==1)
		{
			time = 0 ;
			Distance = 0 ;
			reset= 0;
			LCD_clearScreen();
			LCD_displayStringRowColumn(0,0,"Dis : ");
			LCD_displayStringRowColumn(0,12,"m");
			LCD_displayStringRowColumn(1,0,"Time : ");
			LCD_displayStringRowColumn(1,12,"sec");
		}
		time++;
		Distance += val;
		LCD_goToRowColumn(0,8);
		LCD_intgerToString(Distance);
		LCD_goToRowColumn(1,8);
		LCD_intgerToString(time);
	}
	if(measure_flag==0)
	{
		LCD_clearScreen();
		LCD_displayStringRowColumn(0,0,"fnlDis: ");
		LCD_displayStringRowColumn(0,15,"m");
		LCD_displayStringRowColumn(1,0,"fnlTm : ");
		LCD_displayStringRowColumn(1,13,"sec");
		LCD_goToRowColumn(0,8);
		LCD_intgerToString(Distance);
		LCD_goToRowColumn(1,8);
		LCD_intgerToString(time);
		measure_flag=2;
		reset=1;
	}
}
