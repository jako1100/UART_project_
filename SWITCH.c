
#include "SWITCH.h"

uint8_t GET_SWITCH_STATUS(uint8_t sw_num,uint8_t* status)
{
	uint8_t retval = OK;
	uint8_t val=1;
	switch (sw_num)
	{
	case sw_1:

		DIO_read(PORT_C,PIN4,&val);
		*status=val;
		break;

	case sw_2:

		DIO_read(PORT_B,PIN2,&val);
		*status=val;
		break;
	default :
		retval=NOK;

	}
	return retval;
}
