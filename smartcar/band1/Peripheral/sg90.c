#include "sg90.h"
void SG90_init(void)
{
    HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_4);
    __HAL_TIM_SET_COMPARE(&htim1, TIM_CHANNEL_4,539);//初始化先将其放在中间位置
}
void SG90_middle(void)
{

    __HAL_TIM_SET_COMPARE(&htim1, TIM_CHANNEL_4, 539);
}
void SG90_left(void)//左还是右也要看具体的情况，指安装舵机的方式
{
    __HAL_TIM_SET_COMPARE(&htim1, TIM_CHANNEL_4,179);
}
void SG90_right(void)
{
    __HAL_TIM_SET_COMPARE(&htim1,TIM_CHANNEL_4,899);
}
