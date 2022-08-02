
/**
  ******************************************************************************
  * @file    app_x-cube-ai.c
  * @author  X-CUBE-AI C code generator
  * @brief   AI program body
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

 /*
  * Description
  *   v1.0 - Minimum template to show how to use the Embedded Client API
  *          model. Only one input and one output is supported. All
  *          memory resources are allocated statically (AI_NETWORK_XX, defines
  *          are used).
  *          Re-target of the printf function is out-of-scope.
  *   v2.0 - add multiple IO and/or multiple heap support
  *
  *   For more information, see the embeded documentation:
  *
  *       [1] %X_CUBE_AI_DIR%/Documentation/index.html
  *
  *   X_CUBE_AI_DIR indicates the location where the X-CUBE-AI pack is installed
  *   typical : C:\Users\<user_name>\STM32Cube\Repository\STMicroelectronics\X-CUBE-AI\7.1.0
  */

#ifdef __cplusplus
 extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/

#if defined ( __ICCARM__ )
#define AI_EXTERNAL_SDRAM   _Pragma("location=\"AI_EXTERNAL_SDRAM\"")
#elif defined ( __CC_ARM ) || ( __GNUC__ )
#define AI_EXTERNAL_SDRAM   __attribute__((section(".AI_EXTERNAL_SDRAM")))
#endif

/* System headers */
#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <inttypes.h>
#include <string.h>

#include "app_x-cube-ai.h"
#include "main.h"
#include "ai_datatypes_defines.h"
#include "network.h"
#include "network_data.h"

/* USER CODE BEGIN includes */

#include "utils.h"
#include "math.h"

/* Private defines ---------------------------------------------------------------------*/

#define AI_FXP_Q 	(0x0)
#define AI_UINT_Q 	(0x1)
#define AI_SINT_Q 	(0x2)

/* Private macros ----------------------------------------------------------------------*/

#define _MIN(x_, y_) \
		( ((x_)<(y_)) ? (x_) : (y_) )
#define _MAX(x_, y_) \
		( ((x_)>(y_)) ? (x_) : (y_) )
#define _CLAMP(x_, min_, max_, type_) \
		(type_) (_MIN(_MAX(x_, min_), max_))
#define _ROUND(v_, type_) \
		(type_) ( ((v_)<0) ? ((v_)-0.5f) : ((v_)+0.5f) )

/* References with fp_vision_ai --------------------------------------------------------*/
// Ai_Context_Ptr->activation_buffer	==>	data_activations0
// Ai_Context_Ptr->nn_input_buffer		==>	data_in_1
// Ai_Context_Ptr->nn_output_buffer		==>	data_out_1

/* Variables ---------------------------------------------------------------------------*/

const unsigned long int bufferBytes = IMGBUFFERSIZE;
// look-up table preproc
uint8_t pixel_conv_lut[256];
// neural network classes
const char* output_labels[AI_NETWORK_OUT_1_SIZE] = AI_CLASSES;
// ranking array for the neural network classes
int ranking[AI_NETWORK_OUT_1_SIZE];
// timing to benchmarking the inference
uint32_t nn_inference_time;

/* PFP ---------------------------------------------------------------------------------*/

ai_float ai_get_input_scale(void);
ai_float ai_get_output_scale(void);

/* USER CODE END includes */

/* IO buffers ----------------------------------------------------------------*/

#if !defined(AI_NETWORK_INPUTS_IN_ACTIVATIONS)
AI_ALIGNED(4) ai_i8 data_in_1[AI_NETWORK_IN_1_SIZE_BYTES] __attribute__((section(".extram")));
ai_i8* data_ins[AI_NETWORK_IN_NUM] = {
data_in_1
};
#else
ai_i8* data_ins[AI_NETWORK_IN_NUM] = {
NULL
};
#endif

#if !defined(AI_NETWORK_OUTPUTS_IN_ACTIVATIONS)
AI_ALIGNED(4) ai_i8 data_out_1[AI_NETWORK_OUT_1_SIZE_BYTES] __attribute__((section(".extram")));
//AI_ALIGNED(4) ai_i8 data_out_1[AI_NETWORK_OUT_1_SIZE_BYTES];
ai_i8* data_outs[AI_NETWORK_OUT_NUM] = {
data_out_1
};
#else
ai_i8* data_outs[AI_NETWORK_OUT_NUM] = {
NULL
};
#endif

/* Activations buffers -------------------------------------------------------*/

ai_handle data_activations0[] = {(ai_handle) 0xD0300000};

/* AI objects ----------------------------------------------------------------*/

static ai_handle network = AI_HANDLE_NULL;

static ai_buffer* ai_input;
static ai_buffer* ai_output;

static void ai_log_err(const ai_error err, const char *fct)
{
  /* USER CODE BEGIN log */
	if (fct)
		printf("[%s:%d] TEMPLATE - Error (%s) - type=0x%02x code=0x%02x\r\n", __FILE__, __LINE__, fct, err.type, err.code);
	else
		printf("[%s:%d] TEMPLATE - Error - type=0x%02x code=0x%02x\r\n", __FILE__, __LINE__, err.type, err.code);

	do {} while (1);
  /* USER CODE END log */
}

static int ai_boostrap(ai_handle *act_addr)
{
  ai_error err;

  /* Create and initialize an instance of the model */
  err = ai_network_create_and_init(&network, act_addr, NULL);
  if (err.type != AI_ERROR_NONE) {
    ai_log_err(err, "ai_network_create_and_init");
    return -1;
  }

  ai_input = ai_network_inputs_get(network, NULL);
  ai_output = ai_network_outputs_get(network, NULL);

#if defined(AI_NETWORK_INPUTS_IN_ACTIVATIONS)
  /*  In the case where "--allocate-inputs" option is used, memory buffer can be
   *  used from the activations buffer. This is not mandatory.
   */
  for (int idx=0; idx < AI_NETWORK_IN_NUM; idx++) {
	data_ins[idx] = ai_input[idx].data;
  }
#else
  for (int idx=0; idx < AI_NETWORK_IN_NUM; idx++) {
	  ai_input[idx].data = data_ins[idx];
  }
#endif

#if defined(AI_NETWORK_OUTPUTS_IN_ACTIVATIONS)
  /*  In the case where "--allocate-outputs" option is used, memory buffer can be
   *  used from the activations buffer. This is no mandatory.
   */
  for (int idx=0; idx < AI_NETWORK_OUT_NUM; idx++) {
	data_outs[idx] = ai_output[idx].data;
  }
#else
  for (int idx=0; idx < AI_NETWORK_OUT_NUM; idx++) {
	ai_output[idx].data = data_outs[idx];
  }
#endif

  return 0;
}

static int ai_run(void)
{
  ai_i32 batch;

	/** set input/output buffer addresses */
	ai_input[0].data = AI_HANDLE_PTR(data_in_1);
	ai_output[0].data = AI_HANDLE_PTR(data_out_1);

	/** perform the inference */
	batch = ai_network_run(network, &ai_input[0], &ai_output[0]);
	if (batch != 1) {
		ai_log_err(ai_network_get_error(network),
				"ai_network_run");
		return -1;
	}

  return 0;
}

/* USER CODE BEGIN 2 */

/* Functions Definition ----------------------------------------------------------------*/
ai_size ai_get_input_format(void)
{
	ai_buffer_format fmt = AI_BUFFER_FORMAT(&ai_input[0]);
	return AI_BUFFER_FMT_GET_TYPE(fmt);
}

ai_size ai_get_output_format(void)
{
	ai_buffer_format fmt = AI_BUFFER_FORMAT(&ai_output[0]);
	return AI_BUFFER_FMT_GET_TYPE(fmt);
}

ai_size ai_get_input_quantized_format(void)
{
	ai_buffer_format fmt = AI_BUFFER_FORMAT(&ai_input[0]);
	return (AI_BUFFER_FMT_GET_BITS(fmt) - AI_BUFFER_FMT_GET_SIGN(fmt) - AI_BUFFER_FMT_GET_FBITS(fmt));
}

uint32_t ai_get_input_quantization_scheme(void)
{
	ai_float scale=ai_get_input_scale();

	ai_buffer_format fmt=AI_BUFFER_FORMAT(&ai_input[0]);
	ai_size sign = AI_BUFFER_FMT_GET_SIGN(fmt);

	if(scale==0)
	{
		return AI_FXP_Q;
	}
	else
	{
		if(sign==0)
		{
			return AI_UINT_Q;
		}
		else
		{
			return AI_SINT_Q;
		}
	}
}

uint32_t ai_get_output_quantization_scheme(void)
{
	ai_float scale=ai_get_output_scale();

	ai_buffer_format fmt=AI_BUFFER_FORMAT(&ai_output[0]);
	ai_size sign = AI_BUFFER_FMT_GET_SIGN(fmt);

	if(scale==0)
	{
		return AI_FXP_Q;
	}
	else
	{
		if(sign==0)
		{
			return AI_UINT_Q;
		}
		else
		{
			return AI_SINT_Q;
		}
	}
}

ai_float ai_get_output_fxp_scale(void)
{
	float scale;
	ai_buffer_format fmt_1;

	/* Retrieve format of the output tensor - index 0 */
	fmt_1 = AI_BUFFER_FORMAT(&ai_output[0]);

	/* Build the scale factor for conversion */
	scale = 1.0f / (0x1U << AI_BUFFER_FMT_GET_FBITS(fmt_1));

	return scale;
}

ai_float ai_get_input_scale(void)
{
	return AI_BUFFER_META_INFO_INTQ_GET_SCALE(ai_input[0].meta_info, 0);
}

ai_i32 ai_get_input_zero_point(void)
{
	return AI_BUFFER_META_INFO_INTQ_GET_ZEROPOINT(ai_input[0].meta_info, 0);
}

ai_float ai_get_output_scale(void)
{
	return AI_BUFFER_META_INFO_INTQ_GET_SCALE(ai_output[0].meta_info, 0);
}

ai_i32 ai_get_output_zero_point(void)
{
	return AI_BUFFER_META_INFO_INTQ_GET_ZEROPOINT(ai_output[0].meta_info, 0);
}

static void Precompute_8FXP(uint8_t *lut, uint32_t q_input_shift)
{
	uint32_t index;

	for(index=0;index<256;index++)
	{
		*(lut+index)=__USAT((index + (1 << q_input_shift)) >> (1 + q_input_shift), 8);
	}
}

static void Precompute_8IntU(uint8_t *lut, float scale, int32_t zp, float scale_prepro, int32_t zp_prepro)
{
	for (int32_t i = 0 ; i < 256 ; i++)
	{
		float tmp = (i - zp_prepro) * scale_prepro;
		*(lut + i) = _CLAMP(zp + _ROUND(tmp * scale, int32_t), 0, 255, uint8_t);
	}
}

static void Precompute_8IntS(uint8_t *lut, float scale, int32_t zp, float scale_prepro, int32_t zp_prepro)
{
	for (int32_t i = 0 ; i < 256 ; i++)
	{
		float tmp = (i - zp_prepro) * scale_prepro;
		*(lut + i) = _CLAMP(zp + _ROUND(tmp * scale, int32_t),  -128, 127, int8_t);
	}
}


/**
 * @brief  Performs pixel R & B swapping
 */
void PREPROC_Pixel_RB_Swap(void *pSrc, void *pDst, uint32_t pixels)
{
	uint8_t tmp_r;

	RGB_typedef *pivot = (RGB_typedef *) pSrc;
	RGB_typedef *dest = (RGB_typedef *) pDst;

	for (int i = pixels-1; i >= 0; i--)
	{
		tmp_r=pivot[i].R;

		dest[i].R = pivot[i].B;
		dest[i].B = tmp_r;
		dest[i].G = pivot[i].G;
	}
}


/**
 * @brief Copies the source image pixels to the destination image buffer. The two buffers must have the same size.
 */
static void STM32Ipl_SimpleCopy(const uint8_t *src, uint8_t *dst, uint32_t size, bool reverse)
{
	// param 'reverse' forces the reversed processing (from the last to the first pixel)
	if (reverse) {
		src += size;
		dst += size;
		for (uint32_t i = 0; i < size; i++)
			*dst-- = *src--;
	} else {
		for (uint32_t i = 0; i < size; i++)
			*dst++ = *src++;
	}
}


static void Compute_pix_conv_tab() {
	uint8_t *lut = pixel_conv_lut;

	/*
	 * factors used for neural networks trained on data normalized in the range [-1, 1]
	 * source: https://wiki.st.com/stm32mcu/wiki/AI:How_to_use_Teachable_Machine_to_create_an_image_classification_application_on_STM32
	 */
	float prepro_scale = 127.5f;
	int32_t prepro_zp = 127;

	/*Retrieve the quantization scheme used to quantize the neural network*/
	switch(ai_get_input_quantization_scheme())
	{
		/*Pixel value conversion and normalization*/
		case AI_FXP_Q:
			Precompute_8FXP(lut, ai_get_input_quantized_format());
			break;
		case AI_UINT_Q:
			Precompute_8IntU(lut, ai_get_input_scale(), ai_get_input_zero_point(), prepro_scale, prepro_zp);
			break;
		case AI_SINT_Q:
			Precompute_8IntS(lut, ai_get_input_scale(), ai_get_input_zero_point(), prepro_scale, prepro_zp);
			break;
		default:
			break;
	}
}


/**
 * @brief get the destination buffer with R & B channel swapped and convert the bpp of the destination image if needed
 */
void InputBuffer_PreProcessing(uint8_t *bSrc, uint8_t *bDst)
{
	/*
	 * maybe we need to convert bDst in IMAGE_BPP_RGB565 (or other)
	 * it involves changes in 1.2 STM32Ipl_ConvertRev()
	 * at the moment this function is unused
	 */
	// 1. PREPROC_PixelFormatConversion()
	uint32_t nb_pixels = IMAGE_WIDTH * IMAGE_HEIGHT;
	int rb_swap = 0;

	// only if -> rb_swap = 1
	if(rb_swap) {
		PREPROC_Pixel_RB_Swap(bSrc, bDst, nb_pixels);
	}

	// 1.1 Image_CheckResizeMemoryLayout()
	uint32_t src_size = bufferBytes;
	uint32_t dst_size = bufferBytes;
	uint32_t src_start = (uint32_t)bSrc;
	uint32_t dst_start = (uint32_t)bDst;
	uint32_t src_end = src_start + src_size - 1;
	uint32_t dst_end = dst_start + dst_size - 1;
	bool reverse = false;

	if ((src_end > dst_start) && (dst_end >= src_end))
	{
		reverse = true;
	}

	// 1.2 STM32Ipl_ConvertRev()
	if (bSrc != bDst) {
		STM32Ipl_SimpleCopy(bSrc, bDst, dst_size, reverse);
	}
}


/**
 * @brief Performs pixel conversion from 8-bits integer to 8-bits quantized format expected by NN input with normalization
 */
void AI_PixelValueConversion_QuantizedNN(uint8_t *pSrc)
{
	const uint32_t nb_pixels = AI_NETWORK_IN_1_SIZE;
	const uint8_t *lut = pixel_conv_lut;
	uint8_t *pDst = (uint8_t *)data_in_1;

	if (pDst > pSrc)
	{
		for (int32_t i = nb_pixels - 1; i >= 0; i--)
		{
			pDst[i] = lut[pSrc[i]];
		}
	}
	else
	{
		for (int32_t i = 0; i < nb_pixels; i++)
		{
			pDst[i] = lut[pSrc[i]];
		}
	}
}


/**
 * @brief Performs the dequantization of a quantized NN output
 */
void AI_Output_Dequantize(void)
{
	/**Check format of the output and convert to float if required**/
	if(ai_get_output_format() == AI_BUFFER_FMT_TYPE_Q)
	{
		float scale;
		int32_t zero_point;
		ai_i8 *nn_output_i8;
		ai_u8 *nn_output_u8;
		float *nn_output_f32;

		/*Check what type of quantization scheme is used for the output*/
		switch(ai_get_output_quantization_scheme())
		{
		case AI_FXP_Q:

			scale=ai_get_output_fxp_scale();

			/* Dequantize NN output - in-place 8-bit to float conversion */
			nn_output_i8 = (ai_i8 *) data_out_1;
			nn_output_f32 = (float *) data_out_1;
			for(int32_t i = AI_NETWORK_OUT_1_SIZE - 1; i >= 0; i--)
			{
				float q_value = (float) *(nn_output_i8 + i);
				*(nn_output_f32 + i) = scale * q_value;
			}
			break;

		case AI_UINT_Q:

			scale = ai_get_output_scale();
			zero_point = ai_get_output_zero_point();

			/* Dequantize NN output - in-place 8-bit to float conversion */
			nn_output_u8 = (ai_u8 *) data_out_1;
			nn_output_f32 = (float *) data_out_1;
			for(int32_t i = AI_NETWORK_OUT_1_SIZE - 1; i >= 0; i--)
			{
				int32_t q_value = (int32_t) *(nn_output_u8 + i);
				*(nn_output_f32 + i) = scale * (q_value - zero_point);
			}
			break;

		case AI_SINT_Q:

			scale = ai_get_output_scale();
			zero_point = ai_get_output_zero_point();

			/* Dequantize NN output - in-place 8-bit to float conversion */
			nn_output_i8 = (ai_i8 *) data_out_1;
			nn_output_f32 = (float *) data_out_1;
			for(int32_t i = AI_NETWORK_OUT_1_SIZE - 1; i >= 0; i--)
			{
				int32_t q_value = (int32_t) *(nn_output_i8 + i);
				*(nn_output_f32 + i) = scale * (q_value - zero_point);
			}
			break;

		default:
			break;
		}
	}
}


void ai_process_requirements(void) {
	#if VERBOSE_LEVEL == 2
		printf("[%s:%d] requirements - copy the resized image array onto the nn image buffer \r\n", __FILE__, __LINE__);
	#elif VERBOSE_LEVEL == 1
		printf("ai requirements process phase \r\n");
	#endif

	// copy the array content [resize_image_buffr] onto the image buffer [image_input_buffer]
	// image_input_buffer = (uint8_t*)malloc(sizeof(uint8_t) * bufferBytes);
	// image_input_buffer = (uint8_t*)calloc(bufferBytes, sizeof(uint8_t));
	//	for(uint32_t i = 0; i < bufferBytes; i++)
	//	{
	//		*((uint8_t *)(image_input_buffer + i)) = image_buffer[i];
	//	}
}


void ai_process_preproc() {
	//	#if VERBOSE_LEVEL == 2
	//		printf("[%s:%d] preprocessing pt.1 - swap R&B channels and convert the bpp if needed \r\n", __FILE__, __LINE__);
	//	#elif VERBOSE_LEVEL == 1
	//		printf("ai preprocessing pt.1 \r\n");
	//	#endif

	// pre-process the input buffer and copy in onto a new one
	// image_preproc_buffer = (uint8_t*)malloc(sizeof(uint8_t) * bufferBytes);
	// Image_Buffer_Pre_Processing(image_input_buffer, image_preproc_buffer);
	// Image_Buffer_Pre_Processing((uint8_t *)image_buffer, image_preproc_buffer);

	#if VERBOSE_LEVEL == 2
		printf("[%s:%d] preprocessing pt.2 - PVC for quantized neural network\r\n", __FILE__, __LINE__);
	#elif VERBOSE_LEVEL == 1
		printf("ai preprocessing pt.2 \r\n");
	#endif

	// quantized neural network
	if(ai_get_input_format() == AI_BUFFER_FMT_TYPE_Q) {
		// AI_PixelValueConversion_QuantizedNN(image_input_buffer);
		// AI_PixelValueConversion_QuantizedNN(image_preproc_buffer);
		// AI_PixelValueConversion_QuantizedNN((uint8_t *)image_buffer);
		AI_PixelValueConversion_QuantizedNN((uint8_t *)image_buffer_resized);
	}
}


void ai_process_inference(void) {
	int res;
	uint32_t tinf_start;
	uint32_t tinf_stop;

	#if VERBOSE_LEVEL == 2
		printf("[%s:%d] inference - running the neural network \r\n", __FILE__, __LINE__);
	#elif VERBOSE_LEVEL == 1
		printf("inference \r\n");
	#endif

	tinf_start = HAL_GetTick();
	res = ai_run();
	if (res) {
		printf("[%s:%d] AI Error %d\r\n", __FILE__, __LINE__, res);
	}
	tinf_stop = HAL_GetTick();

	// inference time
	nn_inference_time = ((tinf_stop>tinf_start)?(tinf_stop-tinf_start):((1<<24)-tinf_start+tinf_stop));
}


void ai_process_postproc(void) {
	// NN ouput dequantization if required
	#if VERBOSE_LEVEL == 2
		printf("[%s:%d] postprocessing pt.1 - dequantize neural network's output \r\n", __FILE__, __LINE__);
	#elif VERBOSE_LEVEL == 1
		printf("ai postprocessing pt.1 \r\n");
	#endif

	AI_Output_Dequantize();

	// perform ranking
	#if VERBOSE_LEVEL == 2
		printf("[%s:%d] postprocessing pt.2 - perform ranking with bubblesort \r\n", __FILE__, __LINE__);
	#elif VERBOSE_LEVEL == 1
		printf("ai postprocessing pt.2 \r\n");
	#endif

	// setup the ranking array for the ai classes
	for (int i = 0; i < AI_NETWORK_OUT_1_SIZE; i++) ranking[i] = i;

	// sorts the inference output into the ranking array
	UTILS_Bubblesort((float*)(data_out_1), ranking, AI_NETWORK_OUT_1_SIZE);
}


void ai_process_display(void) {
	// BSP_LCD_DisplayStringAtLine() displays a maximum of 60 characters on the LCD
	char msg[60];
	int x = 10;
	const int nn_top_n_display = 3;

	// App_Output_Display()
	#if VERBOSE_LEVEL == 2
		printf("[%s:%d] inference results: \r\n", __FILE__, __LINE__);
	#elif VERBOSE_LEVEL == 1 || VERBOSE_LEVEL == 0
		printf("inference results: \r\n");
	#endif

	sprintf(msg, "Inference results:");
	BSP_LCD_DisplayStringAtLine(x++, (uint8_t*)msg);

	for (int i = 0; i < nn_top_n_display; i++)
	{
		#if VERBOSE_LEVEL == 2
			printf("[%s:%d] %i) %s -> %.1f%% \r\n", __FILE__, __LINE__, (i+1), output_labels[ranking[i]], *((float*)(data_out_1)+i) * 100);
		#elif VERBOSE_LEVEL == 1 || VERBOSE_LEVEL == 0
			printf("%i) %s -> %.1f%% \r\n", (i+1), output_labels[ranking[i]], *((float*)(data_out_1)+i) * 100);
		#endif

		sprintf(msg, "%i) %s -> %.1f%%", (i+1), output_labels[ranking[i]], *((float*)(data_out_1)+i) * 100);
		BSP_LCD_DisplayStringAtLine(x++, (uint8_t*)msg);
	}

	#if VERBOSE_LEVEL == 2
		printf("[%s:%d] inference time: %ldms \r\n", __FILE__, __LINE__, nn_inference_time);
	#elif VERBOSE_LEVEL == 1 || VERBOSE_LEVEL == 0
		printf("inference time: %ldms \r\n", nn_inference_time);
	#endif

	x++;

	sprintf(msg, "Inference time:");
	BSP_LCD_DisplayStringAtLine(x++, (uint8_t*)msg);

	sprintf(msg, "%ldms", nn_inference_time);
	BSP_LCD_DisplayStringAtLine(x, (uint8_t*)msg);

	#if VERBOSE_LEVEL == 2
		printf("[%s:%d] end \r\n", __FILE__, __LINE__);
	#endif
}

/* USER CODE END 2 */

/* Entry points --------------------------------------------------------------*/

void MX_X_CUBE_AI_Init(void)
{
    BSP_SDRAM_Init();
    /* USER CODE BEGIN 5 */

	/** @brief Initialize network */
	ai_boostrap(data_activations0);

	/** @brief {optional} for debug/log purpose */
	ai_network_report report;
	if (ai_network_get_report(network, &report) != true) {
		printf("ai get report error\r\n");
	}

	// printf("Model name : %s\r\n", report.model_name);
	// printf("Model signature : %s\r\n", report.model_signature);

	// ai_input = &report.inputs[0];
	// ai_output = &report.outputs[0];
	// printf("input[0] : (%lu, %lu, %lu)\r\n", AI_BUFFER_SHAPE_ELEM(ai_input, AI_SHAPE_HEIGHT),
	//										    AI_BUFFER_SHAPE_ELEM(ai_input, AI_SHAPE_WIDTH),
	//										    AI_BUFFER_SHAPE_ELEM(ai_input, AI_SHAPE_CHANNEL));
	// printf("output[0] : (%lu, %lu, %lu)\r\n", AI_BUFFER_SHAPE_ELEM(ai_output, AI_SHAPE_HEIGHT),
	//										     AI_BUFFER_SHAPE_ELEM(ai_output, AI_SHAPE_WIDTH),
	//										     AI_BUFFER_SHAPE_ELEM(ai_output, AI_SHAPE_CHANNEL));

	// requirements
	Compute_pix_conv_tab();

    /* USER CODE END 5 */
}

void MX_X_CUBE_AI_Process(void)
{
    /* USER CODE BEGIN 6 */

	/* ------------------- REQUIREMENTS -------------------- */
	// ai_process_requirements();

	/* ------------------ PRE-PROCESSING ------------------- */
	ai_process_preproc();

	/* -------------------- INFERENCE ---------------------- */
	ai_process_inference();

	/* ------------------ POST-PROCESSING ------------------ */
	ai_process_postproc();

	/* ----------------- INFERENCE RESULTS ----------------- */
	ai_process_display();

    /* USER CODE END 6 */
}
#ifdef __cplusplus
}
#endif
