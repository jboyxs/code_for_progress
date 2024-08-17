#include "follow.h"

follow statu;
void FOLLOW_Start(follow *state)
{
    state->out0=HAL_GPIO_ReadPin(OUT0_Pin,OUT0_GPIO_Port);
    state->out1=HAL_GPIO_ReadPin(OUT1_Pin,OUT1_GPIO_Port);
    state->out2=HAL_GPIO_ReadPin(OUT2_Pin,OUT2_GPIO_Port);
    state->out3=HAL_GPIO_ReadPin(OUT3_Pin,OUT3_GPIO_Port);
    state->out4=HAL_GPIO_ReadPin(OUT4_Pin,OUT4_GPIO_Port);
    //以下就是根据传感器的状态给速度了
    if(state.out0)
}