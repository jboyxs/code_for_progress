#ifndef RANGE_H_
#define RANGE_H_

#include "stm32f1xx_hal.h"
#include "main.h"
#include "delay.h"
#include "oled.h"//先做测试
#include "tim.h"
#include "sg90.h"//添加避障的程序

#define TRIG_ON HAL_GPIO_WritePin(TRIG_GPIO_Port,TRIG_Pin,GPIO_PIN_SET)
#define TRIG_OFF HAL_GPIO_WritePin(TRIG_GPIO_Port,TRIG_Pin,GPIO_PIN_RESET) 

/*extern TIM_HandleTypeDef htim4;
extern TIM_HandleTypeDef htim6;
extern TIM_HandleTypeDef htim7;
*/
void HAL_TIM_IC_CaptureCallback(TIM_HandleTypeDef *htim);    
//void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim);
float RANGE_AcquireData(void);
void RANGE_Alarm(float distance);//先做测试
void RANGE_avoid(void);

#endif /* RANGE_H_ */