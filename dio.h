/*
 * dio.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: COMPUTER SHOW
 */

#ifndef DIO_H_
#define DIO_H_

//typedef enum{NOK,OK}Std_Func_t;

#define MAX_NUM_OF_PINS		32

//#include <avr/io.h>
/*
#include"types.h"
#include"registers.h"
*/
#include "dio_cnfg.h"



#include<avr/io.h>

#define OK 1;
#define NOK 0;

uint8_t DIO_init (void);

uint8_t DIO_write (uint8_t port,uint8_t pin,uint8_t val);

uint8_t DIO_read (uint8_t port,uint8_t pin,uint8_t * Pval);


#endif /* DIO_H_ */
