/* USER CODE BEGIN Header */
/**
 ******************************************************************************
 * @file	: main.c
 * @brief	: Main program body
 * @authors	: Conti Edoardo, Federici Lorenzo, Melnic Andrian
 * @course	: Sistemi Operativi Dedicati @ UNIVPM (2021/2022)
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
/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "fatfs.h"
#include "libjpeg.h"
//#include "app_x-cube-ai.h"
#include "usb_host.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "utils.h"

#include "edge-impulse-sdk/classifier/ei_run_classifier.h"

using namespace ei;
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
CRC_HandleTypeDef hcrc;

DMA2D_HandleTypeDef hdma2d;

I2C_HandleTypeDef hi2c3;

LTDC_HandleTypeDef hltdc;

RTC_HandleTypeDef hrtc;

SPI_HandleTypeDef hspi5;

UART_HandleTypeDef huart1;

SDRAM_HandleTypeDef hsdram1;

/* USER CODE BEGIN PV */
/*
 * Variables declared in "utils.h" are defined here
 * source: https://stackoverflow.com/q/1433204
 */
uint8_t *scanline_buffer;
uint8_t *image_buffer;
__attribute__((section(".extram"))) uint8_t image_buffer_resized[IMGBUFFERSIZE];

// wip
__attribute__((section(".extram"))) uint16_t image_buffer_rgb565[IMAGE_HEIGHT*IMAGE_WIDTH];

// counter increased every time an image is decoded and processed
int imgs_processed = 0;
/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_DMA2D_Init(void);
static void MX_FMC_Init(void);
static void MX_I2C3_Init(void);
static void MX_LTDC_Init(void);
static void MX_SPI5_Init(void);
static void MX_USART1_UART_Init(void);
static void MX_CRC_Init(void);
static void MX_RTC_Init(void);
void MX_USB_HOST_Process(void);

/* USER CODE BEGIN PFP */
static void LCD_Config(void);
void DMA2D_BufferImage2LCD(uint32_t data, uint32_t x, uint32_t y, uint32_t width, uint32_t height);
void Scan_JPGs(void);
/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */
#include <stdarg.h>
#include "edge-impulse-sdk/classifier/ei_run_classifier.h"

void vprint(const char *fmt, va_list argp)
{
    char string[200];
    if(0 < vsprintf(string, fmt, argp)) // build string
    {
        //HAL_UART_Transmit(&huart1, (uint8_t*)string, strlen(string), 0xffffff); // send message via UART
        HAL_UART_Transmit(&huart1, (uint8_t*)string, strlen(string), 1000); // send message via UART
    }
}

void ei_printf(const char *format, ...) {
    va_list myargs;
    va_start(myargs, format);
    vprint(format, myargs);
    va_end(myargs);
}
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

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_DMA2D_Init();
  MX_FMC_Init();
  MX_I2C3_Init();
  MX_LTDC_Init();
  MX_SPI5_Init();
  MX_USART1_UART_Init();
  MX_CRC_Init();
  MX_FATFS_Init();
  MX_LIBJPEG_Init();
  MX_USB_HOST_Init();
  MX_RTC_Init();
  // MX_X_CUBE_AI_Init();
  /* USER CODE BEGIN 2 */
	#if VERBOSE_LEVEL == 2
		printf("[%s:%d] configuring the LCD... \r\n", __FILE__, __LINE__);
	#endif

	// configuring the LCD...
	LCD_Config();

	// now i can write on it
	BSP_LCD_SetFont(&Font16);
	BSP_LCD_SetTextColor(LCD_COLOR_WHITE);
	BSP_LCD_DisplayStringAt(0, LINE(1), (uint8_t*)"STM32 AI Framework", CENTER_MODE);
	BSP_LCD_DisplayStringAt(0, LINE(2), (uint8_t*)"SOD@UNIVPM 2022", CENTER_MODE);
	BSP_LCD_DisplayStringAt(0, LINE(4), (uint8_t*)"OBJECT DETECTION", CENTER_MODE);

	HAL_Delay(2000);
	BSP_LCD_Clear(LCD_COLOR_BLACK);
  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
	while (1)
	{
    /* USER CODE END WHILE */
    MX_USB_HOST_Process();

    // MX_X_CUBE_AI_Process();
    /* USER CODE BEGIN 3 */
		switch(Appli_state){
		case APPLICATION_READY:
			#if VERBOSE_LEVEL == 2
				printf("[%s:%d] scan for JPGs on USB host...\r\n", __FILE__, __LINE__);
			#endif
			// start to read images and process them
			Scan_JPGs();

			// quit when all the images have been read
			Appli_state = APPLICATION_IDLE;
			break;
		case APPLICATION_IDLE:
			// printf("IDLE\r\n");
		default:
			break;
		}

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

  /** Configure the main internal regulator output voltage
  */
  __HAL_RCC_PWR_CLK_ENABLE();
  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1);

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_LSI|RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  RCC_OscInitStruct.LSIState = RCC_LSI_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLM = 4;
  RCC_OscInitStruct.PLL.PLLN = 168;
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV2;
  RCC_OscInitStruct.PLL.PLLQ = 7;
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
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV4;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV2;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_5) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief CRC Initialization Function
  * @param None
  * @retval None
  */
static void MX_CRC_Init(void)
{

  /* USER CODE BEGIN CRC_Init 0 */

  /* USER CODE END CRC_Init 0 */

  /* USER CODE BEGIN CRC_Init 1 */

  /* USER CODE END CRC_Init 1 */
  hcrc.Instance = CRC;
  if (HAL_CRC_Init(&hcrc) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN CRC_Init 2 */

  /* USER CODE END CRC_Init 2 */

}

/**
  * @brief DMA2D Initialization Function
  * @param None
  * @retval None
  */
static void MX_DMA2D_Init(void)
{

  /* USER CODE BEGIN DMA2D_Init 0 */
	//
  /* USER CODE END DMA2D_Init 0 */

  /* USER CODE BEGIN DMA2D_Init 1 */
	//
  /* USER CODE END DMA2D_Init 1 */
  hdma2d.Instance = DMA2D;
  hdma2d.Init.Mode = DMA2D_M2M_PFC;
  hdma2d.Init.ColorMode = DMA2D_OUTPUT_ARGB8888;
  hdma2d.Init.OutputOffset = 0;
  hdma2d.LayerCfg[1].InputOffset = 0;
  hdma2d.LayerCfg[1].InputColorMode = DMA2D_INPUT_RGB888;
  hdma2d.LayerCfg[1].AlphaMode = DMA2D_NO_MODIF_ALPHA;
  hdma2d.LayerCfg[1].InputAlpha = 0;
  if (HAL_DMA2D_Init(&hdma2d) != HAL_OK)
  {
    Error_Handler();
  }
  if (HAL_DMA2D_ConfigLayer(&hdma2d, 1) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN DMA2D_Init 2 */
	//
  /* USER CODE END DMA2D_Init 2 */

}

/**
  * @brief I2C3 Initialization Function
  * @param None
  * @retval None
  */
static void MX_I2C3_Init(void)
{

  /* USER CODE BEGIN I2C3_Init 0 */

  /* USER CODE END I2C3_Init 0 */

  /* USER CODE BEGIN I2C3_Init 1 */

  /* USER CODE END I2C3_Init 1 */
  hi2c3.Instance = I2C3;
  hi2c3.Init.ClockSpeed = 100000;
  hi2c3.Init.DutyCycle = I2C_DUTYCYCLE_2;
  hi2c3.Init.OwnAddress1 = 0;
  hi2c3.Init.AddressingMode = I2C_ADDRESSINGMODE_7BIT;
  hi2c3.Init.DualAddressMode = I2C_DUALADDRESS_DISABLE;
  hi2c3.Init.OwnAddress2 = 0;
  hi2c3.Init.GeneralCallMode = I2C_GENERALCALL_DISABLE;
  hi2c3.Init.NoStretchMode = I2C_NOSTRETCH_DISABLE;
  if (HAL_I2C_Init(&hi2c3) != HAL_OK)
  {
    Error_Handler();
  }

  /** Configure Analogue filter
  */
  if (HAL_I2CEx_ConfigAnalogFilter(&hi2c3, I2C_ANALOGFILTER_ENABLE) != HAL_OK)
  {
    Error_Handler();
  }

  /** Configure Digital filter
  */
  if (HAL_I2CEx_ConfigDigitalFilter(&hi2c3, 0) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN I2C3_Init 2 */

  /* USER CODE END I2C3_Init 2 */

}

/**
  * @brief LTDC Initialization Function
  * @param None
  * @retval None
  */
static void MX_LTDC_Init(void)
{

  /* USER CODE BEGIN LTDC_Init 0 */
	//
  /* USER CODE END LTDC_Init 0 */

  LTDC_LayerCfgTypeDef pLayerCfg = {0};

  /* USER CODE BEGIN LTDC_Init 1 */
	//
  /* USER CODE END LTDC_Init 1 */
  hltdc.Instance = LTDC;
  hltdc.Init.HSPolarity = LTDC_HSPOLARITY_AL;
  hltdc.Init.VSPolarity = LTDC_VSPOLARITY_AL;
  hltdc.Init.DEPolarity = LTDC_DEPOLARITY_AL;
  hltdc.Init.PCPolarity = LTDC_PCPOLARITY_IPC;
  hltdc.Init.HorizontalSync = 9;
  hltdc.Init.VerticalSync = 1;
  hltdc.Init.AccumulatedHBP = 29;
  hltdc.Init.AccumulatedVBP = 3;
  hltdc.Init.AccumulatedActiveW = 269;
  hltdc.Init.AccumulatedActiveH = 323;
  hltdc.Init.TotalWidth = 279;
  hltdc.Init.TotalHeigh = 327;
  hltdc.Init.Backcolor.Blue = 0;
  hltdc.Init.Backcolor.Green = 0;
  hltdc.Init.Backcolor.Red = 0;
  if (HAL_LTDC_Init(&hltdc) != HAL_OK)
  {
    Error_Handler();
  }
  pLayerCfg.WindowX0 = 0;
  pLayerCfg.WindowX1 = 240;
  pLayerCfg.WindowY0 = 0;
  pLayerCfg.WindowY1 = 320;
  pLayerCfg.PixelFormat = LTDC_PIXEL_FORMAT_ARGB8888;
  pLayerCfg.Alpha = 0;
  pLayerCfg.Alpha0 = 0;
  pLayerCfg.BlendingFactor1 = LTDC_BLENDING_FACTOR1_CA;
  pLayerCfg.BlendingFactor2 = LTDC_BLENDING_FACTOR2_CA;
  pLayerCfg.FBStartAdress = 0xD0000000;
  pLayerCfg.ImageWidth = 240;
  pLayerCfg.ImageHeight = 320;
  pLayerCfg.Backcolor.Blue = 0;
  pLayerCfg.Backcolor.Green = 0;
  pLayerCfg.Backcolor.Red = 0;
  if (HAL_LTDC_ConfigLayer(&hltdc, &pLayerCfg, 0) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN LTDC_Init 2 */
	//
  /* USER CODE END LTDC_Init 2 */

}

/**
  * @brief RTC Initialization Function
  * @param None
  * @retval None
  */
static void MX_RTC_Init(void)
{

  /* USER CODE BEGIN RTC_Init 0 */

  /* USER CODE END RTC_Init 0 */

  /* USER CODE BEGIN RTC_Init 1 */

  /* USER CODE END RTC_Init 1 */

  /** Initialize RTC Only
  */
  hrtc.Instance = RTC;
  hrtc.Init.HourFormat = RTC_HOURFORMAT_24;
  hrtc.Init.AsynchPrediv = 127;
  hrtc.Init.SynchPrediv = 255;
  hrtc.Init.OutPut = RTC_OUTPUT_DISABLE;
  hrtc.Init.OutPutPolarity = RTC_OUTPUT_POLARITY_HIGH;
  hrtc.Init.OutPutType = RTC_OUTPUT_TYPE_OPENDRAIN;
  if (HAL_RTC_Init(&hrtc) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN RTC_Init 2 */

  /* USER CODE END RTC_Init 2 */

}

/**
  * @brief SPI5 Initialization Function
  * @param None
  * @retval None
  */
static void MX_SPI5_Init(void)
{

  /* USER CODE BEGIN SPI5_Init 0 */

  /* USER CODE END SPI5_Init 0 */

  /* USER CODE BEGIN SPI5_Init 1 */

  /* USER CODE END SPI5_Init 1 */
  /* SPI5 parameter configuration*/
  hspi5.Instance = SPI5;
  hspi5.Init.Mode = SPI_MODE_MASTER;
  hspi5.Init.Direction = SPI_DIRECTION_2LINES;
  hspi5.Init.DataSize = SPI_DATASIZE_8BIT;
  hspi5.Init.CLKPolarity = SPI_POLARITY_LOW;
  hspi5.Init.CLKPhase = SPI_PHASE_1EDGE;
  hspi5.Init.NSS = SPI_NSS_SOFT;
  hspi5.Init.BaudRatePrescaler = SPI_BAUDRATEPRESCALER_16;
  hspi5.Init.FirstBit = SPI_FIRSTBIT_MSB;
  hspi5.Init.TIMode = SPI_TIMODE_DISABLE;
  hspi5.Init.CRCCalculation = SPI_CRCCALCULATION_DISABLE;
  hspi5.Init.CRCPolynomial = 10;
  if (HAL_SPI_Init(&hspi5) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN SPI5_Init 2 */

  /* USER CODE END SPI5_Init 2 */

}

/**
  * @brief USART1 Initialization Function
  * @param None
  * @retval None
  */
static void MX_USART1_UART_Init(void)
{

  /* USER CODE BEGIN USART1_Init 0 */

  /* USER CODE END USART1_Init 0 */

  /* USER CODE BEGIN USART1_Init 1 */

  /* USER CODE END USART1_Init 1 */
  huart1.Instance = USART1;
  huart1.Init.BaudRate = 9600;
  huart1.Init.WordLength = UART_WORDLENGTH_8B;
  huart1.Init.StopBits = UART_STOPBITS_1;
  huart1.Init.Parity = UART_PARITY_NONE;
  huart1.Init.Mode = UART_MODE_TX_RX;
  huart1.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  huart1.Init.OverSampling = UART_OVERSAMPLING_16;
  if (HAL_UART_Init(&huart1) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN USART1_Init 2 */

  /* USER CODE END USART1_Init 2 */

}

/* FMC initialization function */
static void MX_FMC_Init(void)
{

  /* USER CODE BEGIN FMC_Init 0 */
	//
  /* USER CODE END FMC_Init 0 */

  FMC_SDRAM_TimingTypeDef SdramTiming = {0};

  /* USER CODE BEGIN FMC_Init 1 */
	//
  /* USER CODE END FMC_Init 1 */

  /** Perform the SDRAM1 memory initialization sequence
  */
  hsdram1.Instance = FMC_SDRAM_DEVICE;
  /* hsdram1.Init */
  hsdram1.Init.SDBank = FMC_SDRAM_BANK2;
  hsdram1.Init.ColumnBitsNumber = FMC_SDRAM_COLUMN_BITS_NUM_8;
  hsdram1.Init.RowBitsNumber = FMC_SDRAM_ROW_BITS_NUM_12;
  hsdram1.Init.MemoryDataWidth = FMC_SDRAM_MEM_BUS_WIDTH_16;
  hsdram1.Init.InternalBankNumber = FMC_SDRAM_INTERN_BANKS_NUM_4;
  hsdram1.Init.CASLatency = FMC_SDRAM_CAS_LATENCY_3;
  hsdram1.Init.WriteProtection = FMC_SDRAM_WRITE_PROTECTION_DISABLE;
  hsdram1.Init.SDClockPeriod = FMC_SDRAM_CLOCK_PERIOD_2;
  hsdram1.Init.ReadBurst = FMC_SDRAM_RBURST_DISABLE;
  hsdram1.Init.ReadPipeDelay = FMC_SDRAM_RPIPE_DELAY_1;
  /* SdramTiming */
  SdramTiming.LoadToActiveDelay = 2;
  SdramTiming.ExitSelfRefreshDelay = 7;
  SdramTiming.SelfRefreshTime = 4;
  SdramTiming.RowCycleDelay = 7;
  SdramTiming.WriteRecoveryTime = 3;
  SdramTiming.RPDelay = 2;
  SdramTiming.RCDDelay = 2;

  if (HAL_SDRAM_Init(&hsdram1, &SdramTiming) != HAL_OK)
  {
    Error_Handler( );
  }

  /* USER CODE BEGIN FMC_Init 2 */
  /* USER CODE END FMC_Init 2 */
}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOF_CLK_ENABLE();
  __HAL_RCC_GPIOH_CLK_ENABLE();
  __HAL_RCC_GPIOC_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();
  __HAL_RCC_GPIOG_CLK_ENABLE();
  __HAL_RCC_GPIOE_CLK_ENABLE();
  __HAL_RCC_GPIOD_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOC, GPIO_PIN_4, GPIO_PIN_RESET);

  /*Configure GPIO pin : PC4 */
  GPIO_InitStruct.Pin = GPIO_PIN_4;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

}

/* USER CODE BEGIN 4 */
//int _write(int file, char *ptr, int len){
//	HAL_UART_Transmit(&huart1,(uint8_t*)ptr,len,1000);
//
//	return len;
//}


static void LCD_Config(void)
{
	/* Initialize the LCD */
	BSP_LCD_Init();

	/* Background Layer Initialization */
	BSP_LCD_LayerDefaultInit(0, LCD_BUFFER);

	/* Set Foreground Layer */
	BSP_LCD_SelectLayer(0);

	/* Enable the LCD */
	BSP_LCD_DisplayOn();

	/* Clear the LCD Background layer */
	BSP_LCD_SetTransparency(0,255);
	BSP_LCD_Clear(LCD_COLOR_BLACK);
	BSP_LCD_SetFont(&Font16);
	BSP_LCD_SetTextColor(LCD_COLOR_WHITE);
	BSP_LCD_SetBackColor(LCD_COLOR_BLACK);
}


void DMA2D_BufferImage2LCD(uint32_t data, uint32_t x, uint32_t y, uint32_t width, uint32_t height)
{
	/*
	 * ensure to have configured the DMA2D with this settings
	 * - DMA2D_M2M_PFC : pixel format conversion
	 * the image buffer is stored as RGB888 (= 24bit, uint8_t for each channel)
	 * but the display is configured as ARGB8888 (= 32bit, uint32_t for each pixel)
	 * - MA2D_M2M : if InputColorMode == ColorMode (ARGB8888) but a previous conversion is required
	 * it consists of converting the image buffer to a ARGB32Buffer to store the image in 32bit
	 */
	hdma2d.Init.ColorMode = DMA2D_OUTPUT_ARGB8888;
	hdma2d.LayerCfg[1].InputColorMode = DMA2D_INPUT_RGB888;
	hdma2d.Init.OutputOffset = BSP_LCD_GetXSize() - width;

	HAL_DMA2D_Init(&hdma2d);
	HAL_DMA2D_ConfigLayer(&hdma2d, 1);
	HAL_DMA2D_Start(&hdma2d, data, LCD_BUFFER + (x + y * BSP_LCD_GetXSize()) * 4, width, height);
	HAL_DMA2D_PollForTransfer(&hdma2d, 10);
}


void DMA2D_RGB565_LCD(uint32_t data, uint32_t x, uint32_t y, uint32_t width, uint32_t height)
{
	/*
	 * ensure to have configured the DMA2D with this settings
	 * - DMA2D_M2M_PFC : pixel format conversion
	 * the image buffer is stored as RGB888 (= 24bit, uint8_t for each channel)
	 * but the display is configured as ARGB8888 (= 32bit, uint32_t for each pixel)
	 * - MA2D_M2M : if InputColorMode == ColorMode (ARGB8888) but a previous conversion is required
	 * it consists of converting the image buffer to a ARGB32Buffer to store the image in 32bit
	 */
	hdma2d.Init.ColorMode = DMA2D_OUTPUT_ARGB8888;
	hdma2d.LayerCfg[1].InputColorMode = DMA2D_INPUT_RGB565;
	hdma2d.Init.OutputOffset = BSP_LCD_GetXSize() - width;

	HAL_DMA2D_Init(&hdma2d);
	HAL_DMA2D_ConfigLayer(&hdma2d, 1);
	HAL_DMA2D_Start(&hdma2d, data, LCD_BUFFER + (x + y * BSP_LCD_GetXSize()) * 4, width, height);
	HAL_DMA2D_PollForTransfer(&hdma2d, 10);
}


/**
 * @brief      Convert RGB565 raw camera buffer to RGB888
 *
 * @param[in]   offset       pixel offset of raw buffer
 * @param[in]   length       number of pixels to convert
 * @param[out]  out_buf      pointer to store output image
 */
int ei_buffer_get_data(size_t offset, size_t length, float *out_ptr) {
//	size_t pixel_ix = offset * 2;
//	size_t bytes_left = length;
//	size_t out_ptr_ix = 0;
//
//	// read byte for byte
//	while (bytes_left != 0) {
//		// grab the value and convert to r/g/b
//		uint16_t pixel = (image_buffer_rgb565[pixel_ix] << 8) | image_buffer_rgb565[pixel_ix+1];
//		uint8_t r, g, b;
//		r = ((pixel >> 11) & 0x1f) << 3;
//		g = ((pixel >> 5) & 0x3f) << 2;
//		b = (pixel & 0x1f) << 3;
//
//		// then convert to out_ptr format
//		float pixel_f = (r << 16) + (g << 8) + b;
//		out_ptr[out_ptr_ix] = pixel_f;
//
//		// and go to the next pixel
//		out_ptr_ix++;
//		pixel_ix+=2;
//		bytes_left--;
//	}
//
//	// and done!
//	return 0;

	size_t pixel_ix = offset * 3;
	size_t bytes_left = length;
	size_t out_ptr_ix = 0;

	// read byte for byte
	while (bytes_left != 0) {
		// grab the value and convert to r/g/b
		uint8_t r = image_buffer_resized[pixel_ix];
		uint8_t g = image_buffer_resized[pixel_ix+1];
		uint8_t b = image_buffer_resized[pixel_ix+2];

		// then convert to out_ptr format
		float pixel_f = (r << 16) + (g << 8) + b;
		out_ptr[out_ptr_ix] = pixel_f;

		// and go to the next pixel
		out_ptr_ix++;
		pixel_ix+=3;
		bytes_left--;
	}

	// and done!
	return 0;
}


void convertBuffers() {
	uint8_t r, g, b;
	uint16_t red, green, blue;

	for(int i = 0; i < IMAGE_HEIGHT * IMAGE_WIDTH; i++) {
		// R&B swap
		r = image_buffer_resized[i * 3];
		g = image_buffer_resized[i * 3 + 1];
		b = image_buffer_resized[i * 3 + 2];

		blue = (b >> 3) & 0x1f;
		green = ((g >> 2) & 0x3f) << 5;
		red = ((r >> 3) & 0x1f) << 11;

		// then convert to out_ptr format
		image_buffer_rgb565[i] = (uint16_t) (red | green | blue);
	}

}


void Scan_JPGs(void){
	// needed for manage the USB host's file system
	DIR dir;
	FILINFO fno;
	FRESULT res;
	int status;

	#if VERBOSE_LEVEL == 2
		printf("[%s:%d] searching images in %s ... \r\n", __FILE__, __LINE__, PATH_TO_JPEGS);
	#endif

	if (f_chdir(PATH_TO_JPEGS) == FR_OK){
		// looking for images .jpg and .jpeg format
		res = f_findfirst(&dir, &fno, "", "*.j*g");

		while((res == FR_OK) && (fno.fname[0])){
			ei_printf("############### IMAGE N.%d ############### \r\n", ++imgs_processed);

			#if VERBOSE_LEVEL == 2
				printf("[%s:%d] decoding image %s \r\n", __FILE__, __LINE__, fno.fname);
			#elif VERBOSE_LEVEL == 1 || VERBOSE_LEVEL == 0
				ei_printf("decoding image %s \r\n", fno.fname);
			#endif
			// decode, resize and store the image into the dedicated buffer
			status = ProcessJPG((uint8_t*)fno.fname);

			if(status) {
				/*
				 * print the resized image to the LCD using the Chrom-ART accelerator
				 * which offers hardware acceleration for STM32 graphical operations.
				 *
				 * other methods to draw the image buffer into the LCD:
				 * 1 -> convert the buffer to ARGB8888 format (32bit) in order to avoid the DMA2D_M2M_PFC
				 * 2 -> get a (uint8_t *) buffer compatible with the input format of the neural network
				 * 		it can also be done by casting the array (uint8_t *)image_buffer
				 */
				DMA2D_BufferImage2LCD(
					(uint32_t)image_buffer_resized,
					(BSP_LCD_GetXSize() - IMAGE_WIDTH) / 2,
					(BSP_LCD_GetXSize() - IMAGE_HEIGHT) / 2,
					IMAGE_WIDTH,
					IMAGE_HEIGHT
				);

				// convert RGB888 to RGB565
				// convertBuffers();

//				DMA2D_RGB565_LCD(
//					(uint32_t)image_buffer_rgb565,
//					0, //(BSP_LCD_GetXSize() - IMAGE_WIDTH) / 2,
//					0, //(BSP_LCD_GetXSize() - IMAGE_HEIGHT) / 2,
//					IMAGE_WIDTH,
//					IMAGE_HEIGHT
//				);


				// Edge Impulse AI
				ei::signal_t signal;
				signal.total_length = EI_CLASSIFIER_INPUT_WIDTH * EI_CLASSIFIER_INPUT_HEIGHT;
				signal.get_data = &ei_buffer_get_data;

				// run the impulse: DSP, neural network and the Anomaly algorithm
				ei_impulse_result_t result = { 0 };

				EI_IMPULSE_ERROR ei_error = run_classifier(&signal, &result, false);
				if (ei_error != EI_IMPULSE_OK) {
					ei_printf("Failed to run impulse (%d)\r\n", ei_error);
					break;
				}

				// print the predictions
				ei_printf("Predictions (DSP: %d ms., Classification: %d ms., Anomaly: %d ms.): \r\n",
						result.timing.dsp, result.timing.classification, result.timing.anomaly);

				BSP_LCD_SetFont(&Font12);

				char msg[20];

				bool bb_found = result.bounding_boxes[0].value > 0;
				for (size_t ix = 0; ix < result.bounding_boxes_count; ix++) {
					auto bb = result.bounding_boxes[ix];
					if (bb.value == 0) {
						continue;
					}

					ei_printf("    %s (%f) [ x: %lu, y: %lu, width: %lu, height: %lu ]\r\n", bb.label, bb.value, bb.x, bb.y, bb.width, bb.height);

					uint32_t x_norm = ((BSP_LCD_GetXSize() - IMAGE_WIDTH) / 2) + bb.x;
					uint32_t y_norm = ((BSP_LCD_GetXSize() - IMAGE_HEIGHT) / 2) + bb.y;

					// set colors
					if(!strcmp(bb.label, ei_classifier_inferencing_categories[0])) {
						// screw
						BSP_LCD_SetTextColor(LCD_COLOR_GREEN);
					} else {
						BSP_LCD_SetTextColor(LCD_COLOR_RED);
					}

					// draw circle on LCD
					BSP_LCD_DrawCircle(x_norm, y_norm, bb.width);

					// write label and confidence
					if(EI_PRINT_LABELS) {
						sprintf(msg, "%s (%.2f)", bb.label, bb.value);
						BSP_LCD_DisplayStringAt(x_norm, y_norm + bb.width, (uint8_t*)msg, LEFT_MODE);
					}

				}

				if (!bb_found) {
					ei_printf("    No objects found\r\n");
				}

				// AI process
				// MX_X_CUBE_AI_Process();

				// wait 4s to read the neural network results
				HAL_Delay(2000);

				// clear the last AI results (todo: indices hard-coded)
				// for (int k = 10; k < 17; k++) BSP_LCD_ClearStringLine(k);
				BSP_LCD_Clear(LCD_COLOR_BLACK);
			}

			// search next image is exist
			res = f_findnext(&dir, &fno);
		}

		f_closedir(&dir);

		BSP_LCD_Clear(LCD_COLOR_BLACK);
		BSP_LCD_SetFont(&Font16);
		BSP_LCD_SetTextColor(LCD_COLOR_WHITE);
		BSP_LCD_DisplayStringAt(0, LINE(1), (uint8_t*)"STM32 AI Framework", CENTER_MODE);
		BSP_LCD_DisplayStringAt(0, LINE(2), (uint8_t*)"SOD@UNIVPM 2022", CENTER_MODE);
		BSP_LCD_DisplayStringAt(0, LINE(4), (uint8_t*)"Program terminated", CENTER_MODE);

		printf("################   END   ################ \r\n");
	}
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
