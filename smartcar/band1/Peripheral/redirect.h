#ifndef _REDIRECT_H_
#define _REDIRECT_H_

#include "main.h"
#include "stm32f1xx_hal.h"
#include "stdio.h"
#include "stdarg.h"
#include "usart.h"

void REDIRECT_printf(const char *format,...);
#endif /*REDRECT_H_*/