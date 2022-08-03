/**
 ******************************************************************************
 * @file	: utils.h
 * @brief	: utilities used around the program
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

#ifndef __utils_H
#define __utils_H

/* Includes ----------------------------------------------------------------------------*/
#include "usb_host.h"
#include "libjpeg.h"


/* Types -------------------------------------------------------------------------------*/
typedef struct RGB
{
	uint8_t R;
	uint8_t G;
	uint8_t B;
} RGB_typedef;


/* Defines -----------------------------------------------------------------------------*/
// LCD screen (start address and sizes)
#define LCD_BUFFER			0xD0000000
#define LCD_HEIGHT			320
#define LCD_WIDTH			240
// image and buffer sizes (equal to the size of the neural network input)
#define IMAGE_HEIGHT		224
#define IMAGE_WIDTH			224
#define IMAGE_BPP			3
// dimension in bytes of the image's buffer (WIDTH x HEIGHT x RGB_888_BPP)
#define IMGBUFFERSIZE		IMAGE_WIDTH * IMAGE_HEIGHT * IMAGE_BPP
// AI parameters
#define AI_CLASSES			{"Apple Pie", "Beer", "Caesar Salad", "Cappuccino", "Cheesecake", "Chicken Wings",  \
							"Chocolate Cake", "Coke", "Cup Cakes", "Donuts", "French Fries", "Hamburger",  \
							"HotDog", "Lasagna", "Pizza", "Risotto", "Spaghetti Bolognese", "Steak"};
#define AI_IN_NORM_SCALE	255.0f
#define AI_IN_NORM_ZP		0
#define AI_TOP_N_RESULTS	1
// absolute address of the folder on the USB drive where the images are located
#define PATH_TO_JPEGS		"/food"
// verbose option : [0-2] (the higher the value, the more info will be printed )
#define VERBOSE_LEVEL		1


/* Variables ---------------------------------------------------------------------------*/
// USB host application status
extern ApplicationTypeDef Appli_state;
// buffers
extern uint8_t *scanline_buffer;
extern uint8_t *image_buffer;
extern __attribute__((section(".extram"))) uint8_t image_buffer_resized[IMGBUFFERSIZE];


/* Function prototypes -----------------------------------------------------------------*/
void UTILS_ResizeBuffer(const uint8_t* input, uint8_t* output, int srcW, int srcH, int dstW, int dstH);
void UTILS_Bubblesort(float *prob, int *classes, int size);

#endif /* __utils_H */
