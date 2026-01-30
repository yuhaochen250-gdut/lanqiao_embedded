#ifndef LCD_APP_H
#define LCD_APP_H

#include "bsp_system.h"

void LcdSprintf(uint8_t Line,char *format,...);
void lcd_proc(void);
#endif