#include "ux_printf.h"
#include "stm32f4xx_hal.h"
#include <stdio.h>

//����չ
extern UART_HandleTypeDef huart3;  // ���� UART3 �ľ��

int u3_printf(const char *fmt, ...)
{
    char buf[256];  // ��ʱ��������Ÿ�ʽ������ַ���
    va_list args;
    va_start(args, fmt);
    int len = vsnprintf(buf, sizeof(buf), fmt, args);  // ʹ�� vsnprintf ��ʽ�����
    va_end(args);

    if (len > 0)
    {
        HAL_UART_Transmit(&huart3, (uint8_t*)buf, len, HAL_MAX_DELAY);  // ͨ�� UART3 ��������
    }

    return len;
}



