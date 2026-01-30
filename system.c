#include "system.h"

void system_init(void)
{
	GPIOC -> ODR &= 0x00FF;
	
	GPIOC -> ODR |= 0xFF00;
	
	GPIOD -> BSRR |= 0x01 << 2;
	
	GPIOD -> BRR |= 0x01 << 2;
}
