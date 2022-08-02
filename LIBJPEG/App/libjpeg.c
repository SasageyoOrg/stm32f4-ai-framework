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

// decoded JPEG image sizes
int read_srcImgW;
int read_srcImgH;

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
	RGB_typedef *RGB_matrix = (RGB_typedef*)buffer;

	// swap the R & B components... should be verified
	for(i = 0; i < read_srcImgW; i++) {
		image_buffer[buffer_px_counter++] = RGB_matrix[i].B;
		image_buffer[buffer_px_counter++] = RGB_matrix[i].G;
		image_buffer[buffer_px_counter++] = RGB_matrix[i].R;
	}
}

int ProcessJPG(uint8_t *filename) {
	// output row buffer
	JSAMPROW buffer[2] = {0};
	FIL file;

	if(f_open(&file, (char*)filename, FA_READ) != FR_OK)
	{
		printf("[%s:%d] open file error \r\n", __FILE__, __LINE__);
		return 0;
	}

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

	// save the decoded image dimensions
	read_srcImgW = cinfo.output_width;
	read_srcImgH = cinfo.output_height;

	// check the size against the limits
	if(read_srcImgW > 512 || read_srcImgH > 512)
	{
		#if VERBOSE_LEVEL == 2
			printf("[%s:%d] image too large, skip (max: 512x512px) \r\n", __FILE__, __LINE__);
		#elif VERBOSE_LEVEL == 1 || VERBOSE_LEVEL == 0
			printf("image too large, skip (max: 512x512px) \r\n");
		#endif

		/* Step 6: Finish decompression */
		jpeg_finish_decompress(&cinfo);

		/* Step 7: Release JPEG decompression object */
		jpeg_destroy_decompress(&cinfo);

		f_close(&file);

		return 0;
	}

	/*
	 * allocating dynamic memory in external SDRAM (remember to free the memory once used)
	 * this needs a change in _sbrk() from sysmem.c to set user-specific heap bottom and top limits
	 * sources: https://community.st.com/s/question/0D53W00000evdsbSAA
	 * 			https://community.st.com/s/question/0D53W00000Wc5rDSAR
	 */
	// space address for the scanline buffer
	scanline_buffer = (uint8_t*)calloc(read_srcImgW * 3, sizeof(uint8_t));
	// prepare the buffer of the image that will be read later
	image_buffer = (uint8_t*)calloc(read_srcImgW * read_srcImgW * 3, sizeof(uint8_t));

	// align the buffer space address
	buffer[0] = &scanline_buffer[0];

	// reset counter
	buffer_px_counter = 0;

	while (cinfo.output_scanline < cinfo.output_height)
	{
		(void)jpeg_read_scanlines(&cinfo, buffer, 1);

		// builds the image buffer incrementally by merging scanlines
		StoreImageBuffer(buffer[0]);
	}

	#if VERBOSE_LEVEL == 2
		printf("[%s:%d] resize image buffer for neural network (%d,%d) -> (%d,%d) \r\n", __FILE__, __LINE__,
																						read_srcImgW, read_srcImgH,
																						IMAGE_WIDTH, IMAGE_HEIGHT);
	#elif VERBOSE_LEVEL == 1
		printf("resize image buffer (%d,%d) -> (%d,%d) \r\n", read_srcImgW, read_srcImgH, IMAGE_WIDTH, IMAGE_HEIGHT);
	#endif

	// resize the image buffer for neural network
	UTILS_ResizeBuffer((uint8_t *)image_buffer,
						(uint8_t *)image_buffer_resized,
						read_srcImgW,
						read_srcImgH,
						IMAGE_WIDTH,
						IMAGE_HEIGHT);

	/*
	 * free the allocated memory no longer needed
	 * scanline_buffer	-> used to store the scanline buffer
	 * image_buffer		-> the neural network receives 'image_buffer_resized' as input
	 */
	free(scanline_buffer);
	free(image_buffer);

	/* Step 6: Finish decompression */
	jpeg_finish_decompress(&cinfo);

	/* Step 7: Release JPEG decompression object */
	jpeg_destroy_decompress(&cinfo);

	f_close(&file);

	return 1;
}
/* USER CODE END 4 */

/**
  * @}
  */

/**
  * @}
  */
