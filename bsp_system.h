#ifndef SYSTEM_H 
#define SYSTEM_H

#include "main.h"
#include "system.h"
#include "scheduler.h"
#include "led_app.h"
#include "key_app.h"

#include "lcd_app.h"
#include "stdio.h"
#include "stdarg.h"
#include "lcd.h"
#include "uart_app.h"
#include "string.h"
#include "ringbuffer.h"

#include "adc_app.h"

extern uint8_t ucLed[8];

extern uint16_t uart_rx_index;
extern uint32_t uart_rx_ticks;
extern uint8_t uart_rx_buffer[128];
extern uint8_t uart_rx_dma_buffer[128];


extern uint32_t dma_buffer[2][30];//同时存储两路数据
extern float adc_value[2];
#endif