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
  uint8_t out4;
   float left_speed;
   float right_speed;
    /* data */
} follow;
void FOLLOW_Start(follow* state);


#endif // FOLLOW_H