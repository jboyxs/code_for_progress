#ifndef ENCODER_H_
#define ENCODER_H_
#include "main.h"
#include "stm32f1xx_hal.h"
#include "tim.h"
typedef struct 
{
    uint8_t ENCODERL_count;
    uint8_t ENCODERR_count;
    float left_speed;
    float right_speed;
} ENCODER;
void ENCODER_init(void);
#endif /*ENCODER_H_*/