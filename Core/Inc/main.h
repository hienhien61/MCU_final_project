/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2022 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
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

void HAL_TIM_MspPostInit(TIM_HandleTypeDef *htim);

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define B1_Pin GPIO_PIN_13
#define B1_GPIO_Port GPIOC
#define B1_EXTI_IRQn EXTI15_10_IRQn
#define BUTTON_PED_Pin GPIO_PIN_0
#define BUTTON_PED_GPIO_Port GPIOA
#define BUTTON_MODE_Pin GPIO_PIN_1
#define BUTTON_MODE_GPIO_Port GPIOA
#define USART_TX_Pin GPIO_PIN_2
#define USART_TX_GPIO_Port GPIOA
#define USART_RX_Pin GPIO_PIN_3
#define USART_RX_GPIO_Port GPIOA
#define BUTTON_SET_Pin GPIO_PIN_4
#define BUTTON_SET_GPIO_Port GPIOA
#define LD2_Pin GPIO_PIN_5
#define LD2_GPIO_Port GPIOA
#define BUTTON_INC_Pin GPIO_PIN_0
#define BUTTON_INC_GPIO_Port GPIOB
#define LED_RED_P2_Pin GPIO_PIN_2
#define LED_RED_P2_GPIO_Port GPIOB
#define LED_RED_P1_Pin GPIO_PIN_10
#define LED_RED_P1_GPIO_Port GPIOB
#define LED_GREEN_P2_Pin GPIO_PIN_9
#define LED_GREEN_P2_GPIO_Port GPIOC
#define LED_GREEN_P1_Pin GPIO_PIN_8
#define LED_GREEN_P1_GPIO_Port GPIOA
#define LED_RED_1_Pin GPIO_PIN_10
#define LED_RED_1_GPIO_Port GPIOA
#define TMS_Pin GPIO_PIN_13
#define TMS_GPIO_Port GPIOA
#define TCK_Pin GPIO_PIN_14
#define TCK_GPIO_Port GPIOA
#define LED_GREEN_1_Pin GPIO_PIN_3
#define LED_GREEN_1_GPIO_Port GPIOB
#define LED_GREEN_2_Pin GPIO_PIN_4
#define LED_GREEN_2_GPIO_Port GPIOB
#define LED_RED_2_Pin GPIO_PIN_5
#define LED_RED_2_GPIO_Port GPIOB
/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
