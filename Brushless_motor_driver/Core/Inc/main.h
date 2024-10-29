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

void HAL_TIM_MspPostInit(TIM_HandleTypeDef *htim);

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define HALL_STATE_1_Pin GPIO_PIN_2
#define HALL_STATE_1_GPIO_Port GPIOE
#define CURR_A_Pin GPIO_PIN_0
#define CURR_A_GPIO_Port GPIOC
#define CURR_B_Pin GPIO_PIN_1
#define CURR_B_GPIO_Port GPIOC
#define CURR_C_Pin GPIO_PIN_2
#define CURR_C_GPIO_Port GPIOC
#define ADC_TEMP_Pin GPIO_PIN_3
#define ADC_TEMP_GPIO_Port GPIOC
#define SHA_V_Pin GPIO_PIN_0
#define SHA_V_GPIO_Port GPIOA
#define SHB_V_Pin GPIO_PIN_1
#define SHB_V_GPIO_Port GPIOA
#define SHC_V_Pin GPIO_PIN_2
#define SHC_V_GPIO_Port GPIOA
#define SOURCE_VOLTAGE_Pin GPIO_PIN_3
#define SOURCE_VOLTAGE_GPIO_Port GPIOA
#define SPI1_CS_Pin GPIO_PIN_4
#define SPI1_CS_GPIO_Port GPIOA
#define MOTOR_TEMP_Pin GPIO_PIN_5
#define MOTOR_TEMP_GPIO_Port GPIOC
#define HALL_STATE_2_Pin GPIO_PIN_9
#define HALL_STATE_2_GPIO_Port GPIOE
#define CAN_SHDN_Pin GPIO_PIN_15
#define CAN_SHDN_GPIO_Port GPIOD
#define HALL_STATE_3_Pin GPIO_PIN_6
#define HALL_STATE_3_GPIO_Port GPIOC
#define SPI3_CS_Pin GPIO_PIN_15
#define SPI3_CS_GPIO_Port GPIOA
#define L1_Pin GPIO_PIN_0
#define L1_GPIO_Port GPIOD
#define H1_Pin GPIO_PIN_1
#define H1_GPIO_Port GPIOD
#define nFAULT_Pin GPIO_PIN_7
#define nFAULT_GPIO_Port GPIOD
#define L2_Pin GPIO_PIN_3
#define L2_GPIO_Port GPIOB
#define H2_Pin GPIO_PIN_6
#define H2_GPIO_Port GPIOB
#define L3_Pin GPIO_PIN_0
#define L3_GPIO_Port GPIOE
#define H3_Pin GPIO_PIN_1
#define H3_GPIO_Port GPIOE

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
