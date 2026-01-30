#include "lcd_app.h"

void LcdSprintf(uint8_t Line,char *format,...)
{
    char string[21];
    va_list arg;
    va_start(arg,format);
    vsprintf(string,format,arg);
    va_end(arg);
    LCD_DisplayStringLine(Line,(u8 *)string);
}


uint8_t count = 0;
void lcd_proc(void)
{
    
    LcdSprintf(Line0,"Test LCD App");
    LcdSprintf(Line1,"Count: %d",count);
    LcdSprintf(Line2,"%.2f--%.2f",adc_value[0],adc_value[1]);
    
    count++;

}