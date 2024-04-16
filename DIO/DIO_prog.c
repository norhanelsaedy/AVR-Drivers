/*
 * DIO Driver
 *
 *  Created on: Dec 15, 2023
 *      Author: Nouroo
 */


/*____Library_____*/

#include "STD_types.h"   // Include standard data types header file
#include "BIT_MATH.h"    // Include bit manipulation header file

/*____Lower_Layer _____*/
/*____DIO_____*/
#include "DIO_int.h"     // Include DIO interface header file
#include "DIO_private.h" // Include DIO private header file (if exists)

// Function to set the direction of a specific pin as input or output
void MDIO_vSetPinDir(u8 copy_u8Port , u8 copy_u8Pin , u8 copy_u8Dir)
{
    if (copy_u8Dir == INPUT) {
        // Set as input
        switch (copy_u8Port) {
        case DIO_PORTA :
            CLR_BIT(DDRA, copy_u8Pin); // Clear the bit to set as input
            break;
        case DIO_PORTB:
            CLR_BIT(DDRB, copy_u8Pin);
            break;
        case DIO_PORTC:
            CLR_BIT(DDRC, copy_u8Pin);
            break;
        case DIO_PORTD:
            CLR_BIT(DDRD, copy_u8Pin);
            break;
        }
    } else {
        // Set as output
        switch (copy_u8Port) {
        case DIO_PORTA :
            SET_BIT(DDRA, copy_u8Pin); // Set the bit to set as output
            break;
        case DIO_PORTB:
            SET_BIT(DDRB, copy_u8Pin);
            break;
        case DIO_PORTC:
            SET_BIT(DDRC, copy_u8Pin);
            break;
        case DIO_PORTD:
            SET_BIT(DDRD, copy_u8Pin);
            break;
        }
    }
}

// Function to set the value (HIGH/LOW) of a specific output pin
void MDIO_vSetPinValue(u8 copy_u8Port, u8 copy_u8Pin, u8 copy_u8Value)
{
    // Set the value (HIGH/LOW) of the specified output pin
    if (copy_u8Value == LOW) {
        // Set pin to LOW
        switch (copy_u8Port) {
        case DIO_PORTA :
            CLR_BIT(PORTA, copy_u8Pin); // Clear the bit to set LOW
            break;
        case DIO_PORTB:
            CLR_BIT(PORTB, copy_u8Pin);
            break;
        case DIO_PORTC:
            CLR_BIT(PORTC, copy_u8Pin);
            break;
        case DIO_PORTD:
            CLR_BIT(PORTD, copy_u8Pin);
            break;
        }
    } else {
        // Set pin to HIGH
        switch (copy_u8Port) {
        case DIO_PORTA :
            SET_BIT(PORTA, copy_u8Pin); // Set the bit to set HIGH
            break;
        case DIO_PORTB:
            SET_BIT(PORTB, copy_u8Pin);
            break;
        case DIO_PORTC:
            SET_BIT(PORTC, copy_u8Pin);
            break;
        case DIO_PORTD:
            SET_BIT(PORTD, copy_u8Pin);
            break;
        }
    }
}

// Function to read the value (HIGH/LOW) of a specific input pin
u8 MDIO_u8GetPinValue(u8 copy_u8Port, u8 copy_u8Pin)
{
    u8 L_ReturnGet ;
    // Read the value (HIGH/LOW) of the specified input pin
    switch (copy_u8Port) {
    case DIO_PORTA :
        L_ReturnGet = READ_BIT(PINA, copy_u8Pin); // Read the specified pin
        break;
    case DIO_PORTB:
        L_ReturnGet = READ_BIT(PINB, copy_u8Pin);
        break;
    case DIO_PORTC:
        L_ReturnGet = READ_BIT(PINC, copy_u8Pin);
        break;
    case DIO_PORTD:
        L_ReturnGet = READ_BIT(PIND, copy_u8Pin);
        break;
    }
    return L_ReturnGet  ;
}

/*____PORT FUNCTIONS_____*/
// function to configure the direction of multiple pins at once
void MDIO_vSetPortDir(u8 copy_u8Port, u8 copy_u8Dir)
{
    if (copy_u8Dir == INPUT) {
        // Set all pins of the port as input
        switch (copy_u8Port) {
        case DIO_PORTA :
            DDRA = 0x00; // Set all bits to 0 to set as input
            break;
        case DIO_PORTB:
            DDRB = 0x00;
            break;
        case DIO_PORTC:
            DDRC = 0x00;
            break;
        case DIO_PORTD:
            DDRD = 0x00;
            break;
        }
    } else {
        // Set all pins of the port as output
        switch (copy_u8Port) {
        case DIO_PORTA :
            DDRA = 0xFF; // Set all bits to 1 to set as output
            break;
        case DIO_PORTB:
            DDRB = 0xFF;
            break;
        case DIO_PORTC:
            DDRC = 0xFF;
            break;
        case DIO_PORTD:
            DDRD = 0xFF;
            break;
        }
    }
}

// function to write values to multiple output pins at once
void MDIO_vSetPortValue(u8 copy_u8Port, u8 copy_u8Value)
{
    // Set the value (HIGH/LOW) of all pins of the specified port
    if (copy_u8Value == LOW) {
        // Set all pins of the port to LOW
        switch (copy_u8Port) {
        case DIO_PORTA :
            PORTA = 0x00; // Set all bits to 0 to set LOW
            break;
        case DIO_PORTB:
            PORTB = 0x00;
            break;
        case DIO_PORTC:
            PORTC = 0x00;
            break;
        case DIO_PORTD:
            PORTD = 0x00;
            break;
        }
    } else {
        // Set all pins of the port to HIGH
        switch (copy_u8Port) {
        case DIO_PORTA :
            PORTA = 0xFF; // Set all bits to 1 to set HIGH
            break;
        case DIO_PORTB:
            PORTB = 0xFF;
            break;
        case DIO_PORTC:
            PORTC = 0xFF;
            break;
        case DIO_PORTD:
            PORTD = 0xFF;
            break;
        }
    }
}

// function to read values from multiple input pins at once
u8 MDIO_u8GetPortValue(u8 copy_u8Port)
{
    u8 L_ReturnGet ;
    // Read the value of the specified input port
    switch (copy_u8Port) {
    case DIO_PORTA :
        L_ReturnGet = PINA; // Read the value of the port
        break;
    case DIO_PORTB:
        L_ReturnGet = PINB;
        break;
    case DIO_PORTC:
        L_ReturnGet = PINC;
        break;
    case DIO_PORTD:
        L_ReturnGet = PIND;
        break;
    }
    return L_ReturnGet  ;
}
