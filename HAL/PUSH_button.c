#include "GPIO.h"

void BUTTON_en(uint8_t port, uint8_t bit)
{
	GPIO_dir(port,bit,INPUT);
}

uint8_t BUTTON_status(uint8_t port, uint8_t bit)
{
	uint8_t value = GPIO_read(port,bit); 
	return value;
}