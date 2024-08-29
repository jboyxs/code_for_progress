#ifndef FOLLOW_H
#define FOLLOW_H

#include "main.h"
#include "stm32f1xx_hal.h"
typedef struct 
{
   uint8_t out0;
   uint8_t out1;
   uint8_t out2;
   uint8_t out3;
    //感觉上面四个状态量是不是存在数组里更合适一点
    uint8_t nowstate;
   uint8_t laststate;
   float left_speed;
   float right_speed;
    /* data */
} follow;
//到时候这个函数感觉是加到while循环里面合适还是加到控速pid的定时中断服务函数里面合适呢？
void FOLLOW_Start(follow* state);


#endif // FOLLOW_H