#include "ux_printf.h"
#include "stm32f4xx_hal.h"
#include <stdio.h>

//可拓展
extern UART_HandleTypeDef huart3;  // 引用 UART3 的句柄

int u3_printf(const char *fmt, ...)
{
    char buf[256];  // 临时缓冲区存放格式化后的字符串
    va_list args;
    va_start(args, fmt);
    int len = vsnprintf(buf, sizeof(buf), fmt, args);  // 使用 vsnprintf 格式化输出
    va_end(args);

    if (len > 0)
    {
        HAL_UART_Transmit(&huart3, (uint8_t*)buf, len, HAL_MAX_DELAY);  // 通过 UART3 发送数据
    }

    return len;
}



