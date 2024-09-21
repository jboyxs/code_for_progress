/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2024 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "dma.h"
#include "i2c.h"
#include "tim.h"
#include "usart.h"
#include "gpio.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "oled.h"
#include "range.h"//测距和避�?
#include "follow.h"//循迹
#include "motor.h"//速度pid
#include "encoder.h"
#include "stdio.h"
#include "redirect.h"
#include "pid.h"
#include "math.h"
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */
extern float distances;
extern  uint8_t c_values;
extern uint8_t test;
extern ENCODER measure;
extern PIDController motor_pid;
extern follow statu;//循迹函数的参数，里面有各个传感器的状�?
float left_setpoint;
float right_setpoint;
/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */
OLED_Init(&hi2c1);
  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_DMA_Init();
  MX_I2C1_Init();
  MX_TIM4_Init();
  MX_TIM6_Init();
  MX_TIM2_Init();
  MX_TIM3_Init();
  MX_TIM5_Init();
  MX_TIM7_Init();
  MX_USART1_UART_Init();
  MX_TIM1_Init();
  /* USER CODE BEGIN 2 */
OLED_Clear();
OLED_Display_On();
HAL_TIM_Base_Start_IT(&htim6);//测距的时�?
MOTOR_init();
ENCODER_init();
SG90_init();
PID_init();//先调节P参数
//left_setpoint=5;
//right_setpoint=5;
//OLED_ShowString(0,6,"test",4,0);
//OLED_ShowString(0,0,"Distance: ",9,0);
  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
    //OLED_Showdecimal(12,0,distances,2,2,16,0);
    //OLED_Showdecimal(0,4,RANGE_AcquireData(),2,2,16,0);
    //OLED_ShowNum(7,6,test,5,16,0);
    //RANGE_Alarm(RANGE_AcquireData());
    //OLED_Showdecimal(60,6,measure.left_speed,2,2,16,0);
    //__HAL_TIM_SET_COMPARE(&htim2,TIM_CHANNEL_3,500);
    //__HAL_TIM_SET_COMPARE(&htim2,TIM_CHANNEL_4,500);
   // printf("%f\n",measure.left_speed);
    //printf("%f\n",measure.left_speed);
    //RANGE_avoid();
    FOLLOW_Start(&statu);
    //SG90_right();
   //printf("%f\n",motor_pid.out);
    //printf("%d\n",test);//放在while循环中会对时序产生的影响比较�??
    //RANGE_avoid();
    //FOLLOW_Start(&statu);
    //HAL_Delay(1000);
   // printf("%d\n",test);
    //HAL_UART_Transmit_DMA(&huart1,(uint8_t*)&distances,1);
//float t1=0,t2=0;
//t1 += 0.1;
//t2 += 0.5;
//printf("simples:%f, %f\n", sin(t1), sin(t2)); 		
//HAL_Delay(100);
  }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  RCC_OscInitStruct.HSEPredivValue = RCC_HSE_PREDIV_DIV1;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLMUL = RCC_PLL_MUL9;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV2;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_2) != HAL_OK)
  {
    Error_Handler();
  }
}

/* USER CODE BEGIN 4 */
//中断回调函数
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{


	if(htim==&htim6)                      //判断是否为TIM3溢出中断
	{
		TRIG_OFF;                         //先将超声波模块SR04的发送端TRIG拉低
		TRIG_ON;                          //再将超声波模块SR04的发送端TRIG拉高，并且持�????20ms后再拉低
		delay_us(20);
		TRIG_OFF;
		__HAL_TIM_SET_CAPTUREPOLARITY(&htim4,TIM_CHANNEL_1,TIM_ICPOLARITY_RISING);//设置为上升沿捕获
		HAL_TIM_IC_Start_IT(&htim4,TIM_CHANNEL_1);//�????启定时器输入捕获
		//d_values=0;
		//test++;

	}
	if(htim==&htim7)
		{
			//test++;
     // HAL_UART_Transmit_DMA(&huart1,(uint8_t*)&distances,1);//无法在串口调试助手中显示�??10进制，只能显示为16进制
      //printf("%f\n",distances);//会对时序产生很大的影�??
      //REDIRECT_printf("hello world\n");//感觉还是不可
			measure.ENCODERL_count=(short)__HAL_TIM_GET_COUNTER(&htim5);
			measure.ENCODERR_count=(short)__HAL_TIM_GET_COUNTER(&htim3);
      measure.ENCODERR_count=-measure.ENCODERR_count;
			__HAL_TIM_SET_COUNTER(&htim5,0);
			__HAL_TIM_SET_COUNTER(&htim3,0);
			measure.left_speed=(float)measure.ENCODERL_count*100/20/11/4;
			measure.right_speed=(float)measure.ENCODERR_count*100/20/11/4;
      //位置PID
     // test++;
      //MOTOR_Speed(0,800);
      MOTOR_Speed((int )PID_update(&motor_pid,left_setpoint,measure.left_speed),(int)PID_update(&motor_pid,right_setpoint,measure.right_speed));
		}

}
int fputc(int ch,FILE *f)
{
   //HAL_UART_Transmit_DMA(&huart1,(uint8_t *)&ch,1);
  HAL_UART_Transmit(&huart1,(uint8_t *)&ch,1,0xFFFF);
  return ch;
}

/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */
