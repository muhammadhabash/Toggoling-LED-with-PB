#include "PUSH_button.h"

void BUTTON_en(uint8_t u8_port, uint8_t u8_bit)
{
	GPIO_dir(u8_port,u8_bit,INPUT);
}

uint8_t BUTTON_status(uint8_t u8_port, uint8_t u8_bit)
{
	uint8_t u8_value = GPIO_read(u8_port,u8_bit); 
	return u8_value;
}