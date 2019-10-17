#ifndef SWITCH_H_
#define SWITCH_H_

#include "dio.h"

#define MAX_SWITCHES 3

uint8_t GET_SWITCH_STATUS(uint8_t sw_num,uint8_t* status);

#define sw_1 1
#define sw_2 2
#endif
