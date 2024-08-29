#include "follow.h"

follow statu;
void FOLLOW_Start(follow *state)
{
    state->out0=HAL_GPIO_ReadPin(OUT1_GPIO_Port,OUT0_Pin);
    state->out1=HAL_GPIO_ReadPin(OUT1_GPIO_Port,OUT1_Pin);
    state->out2=HAL_GPIO_ReadPin(OUT1_GPIO_Port,OUT2_Pin);
    state->out3=HAL_GPIO_ReadPin(OUT1_GPIO_Port,OUT3_Pin);
    //state->out4=HAL_GPIO_ReadPin(OUT1_GPIO_Port,OUT4_Pin);
    //以下就是根据传感器的状态给速度了
    //先抄一下网上的四路循迹
   if(!state->out0&&state->out1&&state->out2&&!state->out3)
   {
    //标准的直行，左右速度的值具体还要改
    //state->left_speed=100;
    //state->right_speed=100; 
    state->nowstate=0;
   }
    else if(!state->out0&&!state->out1&&state->out2&&!state->out3)
    {
        //右小转，左右速度的值具体还要改
        //state->left_speed=100;
        //state->right_speed=50;
        state->nowstate=1;
    }
    else if(!state->out0&&!state->out1&&!state->out2&&state->out3)
    {
        //右大转，左右速度的值具体还要改
        //state->left_speed=;
        //state->right_speed=;
        state->nowstate=2;
    }
    else if(!state->out0&&state->out1&&!state->out2&&!state->out3)
    {
        //左小转，左右速度的值具体还要改
        //state->left_speed=50;
        //state->right_speed=100;
        state->nowstate=3;
    }
    else if(state->out0&&!state->out1&&!state->out2&&!state->out3)
    {
        //左大转，左右速度的值具体还要改
        //state->left_speed=50;
        //state->right_speed=50;
        state->nowstate=4;
    }
    if(!state->out0&&!state->out1&&state->out2&&!state->out3)
    {
        if(state->laststate==1)
        {
            //上一个状态是右小转
            //右小中转，左右速度的值具体还要改
            //state->left_speed=100;
            //state->right_speed=50;
            state->nowstate=5;
        }
        else if(state->laststate==3)
        {
            //上一个状态是左小转
            //左小中转，左右速度的值具体还要改
            //state->left_speed=50;
            //state->right_speed=100;
            state->nowstate=6;
        }
    }
   state->laststate=state->nowstate;
   
}