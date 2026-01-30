#include "adc_app.h"

uint32_t dma_buffer[2][30];//同时存储两路数据
float adc_value[2];

void adc_proc(void)
{
    for(uint8_t i = 0;i < 30;i++)//循环30次
    {
        adc_value[0] += (float)dma_buffer[0][i];
        adc_value[1] += (float)dma_buffer[1][i];
    }
    
    adc_value[0] = adc_value[0] / 30 * 3.3f / 4096;
    adc_value[1] = adc_value[1] / 30 * 3.3f / 4096;
}

