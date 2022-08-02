/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * File Name	: libjpeg.h
  * Description	: This file provides code for the configuration
  *               of the libjpeg instances.
 * @authors		: Conti Edoardo, Federici Lorenzo, Melnic Andrian
 * @course		: Sistemi Operativi Dedicati @ UNIVPM (2021/2022)
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2022 STMicroelectronics.
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
#ifndef __libjpeg_H
#define __libjpeg_H
#ifdef __cplusplus
 extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "jpeglib.h"

/* USER CODE BEGIN 0 */
//#include "utils.h"
/* USER CODE END 0 */

/* Global variables ---------------------------------------------------------*/

/* USER CODE BEGIN 1 */
/* USER CODE END 1 */

/* LIBJPEG init function */
void MX_LIBJPEG_Init(void);

/* USER CODE BEGIN 2 */
void StoreImageBuffer(uint8_t* buffer);
int ProcessJPG(uint8_t *filename);
/* USER CODE END 2 */

#ifdef __cplusplus
}
#endif
#endif /*__libjpeg_H */

/**
  * @}
  */

/**
  * @}
  */

