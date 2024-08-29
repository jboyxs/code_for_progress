#include "redirect.h"
unsigned char printf_temp[100];
void REDIRECT_printf(const char *format,...)
{
    unsigned short len;
    va_list args;
    va_start (args,format);
    len=vsnprintf((char*)printf_temp,sizeof(printf_temp)+1,(char*)format,args);
    va_end(args);
    HAL_UART_Transmit_DMA(&huart1,printf_temp,len);

}