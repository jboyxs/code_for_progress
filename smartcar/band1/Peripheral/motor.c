#include "motor.h"
void MOTOR_init(void)
{
    HAL_TIM_PWM_Start(&htim2,TIM_CHANNEL_1);
    HAL_TIM_PWM_Start(&htim2,TIM_CHANNEL_2);
    HAL_TIM_PWM_Start(&htim2,TIM_CHANNEL_3);
    HAL_TIM_PWM_Start(&htim2,TIM_CHANNEL_4);
}

void MOTOR_Speed(int8_t left_speed, int8_t right_speed)
{
    if(left_speed>0&&right_speed>0)
    {
        AIN1L_HIGH();
        AIN2L_LOW();
        BIN1L_HIGH();
        BIN2L_LOW();
        __HAL_TIM_SetCompare(&htim2,TIM_CHANNEL_1,left_speed);
       
        __HAL_TIM_SetCompare(&htim2,TIM_CHANNEL_2,left_speed);
        __HAL_TIM_SetCompare(&htim2,TIM_CHANNEL_3,right_speed);
        __HAL_TIM_SetCompare(&htim2,TIM_CHANNEL_4,right_speed);
    }
    if(left_speed<0&&right_speed<0)
    {
        AIN1L_LOW();
        AIN2L_HIGH();
        BIN1L_LOW();
        BIN2L_HIGH();
        __HAL_TIM_SetCompare(&htim2,TIM_CHANNEL_1,-left_speed);
        __HAL_TIM_SetCompare(&htim2,TIM_CHANNEL_2,-left_speed);
        __HAL_TIM_SetCompare(&htim2,TIM_CHANNEL_3,-right_speed);
        __HAL_TIM_SetCompare(&htim2,TIM_CHANNEL_4,-right_speed);
    }
    if(left_speed>0&&right_speed<0)
    {
        AIN1L_HIGH();
        AIN2L_LOW();
        BIN1L_LOW();
        BIN2L_HIGH();
        __HAL_TIM_SetCompare(&htim2,TIM_CHANNEL_1,left_speed);
        __HAL_TIM_SetCompare(&htim2,TIM_CHANNEL_2,left_speed);
        __HAL_TIM_SetCompare(&htim2,TIM_CHANNEL_3,-right_speed);
        __HAL_TIM_SetCompare(&htim2,TIM_CHANNEL_4,-right_speed);
    }
    if(left_speed<0&&right_speed>0)
    {
        AIN1L_LOW();
        AIN2L_HIGH();
        BIN1L_HIGH();
        BIN2L_LOW();
        __HAL_TIM_SetCompare(&htim2,TIM_CHANNEL_1,-left_speed);
        __HAL_TIM_SetCompare(&htim2,TIM_CHANNEL_2,-left_speed);
        __HAL_TIM_SetCompare(&htim2,TIM_CHANNEL_3,right_speed);
        __HAL_TIM_SetCompare(&htim2,TIM_CHANNEL_4,right_speed);
    }

}