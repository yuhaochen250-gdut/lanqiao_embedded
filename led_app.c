#include "led_app.h"

void led_disp(uint8_t *ucLed) //传入数组地址
{
    //记录当前LED状态的临时变量
    uint8_t temp = 0x00;
    static uint8_t temp_old = 0xff;//static修饰，不会导致每次进入函数的时候都会刷新一次

    for (int i = 0;i < 8;i++)
    {
        temp |= (ucLed[i] << (7-i) );//第零个灯即为最左边的灯
		}
			
    if(temp != temp_old)//只有当前后两次led状态不一样的时候才更新
    {
        GPIOC -> ODR &= 0x00ff;//清空寄存器高八位的数据，保持低八位不变
        GPIOC -> ODR |= ~(temp << 8);//将temp放入寄存器
        GPIOD -> BSRR |= 0x01 << 2;//PD2改为高电平，开启
        GPIOD -> BRR |= 0x01 << 2; //PD2改为低电平，锁存
        temp_old = temp;
    }
		
}

uint8_t ucLed[8] = {1,0,1,0,0,1,0,1};

void led_proc(void)
{
    led_disp(ucLed);
}