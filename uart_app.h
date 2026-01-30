#ifndef UART_APP_H
#define UART_APP_H

#include "bsp_system.h"
#include "usart.h"

void uart_proc(void);
void HAL_UART_TxCpltCallback(UART_HandleTypeDef *huart);
#endif