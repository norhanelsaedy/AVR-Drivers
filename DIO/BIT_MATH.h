/*
 * DIO Driver
 *
 *  Created on: Dec 15, 2023
 *      Author: Nouroo
 */

/*____Guard file_____*/

#ifndef BIT_MATH_H
#define BIT_MATH_H

#define  READ_BIT(reg,bit)  ((reg>>bit)&1)
#define  READ_BIT2(reg,bit)  (reg&(1<<BIT))
#define  SET_BIT(reg,bit)   (reg=reg|(1<<bit))
#define  CLR_BIT(reg,bit)   (reg=reg&(~(1<<bit)))
#define  TOG_BIT(reg,bit)   (reg=reg^(1<<bit))


#endif
