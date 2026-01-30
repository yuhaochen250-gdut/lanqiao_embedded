#include "uart_app.h"

ringbuffer_t usart_rb;
uint8_t usart_read_buffer[128];

// UART_HandleTypeDef 是HAL库定义的结构体类型
// 用于管理和操作UART外设的所有相关信息

//void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)//中断回调函数
//{
//    // 检查是否是串口1触发的中断
//    if(huart -> Instance == USART1)
//    {
//        // huart->Instance 获取句柄中存储的地址
//        // USART1 是串口1的基地址常量
//        // 比较两者是否相等
//        uart_rx_ticks = uwTick;//时间戳更新
//        uart_rx_index++;
//        HAL_UART_Receive_IT(&huart1,&uart_rx_buffer[uart_rx_index],1);
//        //启动非阻塞（中断）模式的串口接收。
//        //设置好接收后立即返回，数据到来时通过中断自动接收。
////        printf("test");
//    }
//}

void HAL_UARTEx_RxEventCallback(UART_HandleTypeDef *huart,uint16_t size)
{
    //空闲状态时进来
//    printf("dma data:%s\n",uart_rx_dma_buffer);
    if(!ringbuffer_is_full(&usart_rb))//判断是否已满
    {
        ringbuffer_write(&usart_rb,uart_rx_dma_buffer,size);//没有满，可以写入
    }
    memset(uart_rx_dma_buffer,0,sizeof(uart_rx_dma_buffer));
}


void uart_proc(void)//解析函数
{
//    //UART接收数据处理函数
//    //在主循环中被周期性调用，用于检测和处理完整的串口数据帧
//    if(uart_rx_index == 0) return;//如果没有接收到任何数据，立即返回

//    if(uwTick - uart_rx_ticks > 100)//触发超时，认为一帧数据接收完成
//    {
//        printf("uart data:%s",uart_rx_buffer);//输出接收到的数据
//        memset(uart_rx_buffer,0,uart_rx_index);//清空已使用的缓冲区部分
//        uart_rx_index = 0;//重置接收计数器
//        huart1.pRxBuffPtr = uart_rx_buffer;
//    }
    if(ringbuffer_is_empty(&usart_rb)) return;
    ringbuffer_read(&usart_rb,usart_read_buffer,usart_rb.itemCount);
    printf("ringbuffer data:%s\n",usart_read_buffer);
    memset(usart_read_buffer,0,sizeof(uint8_t) * 128);
}

