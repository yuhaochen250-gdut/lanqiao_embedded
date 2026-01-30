#include "key_app.h"

uint8_t key_val = 0;//当前按键状态
uint8_t key_old = 0;//前一按键状态
uint8_t key_down = 0;//按下的按键
uint8_t key_up = 0;//释放的按键

uint8_t key_read(void)
{
    uint8_t temp = 0;
    
    if(HAL_GPIO_ReadPin(GPIOB,GPIO_PIN_0) == GPIO_PIN_RESET)
    {
        temp = 1;
    }
    if(HAL_GPIO_ReadPin(GPIOB,GPIO_PIN_1) == GPIO_PIN_RESET)
    {
        temp = 2;
    }
    if(HAL_GPIO_ReadPin(GPIOB,GPIO_PIN_2) == GPIO_PIN_RESET)
    {
        temp = 3;
    }
    if(HAL_GPIO_ReadPin(GPIOA,GPIO_PIN_0) == GPIO_PIN_RESET)
    {
        temp = 4;
    }

    return temp;
}

void key_proc(void)
{
    key_val = key_read();//读取当前按键状态

    //计算按下的按键（当前按下状态与前一状态异或，并与当前状态相与）
    key_down = key_val & (key_old ^ key_val);

    //计算释放的按键（当前未按下状态与前一状态异或，并与当前状态相与）
    key_up = ~key_val & (key_old ^ key_val);
   
    //更新前一按键状态
    key_old = key_val;

    if(key_down != 0)
    {
        ucLed[key_down] ^= 1;
    }
    
}
