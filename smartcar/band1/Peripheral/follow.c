#include "follow.h"

follow statu;
void FOLLOW_Start(follow *state)
{
    state->out0=HAL_GPIO_ReadPin(OUT1_GPIO_Port,OUT0_Pin);
    state->out1=HAL_GPIO_ReadPin(OUT1_GPIO_Port,OUT1_Pin);
    state->out2=HAL_GPIO_ReadPin(OUT1_GPIO_Port,OUT2_Pin);
    state->out3=HAL_GPIO_ReadPin(OUT1_GPIO_Port,OUT3_Pin);
state->out4=HAL_GPIO_ReadPin(OUT1_GPIO_Port,OUT4_Pin);
    //以下就是根据传感器的状态给速度了
   //if(state.out0)
}