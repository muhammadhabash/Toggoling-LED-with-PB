#include "ATMEGA32.h"
#include "BIT_manipulation.h"
#include "GPIO.h"
#include "LED.h"
#include "PUSH_button.h"
#include "Timers.h"

int main(void)
{
	LED_en(B,4);                            //Enables the LED and set it as an output
	BUTTON_en(B,2);                         //Enables the PB and set it as an input
    
	while (1) 
    {
		if(PRESSED == BUTTON_status(B,2))   //Poll on push button status
		{
			LED_toggle(B,4);                //Toggoling the led
			TIMER0_msdelay(500);            //This delay is used to avoid mechanical bouncing of push buttons
		}
    }
}

