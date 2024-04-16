/*
 * DIO Driver
 *
 *  Created on: Dec 15, 2023
 *      Author: Nouroo
 */

/*____Guard file_____*/

#ifndef DIO_INTERFACE_H
#define DIO_INTERFACE_H


#define OUTPUT   1
#define INPUT   0

#define HIGH   1
#define LOW   0

typedef enum
{
	DIO_NOK,
	DIO_OK

}DIO_ErroeState;

/*____DIO PORTS_____*/
#define DIO_PORTA   0
#define DIO_PORTB   1
#define DIO_PORTC   2
#define DIO_PORTD   3

/*____DIO PINS_____*/
#define DIO_PIN0   0
#define DIO_PIN1   1
#define DIO_PIN2   2
#define DIO_PIN3   3
#define DIO_PIN4   4
#define DIO_PIN5   5
#define DIO_PIN6   6
#define DIO_PIN7   7

#define DIO_ALL_PORT   0xff


/*____PIN FUNCTIONS_____*/
// Function to set the direction of a specific pin as input
void MDIO_vSetPinDir(u8 copy_u8Port , u8 copy_u8Pin , u8 copy_u8Dir);
// Function to set the value (HIGH/LOW) of a specific output pin
void MDIO_vSetPinValue(u8 copy_u8Port, u8 copy_u8Pin, u8 copy_u8Value);

// Function to read the value (HIGH/LOW) of a specific input pin
u8 MDIO_u8GetPinValue(u8 copy_u8Port, u8 copy_u8Pin);


/*____PORT FUNCTIONS_____*/
// function to configure the direction of multiple pins at once
void MDIO_vSetPortDir(u8 copy_u8Port, u8 copy_u8Dir);

//function to write values to multiple output pins at once
void MDIO_vSetPortValue(u8 copy_u8Port, u8 copy_u8Value);

// function to read values from multiple input pins at once
u8 MDIO_u8GetPortValue(u8 copy_u8Port);


#endif
