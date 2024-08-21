#include "range.h"



/********************************************************************************************
 *设置变量
 *distances:超声波所测距离
 *t        :回响信号脉冲持续时间
 *high_time[0]:回响信号脉冲上升沿发生时间
 *high_time[1]:回响信号脉冲下降沿发生时间
 *c_values :标志值，用于定时器输入捕获回调函数

 ********************************************************************************************/
float distances;
uint32_t t=0;
uint32_t high_time[2]={0};
uint8_t c_values=0;
uint8_t d_values=0;
uint8_t test=0;
/********************************************************************************************
 * 定时器中断回调函数 void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
 *
 * 说明:
 * 因为SR04每次发送超声波的时间间隔要大于60ms，
 * 故通过Cube MX 已经将TIM3设置为100ms的定时器，每隔100ms才执行一次这个定时器中断回调函数
 * 即每隔100ms发送一个20us的高电平脉冲，同时开启定时器4输入捕获并设置为上升沿捕获
 *
 ********************************************************************************************/
/*void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{


	if(htim==&htim6)                      //判断是否为TIM3溢出中断
	{
		TRIG_OFF;                         //先将超声波模块SR04的发送端TRIG拉低
		TRIG_ON;                          //再将超声波模块SR04的发送端TRIG拉高，并且持续20ms后再拉低
		delay_us(20);
		TRIG_OFF;
		__HAL_TIM_SET_CAPTUREPOLARITY(&htim4,TIM_CHANNEL_1,TIM_ICPOLARITY_RISING);//设置为上升沿捕获
		HAL_TIM_IC_Start_IT(&htim4,TIM_CHANNEL_1);//开启定时器输入捕获
		//d_values=0;
		//test++;

	}
	if(htim==&htim7)
		{
			test++;
			measure.ENCODERL_count=__HAL_TIM_GET_COUNTER(&htim5);
			measure.ENCODERR_count=__HAL_TIM_GET_COUNTER(&htim3);
			__HAL_TIM_SET_COUNTER(&htim5,0);
			__HAL_TIM_SET_COUNTER(&htim3,0);
			measure.left_speed=(float)measure.ENCODERL_count*100/20/11/4;
			measure.right_speed=(float)measure.ENCODERR_count*100/20/11/4;
		}

}*/

/********************************************************************************************
 * 定时器输入捕获回调函数 void HAL_TIM_IC_CaptureCallback(TIM_HandleTypeDef *htim)
 *
 *说明:
 *ECHO接收回响信号脉冲，这个回调函数要被执行2次
 *这个回调函数在类似于一个分叉路口，上升沿捕获走路口0，下降沿捕获走路口1
 *
 ********************************************************************************************/
	void HAL_TIM_IC_CaptureCallback(TIM_HandleTypeDef *htim)
	{
		//test++;
		if(htim==&htim4)
		{//test++;
			switch(c_values)
			{//标志值c_values初始设定值为0，上升沿输入捕获，先执行回调函数执行case(0)中内容

			case(0): high_time[0]=HAL_TIM_ReadCapturedValue(&htim4,TIM_CHANNEL_1);//获取上升沿的捕获值，即接收的高电平开始时间
			         __HAL_TIM_SET_CAPTUREPOLARITY(&htim4,TIM_CHANNEL_1,TIM_ICPOLARITY_FALLING);//设置为下降沿捕获
			         c_values++;//标志值c_values值变为1，下次回调函数执行case(1)中内容
			         break;


			case(1): high_time[1]=HAL_TIM_ReadCapturedValue(&htim4,TIM_CHANNEL_1);//获取下降沿的捕获值，即接收的高电平结束时间
			         HAL_TIM_IC_Stop_IT(&htim4,TIM_CHANNEL_1); //关闭TIM4输入捕获
			         c_values=0;                 //标志值清零，用于下次输入捕获回调函数
			         __HAL_TIM_SET_COUNTER(&htim4,0);//TIM4计数值清零
				     t=high_time[1]-high_time[0];//下降沿捕获值-上升沿捕获值=回响信号高电平脉冲持续时间t
				     distances= t*0.017; //速度0.034cm/us,计算出的距离要除以2,distances的单位是cm
					 d_values=1;
			         break;
			default: break;
			}
		}
		
	}
float RANGE_AcquireData(void)
{
	{
	HAL_TIM_Base_Stop_IT (&htim6);
	float distance=0;
	HAL_TIM_Base_Start_IT (&htim6);
	if(d_values ==1)
	{
	distance =distances;
	}
	else
		{
			
			distance =distances;//while循环体似乎不能刚刚那么用
	  }
		return distance;
		HAL_TIM_Base_Stop_IT (&htim6 );
}
}
void RANGE_Alarm(float distance)
{
	if(distance<10)
	{
		OLED_ShowString(0,0,"too close",9,0);
	}
	else
	{
		OLED_ShowString(0,0,"safe     ",9,0);
	}
}
