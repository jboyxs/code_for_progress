/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
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

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f1xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define TRIG_Pin GPIO_PIN_0
#define TRIG_GPIO_Port GPIOC
#define OUT0_Pin GPIO_PIN_1
#define OUT0_GPIO_Port GPIOC
#define OUT1_Pin GPIO_PIN_2
#define OUT1_GPIO_Port GPIOC
#define OUT2_Pin GPIO_PIN_3
#define OUT2_GPIO_Port GPIOC
#define ENCODER1L_Pin GPIO_PIN_0
#define ENCODER1L_GPIO_Port GPIOA
#define ENCODER2L_Pin GPIO_PIN_1
#define ENCODER2L_GPIO_Port GPIOA
#define PWMAR_Pin GPIO_PIN_2
#define PWMAR_GPIO_Port GPIOA
#define PWMBR_Pin GPIO_PIN_3
#define PWMBR_GPIO_Port GPIOA
#define ENCODER1R_Pin GPIO_PIN_6
#define ENCODER1R_GPIO_Port GPIOA
#define ENCODER2R_Pin GPIO_PIN_7
#define ENCODER2R_GPIO_Port GPIOA
#define OUT3_Pin GPIO_PIN_4
#define OUT3_GPIO_Port GPIOC
#define OUT4_Pin GPIO_PIN_5
#define OUT4_GPIO_Port GPIOC
#define AIN1L_Pin GPIO_PIN_6
#define AIN1L_GPIO_Port GPIOC
#define AIN2L_Pin GPIO_PIN_7
#define AIN2L_GPIO_Port GPIOC
#define BIN1L_Pin GPIO_PIN_8
#define BIN1L_GPIO_Port GPIOC
#define BIN2L_Pin GPIO_PIN_9
#define BIN2L_GPIO_Port GPIOC
#define TX_Pin GPIO_PIN_9
#define TX_GPIO_Port GPIOA
#define RX_Pin GPIO_PIN_10
#define RX_GPIO_Port GPIOA
#define PWMAL_Pin GPIO_PIN_15
#define PWMAL_GPIO_Port GPIOA
#define AIN1R_Pin GPIO_PIN_10
#define AIN1R_GPIO_Port GPIOC
#define AIN2R_Pin GPIO_PIN_11
#define AIN2R_GPIO_Port GPIOC
#define BIN1R_Pin GPIO_PIN_12
#define BIN1R_GPIO_Port GPIOC
#define BIN2R_Pin GPIO_PIN_2
#define BIN2R_GPIO_Port GPIOD
#define PWMBL_Pin GPIO_PIN_3
#define PWMBL_GPIO_Port GPIOB
#define ECHO_Pin GPIO_PIN_6
#define ECHO_GPIO_Port GPIOB

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
