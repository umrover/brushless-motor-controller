/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2023 STMicroelectronics.
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
#include "stm32g4xx_hal.h"

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
#define CURR_1_Pin GPIO_PIN_0
#define CURR_1_GPIO_Port GPIOC
#define CURR_2_Pin GPIO_PIN_1
#define CURR_2_GPIO_Port GPIOC
#define CURR_3_Pin GPIO_PIN_2
#define CURR_3_GPIO_Port GPIOC
#define ADC_TEMP_Pin GPIO_PIN_3
#define ADC_TEMP_GPIO_Port GPIOC
#define VOLTAGE_1_Pin GPIO_PIN_0
#define VOLTAGE_1_GPIO_Port GPIOA
#define VOLTAGE_2_Pin GPIO_PIN_1
#define VOLTAGE_2_GPIO_Port GPIOA
#define VOLTAGE_3_Pin GPIO_PIN_2
#define VOLTAGE_3_GPIO_Port GPIOA
#define DRIVER_VOLTAGE_Pin GPIO_PIN_3
#define DRIVER_VOLTAGE_GPIO_Port GPIOA
#define MOTOR_TEMP_Pin GPIO_PIN_5
#define MOTOR_TEMP_GPIO_Port GPIOC
#define HALL1_INPUT_Pin GPIO_PIN_6
#define HALL1_INPUT_GPIO_Port GPIOC
#define HALL_2_INPUT_Pin GPIO_PIN_7
#define HALL_2_INPUT_GPIO_Port GPIOC
#define HALL_3_INPUT_Pin GPIO_PIN_8
#define HALL_3_INPUT_GPIO_Port GPIOC
#define CAN_SHDN_Pin GPIO_PIN_8
#define CAN_SHDN_GPIO_Port GPIOA
#define H1_OUTPUT_Pin GPIO_PIN_0
#define H1_OUTPUT_GPIO_Port GPIOD
#define H2_OUTPUT_Pin GPIO_PIN_1
#define H2_OUTPUT_GPIO_Port GPIOD
#define H3_OUTPUT_Pin GPIO_PIN_2
#define H3_OUTPUT_GPIO_Port GPIOD

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
