#include "Timers.h"

volatile uint32_t counts = 0;                   //Denotes the number of overflows in timer 0

void __vector_11(void) __attribute__((signal)); //Overflow interrupt for timer 0
void __vector_11(void)
{
	counts++;                                   //This variable increases with every overflow occurs in timer 0 
}	                                            //because the required mseconds delay consists of multiple numbers of overflows

void OVI0_init(void)
{
	BIT_SET(TIMSK_R,0);
	BIT_SET(STATUS_R,7);                        //Enabling Global Interrupt in status registers
}

void OCI0_init(void)
{
	BIT_SET(TIMSK_R,1);
	BIT_SET(STATUS_R,7);
}

void OVI2_init(void)
{
	BIT_SET(TIMSK_R,6);
	BIT_SET(STATUS_R,7);
}

void OCI2_init(void)
{
	BIT_SET(TIMSK_R,7);
	BIT_SET(STATUS_R,7);
}

void TIMER0_msdelay(uint16_t mseconds)
{	
	volatile uint32_t ticks;
	volatile uint16_t remainder;
	ticks     = ( ( mseconds / 0.001 ) / 255 );
	remainder = ((mseconds / 0.001) - ( ticks * 255 ));  //Calculating the remaining fraction of clock cycles
	OVI0_init();                                         //Enabling system interrupt and flag for overflow int timer 0
	TIMER0_start(8);                                     //Prescaler of one that yields 8MHz frequency
	while (counts < ticks)
	{
		//Stay here till reaching the overflow counts that corresponds to the required delay
	}
	TIMER0_CNT_R = (255-remainder);                      //Compensation of ticks remaining fraction to increase accuracy
	TIMER0_stop();                                       //Stop timer after delay
	counts = 0;                                          //Reset overflows counter
}

void TIMER0_start(uint16_t u16_prescale)
{
	if (1 == u16_prescale)
	{
		TIMER0_CTL_R |= (1<<CS00);
	}
	else if (8 == u16_prescale)
	{
		TIMER0_CTL_R |= (1<<CS01);	
	}
	else if (32 == u16_prescale)
	{
		TIMER0_CTL_R |= (1<<CS01) | (1<<CS00);
	}
	else if (64 == u16_prescale)
	{
		TIMER0_CTL_R |= (1<<CS02);
	}
	else if (128 == u16_prescale)
	{
		TIMER0_CTL_R |= (1<<CS02) | (1<<CS00);
	}
	else if (256 == u16_prescale)
	{
		TIMER0_CTL_R |= (1<<CS02) | (1<<CS01);
	}
	else if (1024 == u16_prescale)
	{
		TIMER0_CTL_R |= (1<<CS02) | (1<<CS01) | (1<<CS00);
	}
}

void TIMER0_stop(void)
{
	TIMER0_CTL_R = 0;
}

void TIMER2_start(uint16_t u16_prescale)
{
	if (1 == u16_prescale)
	{
		TIMER2_CTL_R |= (1<<CS00);
	}
	else if (8 == u16_prescale)
	{
		TIMER2_CTL_R |= (1<<CS01);
	}
	else if (32 == u16_prescale)
	{
		TIMER2_CTL_R |= (1<<CS01) | (1<<CS00);
	}
	else if (64 == u16_prescale)
	{
		TIMER2_CTL_R |= (1<<CS02);
	}
	else if (128 == u16_prescale)
	{
		TIMER2_CTL_R |= (1<<CS02) | (1<<CS00);
	}
	else if (256 == u16_prescale)
	{
		TIMER2_CTL_R |= (1<<CS02) | (1<<CS01);
	}
	else if (1024 == u16_prescale)
	{
		TIMER2_CTL_R |= (1<<CS02) | (1<<CS01) | (1<<CS00);
	}
}

void TIMER2_stop(void)
{
	TIMER2_CTL_R = 0;
}