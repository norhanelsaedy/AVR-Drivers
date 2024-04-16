
/*
 * DIO Driver
 *
 *  Created on: Dec 15, 2023
 *      Author: Nouroo
 */
#include "STD_types.h"
#include "BIT_MATH.h"
#include "DIO_int.h"
#include <util/delay.h>

int main ()

{
MDIO_vSetPortDir(DIO_PORTD,OUTPUT);
	while(1)
	{
	MDIO_vSetPinValue(DIO_PORTD,DIO_PIN1 , HIGH );
	_delay_ms(500);
	MDIO_vSetPinValue(DIO_PORTD,DIO_PIN1, LOW );
	_delay_ms(500);
	}
}
