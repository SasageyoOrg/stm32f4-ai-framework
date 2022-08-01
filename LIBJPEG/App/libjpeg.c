/* USER CODE BEGIN Header */
/**
 ******************************************************************************
 * File Name	: libjpeg.c
 * Description	: This file provides code for the configuration
 *                of the libjpeg instances.
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

/* Includes ------------------------------------------------------------------*/
#include "libjpeg.h"

/* USER CODE BEGIN 0 */
#include "utils.h"
/* USER CODE END 0 */

/* USER CODE BEGIN 1 */
/* USER CODE END 1 */

/* Global variables ---------------------------------------------------------*/

/* USER CODE BEGIN 2 */

__attribute__((section(".ccmram"))) FIL file;
__attribute__((section(".ccmram"))) struct jpeg_decompress_struct cinfo;
__attribute__((section(".ccmram"))) struct jpeg_error_mgr jerr;
__attribute__((section(".ccmram"))) JSAMPROW buffer[1] = {0};
__attribute__((section(".ccmram"))) int buffer_px_counter = 0;

RGB_typedef *RGB_matrix;

/* USER CODE END 2 */

/* LIBJPEG init function */
void MX_LIBJPEG_Init(void)
{
/***************************************/
   /**
  */

  /* USER CODE BEGIN 3 */
  /* USER CODE END 3 */

}

/* USER CODE BEGIN 4 */
void StoreImageBuffer(uint8_t* buffer){
	uint32_t i = 0;
	RGB_matrix = (RGB_typedef*)buffer;

	// swap the R & B components... should be verified
	for(i = 0; i < IMAGE_WIDTH; i++) {
		image_buffer[buffer_px_counter++] = RGB_matrix[i].B;
		image_buffer[buffer_px_counter++] = RGB_matrix[i].G;
		image_buffer[buffer_px_counter++] = RGB_matrix[i].R;
	}
}

void Decode_JPG(uint8_t *filename) {
	/* Decode JPEG Image */
	JSAMPROW buffer[2] = {0}; /* Output row buffer */
	FIL file;

	if(f_open(&file, (char*)filename, FA_READ) != FR_OK)
	{
		printf("[%s:%d] open file error \r\n", __FILE__, __LINE__);
		return;
	}


	buffer[0] = &_aucLine[0];
	// step 1: allocate and initialize JPEG decompression object
	cinfo.err = jpeg_std_error(&jerr);

	// initialize the JPEG decompression object
	jpeg_create_decompress(&cinfo);
	jpeg_stdio_src (&cinfo, &file);

	// step 3: read image parameters with jpeg_read_header()
	jpeg_read_header(&cinfo, TRUE);

	// step 4: set parameters for decompression
	cinfo.dct_method = JDCT_FLOAT;

	// step 5: start the de-compressor
	cinfo.scale_num=1;
	cinfo.scale_denom=1;
	jpeg_start_decompress(&cinfo);

	#if VERBOSE_LEVEL == 2
		printf("[%s:%d] jpeg output size %dx%d\r\n", __FILE__, __LINE__, cinfo.output_width, cinfo.output_height);
	#endif

	buffer_px_counter = 0;
	while (cinfo.output_scanline < cinfo.output_height)
	{
		(void)jpeg_read_scanlines(&cinfo, buffer, 1);

		StoreImageBuffer(buffer[0]);
	}

	/* Step 6: Finish decompression */
	jpeg_finish_decompress(&cinfo);

	/* Step 7: Release JPEG decompression object */
	jpeg_destroy_decompress(&cinfo);

	f_close(&file);
}
/* USER CODE END 4 */

/**
  * @}
  */

/**
  * @}
  */
