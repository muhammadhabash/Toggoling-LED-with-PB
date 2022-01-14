#ifndef PUSH_BUTTON_H_
#define PUSH_BUTTON_H_

#include "GPIO.h"

 
/****************************************************************************/
/*                                                                          */
/*                            Macros for defining Button status             */
/*                                                                          */
/****************************************************************************/

#define PRESSED     (1)
#define NOT_PRESSED (0)

/****************************************************************************/
/*                                                                          */
/*                            Functions Prototypes                          */
/*                                                                          */
/****************************************************************************/

void BUTTON_en(uint8_t u8_port, uint8_t u8_bit);        //This function enables the given pin in the given port and sets it as input
uint8_t BUTTON_status(uint8_t u8_port, uint8_t u8_bit); //This function read the given pin value in the given port and returns it



#endif