/**
  ******************************************************************************
  * @file    network.c
  * @author  AST Embedded Analytics Research Platform
  * @date    Wed Aug  3 16:49:59 2022
  * @brief   AI Tool Automatic Code Generator for Embedded NN computing
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2017 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  ******************************************************************************
  */


#include "network.h"
#include "network_data.h"

#include "ai_platform.h"
#include "ai_platform_interface.h"
#include "ai_math_helpers.h"

#include "core_common.h"
#include "core_convert.h"

#include "layers.h"




#undef AI_NET_OBJ_INSTANCE
#define AI_NET_OBJ_INSTANCE g_network
 
#undef AI_NETWORK_MODEL_SIGNATURE
#define AI_NETWORK_MODEL_SIGNATURE     "1f5a7ae86308bf74a8d7be98358877a9"

#ifndef AI_TOOLS_REVISION_ID
#define AI_TOOLS_REVISION_ID     ""
#endif

#undef AI_TOOLS_DATE_TIME
#define AI_TOOLS_DATE_TIME   "Wed Aug  3 16:49:59 2022"

#undef AI_TOOLS_COMPILE_TIME
#define AI_TOOLS_COMPILE_TIME    __DATE__ " " __TIME__

#undef AI_NETWORK_N_BATCHES
#define AI_NETWORK_N_BATCHES         (1)




/**  Array declarations section  **********************************************/
/* Array#0 */
AI_ARRAY_OBJ_DECLARE(
  quantize_input_2_output_array, AI_ARRAY_FORMAT_U8|AI_FMT_FLAG_IS_IO,
  NULL, NULL, 150529, AI_STATIC)

/* Array#1 */
AI_ARRAY_OBJ_DECLARE(
  quantize_conv1_conv2d_output_array, AI_ARRAY_FORMAT_U8,
  NULL, NULL, 100352, AI_STATIC)

/* Array#2 */
AI_ARRAY_OBJ_DECLARE(
  quantize_conv_dw_1_conv2d_output_array, AI_ARRAY_FORMAT_U8,
  NULL, NULL, 25088, AI_STATIC)

/* Array#3 */
AI_ARRAY_OBJ_DECLARE(
  quantize_conv_pw_1_conv2d_output_array, AI_ARRAY_FORMAT_U8,
  NULL, NULL, 50176, AI_STATIC)

/* Array#4 */
AI_ARRAY_OBJ_DECLARE(
  quantize_conv_dw_2_conv2d_output_array, AI_ARRAY_FORMAT_U8,
  NULL, NULL, 12544, AI_STATIC)

/* Array#5 */
AI_ARRAY_OBJ_DECLARE(
  quantize_conv_pw_2_conv2d_output_array, AI_ARRAY_FORMAT_U8,
  NULL, NULL, 25088, AI_STATIC)

/* Array#6 */
AI_ARRAY_OBJ_DECLARE(
  quantize_conv_dw_3_conv2d_output_array, AI_ARRAY_FORMAT_U8,
  NULL, NULL, 25088, AI_STATIC)

/* Array#7 */
AI_ARRAY_OBJ_DECLARE(
  quantize_conv_pw_3_conv2d_output_array, AI_ARRAY_FORMAT_U8,
  NULL, NULL, 25088, AI_STATIC)

/* Array#8 */
AI_ARRAY_OBJ_DECLARE(
  quantize_conv_dw_4_conv2d_output_array, AI_ARRAY_FORMAT_U8,
  NULL, NULL, 6272, AI_STATIC)

/* Array#9 */
AI_ARRAY_OBJ_DECLARE(
  quantize_conv_pw_4_conv2d_output_array, AI_ARRAY_FORMAT_U8,
  NULL, NULL, 12544, AI_STATIC)

/* Array#10 */
AI_ARRAY_OBJ_DECLARE(
  quantize_conv_dw_5_conv2d_output_array, AI_ARRAY_FORMAT_U8,
  NULL, NULL, 12544, AI_STATIC)

/* Array#11 */
AI_ARRAY_OBJ_DECLARE(
  quantize_conv_pw_5_conv2d_output_array, AI_ARRAY_FORMAT_U8,
  NULL, NULL, 12544, AI_STATIC)

/* Array#12 */
AI_ARRAY_OBJ_DECLARE(
  quantize_conv_dw_6_conv2d_output_array, AI_ARRAY_FORMAT_U8,
  NULL, NULL, 3136, AI_STATIC)

/* Array#13 */
AI_ARRAY_OBJ_DECLARE(
  quantize_conv_pw_6_conv2d_output_array, AI_ARRAY_FORMAT_U8,
  NULL, NULL, 6272, AI_STATIC)

/* Array#14 */
AI_ARRAY_OBJ_DECLARE(
  quantize_conv_dw_7_conv2d_output_array, AI_ARRAY_FORMAT_U8,
  NULL, NULL, 6272, AI_STATIC)

/* Array#15 */
AI_ARRAY_OBJ_DECLARE(
  quantize_conv_pw_7_conv2d_output_array, AI_ARRAY_FORMAT_U8,
  NULL, NULL, 6272, AI_STATIC)

/* Array#16 */
AI_ARRAY_OBJ_DECLARE(
  quantize_conv_dw_8_conv2d_output_array, AI_ARRAY_FORMAT_U8,
  NULL, NULL, 6272, AI_STATIC)

/* Array#17 */
AI_ARRAY_OBJ_DECLARE(
  quantize_conv_pw_8_conv2d_output_array, AI_ARRAY_FORMAT_U8,
  NULL, NULL, 6272, AI_STATIC)

/* Array#18 */
AI_ARRAY_OBJ_DECLARE(
  quantize_conv_dw_9_conv2d_output_array, AI_ARRAY_FORMAT_U8,
  NULL, NULL, 6272, AI_STATIC)

/* Array#19 */
AI_ARRAY_OBJ_DECLARE(
  quantize_conv_pw_9_conv2d_output_array, AI_ARRAY_FORMAT_U8,
  NULL, NULL, 6272, AI_STATIC)

/* Array#20 */
AI_ARRAY_OBJ_DECLARE(
  quantize_conv_dw_10_conv2d_output_array, AI_ARRAY_FORMAT_U8,
  NULL, NULL, 6272, AI_STATIC)

/* Array#21 */
AI_ARRAY_OBJ_DECLARE(
  quantize_conv_pw_10_conv2d_output_array, AI_ARRAY_FORMAT_U8,
  NULL, NULL, 6272, AI_STATIC)

/* Array#22 */
AI_ARRAY_OBJ_DECLARE(
  quantize_conv_dw_11_conv2d_output_array, AI_ARRAY_FORMAT_U8,
  NULL, NULL, 6272, AI_STATIC)

/* Array#23 */
AI_ARRAY_OBJ_DECLARE(
  quantize_conv_pw_11_conv2d_output_array, AI_ARRAY_FORMAT_U8,
  NULL, NULL, 256, AI_STATIC)

/* Array#24 */
AI_ARRAY_OBJ_DECLARE(
  quantize_conv_preds_conv2d_output_array, AI_ARRAY_FORMAT_U8,
  NULL, NULL, 18, AI_STATIC)

/* Array#25 */
AI_ARRAY_OBJ_DECLARE(
  quantize_conv_preds_conv2d_0_conversion_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 18, AI_STATIC)

/* Array#26 */
AI_ARRAY_OBJ_DECLARE(
  act_softmax_output_array, AI_ARRAY_FORMAT_FLOAT|AI_FMT_FLAG_IS_IO,
  NULL, NULL, 18, AI_STATIC)

/* Array#27 */
AI_ARRAY_OBJ_DECLARE(
  quantize_conv1_conv2d_weights_array, AI_ARRAY_FORMAT_U8,
  NULL, NULL, 216, AI_STATIC)

/* Array#28 */
AI_ARRAY_OBJ_DECLARE(
  quantize_conv1_conv2d_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 8, AI_STATIC)

/* Array#29 */
AI_ARRAY_OBJ_DECLARE(
  quantize_conv_dw_1_conv2d_weights_array, AI_ARRAY_FORMAT_U8,
  NULL, NULL, 72, AI_STATIC)

/* Array#30 */
AI_ARRAY_OBJ_DECLARE(
  quantize_conv_dw_1_conv2d_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 8, AI_STATIC)

/* Array#31 */
AI_ARRAY_OBJ_DECLARE(
  quantize_conv_pw_1_conv2d_weights_array, AI_ARRAY_FORMAT_U8,
  NULL, NULL, 128, AI_STATIC)

/* Array#32 */
AI_ARRAY_OBJ_DECLARE(
  quantize_conv_pw_1_conv2d_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 16, AI_STATIC)

/* Array#33 */
AI_ARRAY_OBJ_DECLARE(
  quantize_conv_dw_2_conv2d_weights_array, AI_ARRAY_FORMAT_U8,
  NULL, NULL, 144, AI_STATIC)

/* Array#34 */
AI_ARRAY_OBJ_DECLARE(
  quantize_conv_dw_2_conv2d_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 16, AI_STATIC)

/* Array#35 */
AI_ARRAY_OBJ_DECLARE(
  quantize_conv_pw_2_conv2d_weights_array, AI_ARRAY_FORMAT_U8,
  NULL, NULL, 512, AI_STATIC)

/* Array#36 */
AI_ARRAY_OBJ_DECLARE(
  quantize_conv_pw_2_conv2d_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 32, AI_STATIC)

/* Array#37 */
AI_ARRAY_OBJ_DECLARE(
  quantize_conv_dw_3_conv2d_weights_array, AI_ARRAY_FORMAT_U8,
  NULL, NULL, 288, AI_STATIC)

/* Array#38 */
AI_ARRAY_OBJ_DECLARE(
  quantize_conv_dw_3_conv2d_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 32, AI_STATIC)

/* Array#39 */
AI_ARRAY_OBJ_DECLARE(
  quantize_conv_pw_3_conv2d_weights_array, AI_ARRAY_FORMAT_U8,
  NULL, NULL, 1024, AI_STATIC)

/* Array#40 */
AI_ARRAY_OBJ_DECLARE(
  quantize_conv_pw_3_conv2d_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 32, AI_STATIC)

/* Array#41 */
AI_ARRAY_OBJ_DECLARE(
  quantize_conv_dw_4_conv2d_weights_array, AI_ARRAY_FORMAT_U8,
  NULL, NULL, 288, AI_STATIC)

/* Array#42 */
AI_ARRAY_OBJ_DECLARE(
  quantize_conv_dw_4_conv2d_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 32, AI_STATIC)

/* Array#43 */
AI_ARRAY_OBJ_DECLARE(
  quantize_conv_pw_4_conv2d_weights_array, AI_ARRAY_FORMAT_U8,
  NULL, NULL, 2048, AI_STATIC)

/* Array#44 */
AI_ARRAY_OBJ_DECLARE(
  quantize_conv_pw_4_conv2d_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 64, AI_STATIC)

/* Array#45 */
AI_ARRAY_OBJ_DECLARE(
  quantize_conv_dw_5_conv2d_weights_array, AI_ARRAY_FORMAT_U8,
  NULL, NULL, 576, AI_STATIC)

/* Array#46 */
AI_ARRAY_OBJ_DECLARE(
  quantize_conv_dw_5_conv2d_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 64, AI_STATIC)

/* Array#47 */
AI_ARRAY_OBJ_DECLARE(
  quantize_conv_pw_5_conv2d_weights_array, AI_ARRAY_FORMAT_U8,
  NULL, NULL, 4096, AI_STATIC)

/* Array#48 */
AI_ARRAY_OBJ_DECLARE(
  quantize_conv_pw_5_conv2d_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 64, AI_STATIC)

/* Array#49 */
AI_ARRAY_OBJ_DECLARE(
  quantize_conv_dw_6_conv2d_weights_array, AI_ARRAY_FORMAT_U8,
  NULL, NULL, 576, AI_STATIC)

/* Array#50 */
AI_ARRAY_OBJ_DECLARE(
  quantize_conv_dw_6_conv2d_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 64, AI_STATIC)

/* Array#51 */
AI_ARRAY_OBJ_DECLARE(
  quantize_conv_pw_6_conv2d_weights_array, AI_ARRAY_FORMAT_U8,
  NULL, NULL, 8192, AI_STATIC)

/* Array#52 */
AI_ARRAY_OBJ_DECLARE(
  quantize_conv_pw_6_conv2d_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 128, AI_STATIC)

/* Array#53 */
AI_ARRAY_OBJ_DECLARE(
  quantize_conv_dw_7_conv2d_weights_array, AI_ARRAY_FORMAT_U8,
  NULL, NULL, 1152, AI_STATIC)

/* Array#54 */
AI_ARRAY_OBJ_DECLARE(
  quantize_conv_dw_7_conv2d_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 128, AI_STATIC)

/* Array#55 */
AI_ARRAY_OBJ_DECLARE(
  quantize_conv_pw_7_conv2d_weights_array, AI_ARRAY_FORMAT_U8,
  NULL, NULL, 16384, AI_STATIC)

/* Array#56 */
AI_ARRAY_OBJ_DECLARE(
  quantize_conv_pw_7_conv2d_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 128, AI_STATIC)

/* Array#57 */
AI_ARRAY_OBJ_DECLARE(
  quantize_conv_dw_8_conv2d_weights_array, AI_ARRAY_FORMAT_U8,
  NULL, NULL, 1152, AI_STATIC)

/* Array#58 */
AI_ARRAY_OBJ_DECLARE(
  quantize_conv_dw_8_conv2d_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 128, AI_STATIC)

/* Array#59 */
AI_ARRAY_OBJ_DECLARE(
  quantize_conv_pw_8_conv2d_weights_array, AI_ARRAY_FORMAT_U8,
  NULL, NULL, 16384, AI_STATIC)

/* Array#60 */
AI_ARRAY_OBJ_DECLARE(
  quantize_conv_pw_8_conv2d_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 128, AI_STATIC)

/* Array#61 */
AI_ARRAY_OBJ_DECLARE(
  quantize_conv_dw_9_conv2d_weights_array, AI_ARRAY_FORMAT_U8,
  NULL, NULL, 1152, AI_STATIC)

/* Array#62 */
AI_ARRAY_OBJ_DECLARE(
  quantize_conv_dw_9_conv2d_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 128, AI_STATIC)

/* Array#63 */
AI_ARRAY_OBJ_DECLARE(
  quantize_conv_pw_9_conv2d_weights_array, AI_ARRAY_FORMAT_U8,
  NULL, NULL, 16384, AI_STATIC)

/* Array#64 */
AI_ARRAY_OBJ_DECLARE(
  quantize_conv_pw_9_conv2d_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 128, AI_STATIC)

/* Array#65 */
AI_ARRAY_OBJ_DECLARE(
  quantize_conv_dw_10_conv2d_weights_array, AI_ARRAY_FORMAT_U8,
  NULL, NULL, 1152, AI_STATIC)

/* Array#66 */
AI_ARRAY_OBJ_DECLARE(
  quantize_conv_dw_10_conv2d_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 128, AI_STATIC)

/* Array#67 */
AI_ARRAY_OBJ_DECLARE(
  quantize_conv_pw_10_conv2d_weights_array, AI_ARRAY_FORMAT_U8,
  NULL, NULL, 16384, AI_STATIC)

/* Array#68 */
AI_ARRAY_OBJ_DECLARE(
  quantize_conv_pw_10_conv2d_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 128, AI_STATIC)

/* Array#69 */
AI_ARRAY_OBJ_DECLARE(
  quantize_conv_dw_11_conv2d_weights_array, AI_ARRAY_FORMAT_U8,
  NULL, NULL, 1152, AI_STATIC)

/* Array#70 */
AI_ARRAY_OBJ_DECLARE(
  quantize_conv_dw_11_conv2d_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 128, AI_STATIC)

/* Array#71 */
AI_ARRAY_OBJ_DECLARE(
  quantize_conv_pw_11_conv2d_weights_array, AI_ARRAY_FORMAT_U8,
  NULL, NULL, 32768, AI_STATIC)

/* Array#72 */
AI_ARRAY_OBJ_DECLARE(
  quantize_conv_pw_11_conv2d_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 256, AI_STATIC)

/* Array#73 */
AI_ARRAY_OBJ_DECLARE(
  quantize_conv_preds_conv2d_weights_array, AI_ARRAY_FORMAT_U8,
  NULL, NULL, 4608, AI_STATIC)

/* Array#74 */
AI_ARRAY_OBJ_DECLARE(
  quantize_conv_preds_conv2d_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 18, AI_STATIC)

/* Array#75 */
AI_ARRAY_OBJ_DECLARE(
  quantize_conv1_conv2d_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 572, AI_STATIC)

/* Array#76 */
AI_ARRAY_OBJ_DECLARE(
  quantize_conv_dw_1_conv2d_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 217, AI_STATIC)

/* Array#77 */
AI_ARRAY_OBJ_DECLARE(
  quantize_conv_pw_1_conv2d_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 32, AI_STATIC)

/* Array#78 */
AI_ARRAY_OBJ_DECLARE(
  quantize_conv_dw_2_conv2d_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 433, AI_STATIC)

/* Array#79 */
AI_ARRAY_OBJ_DECLARE(
  quantize_conv_pw_2_conv2d_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 64, AI_STATIC)

/* Array#80 */
AI_ARRAY_OBJ_DECLARE(
  quantize_conv_dw_3_conv2d_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 865, AI_STATIC)

/* Array#81 */
AI_ARRAY_OBJ_DECLARE(
  quantize_conv_pw_3_conv2d_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 128, AI_STATIC)

/* Array#82 */
AI_ARRAY_OBJ_DECLARE(
  quantize_conv_dw_4_conv2d_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 865, AI_STATIC)

/* Array#83 */
AI_ARRAY_OBJ_DECLARE(
  quantize_conv_pw_4_conv2d_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 128, AI_STATIC)

/* Array#84 */
AI_ARRAY_OBJ_DECLARE(
  quantize_conv_dw_5_conv2d_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 1729, AI_STATIC)

/* Array#85 */
AI_ARRAY_OBJ_DECLARE(
  quantize_conv_pw_5_conv2d_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 256, AI_STATIC)

/* Array#86 */
AI_ARRAY_OBJ_DECLARE(
  quantize_conv_dw_6_conv2d_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 1729, AI_STATIC)

/* Array#87 */
AI_ARRAY_OBJ_DECLARE(
  quantize_conv_pw_6_conv2d_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 256, AI_STATIC)

/* Array#88 */
AI_ARRAY_OBJ_DECLARE(
  quantize_conv_dw_7_conv2d_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 3457, AI_STATIC)

/* Array#89 */
AI_ARRAY_OBJ_DECLARE(
  quantize_conv_pw_7_conv2d_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 512, AI_STATIC)

/* Array#90 */
AI_ARRAY_OBJ_DECLARE(
  quantize_conv_dw_8_conv2d_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 3457, AI_STATIC)

/* Array#91 */
AI_ARRAY_OBJ_DECLARE(
  quantize_conv_pw_8_conv2d_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 512, AI_STATIC)

/* Array#92 */
AI_ARRAY_OBJ_DECLARE(
  quantize_conv_dw_9_conv2d_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 3457, AI_STATIC)

/* Array#93 */
AI_ARRAY_OBJ_DECLARE(
  quantize_conv_pw_9_conv2d_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 512, AI_STATIC)

/* Array#94 */
AI_ARRAY_OBJ_DECLARE(
  quantize_conv_dw_10_conv2d_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 3457, AI_STATIC)

/* Array#95 */
AI_ARRAY_OBJ_DECLARE(
  quantize_conv_pw_10_conv2d_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 512, AI_STATIC)

/* Array#96 */
AI_ARRAY_OBJ_DECLARE(
  quantize_conv_dw_11_conv2d_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 3457, AI_STATIC)

/* Array#97 */
AI_ARRAY_OBJ_DECLARE(
  quantize_conv_pw_11_conv2d_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 512, AI_STATIC)

/* Array#98 */
AI_ARRAY_OBJ_DECLARE(
  quantize_conv_pw_11_conv2d_scratch1_array, AI_ARRAY_FORMAT_U8,
  NULL, NULL, 12544, AI_STATIC)

/* Array#99 */
AI_ARRAY_OBJ_DECLARE(
  quantize_conv_preds_conv2d_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 1024, AI_STATIC)

/**  Array metadata declarations section  *************************************/
/* Int quant #0 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(quantize_input_2_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_U8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.00392156862745098f),
    AI_PACK_UINTQ_ZP(0)))

/* Int quant #1 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(quantize_conv1_conv2d_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_U8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.06043581495098039f),
    AI_PACK_UINTQ_ZP(0)))

/* Int quant #2 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(quantize_conv_dw_1_conv2d_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_U8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.12466589235791974f),
    AI_PACK_UINTQ_ZP(102)))

/* Int quant #3 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(quantize_conv_pw_1_conv2d_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_U8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.042776081608790976f),
    AI_PACK_UINTQ_ZP(0)))

/* Int quant #4 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(quantize_conv_dw_2_conv2d_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_U8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.08005018421247893f),
    AI_PACK_UINTQ_ZP(137)))

/* Int quant #5 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(quantize_conv_pw_2_conv2d_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_U8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.09826159009746477f),
    AI_PACK_UINTQ_ZP(0)))

/* Int quant #6 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(quantize_conv_dw_3_conv2d_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_U8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.17465208464977788f),
    AI_PACK_UINTQ_ZP(151)))

/* Int quant #7 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(quantize_conv_pw_3_conv2d_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_U8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.07594745112400429f),
    AI_PACK_UINTQ_ZP(0)))

/* Int quant #8 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(quantize_conv_dw_4_conv2d_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_U8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.17589300567028568f),
    AI_PACK_UINTQ_ZP(120)))

/* Int quant #9 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(quantize_conv_pw_4_conv2d_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_U8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.051303796207203586f),
    AI_PACK_UINTQ_ZP(0)))

/* Int quant #10 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(quantize_conv_dw_5_conv2d_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_U8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.10018726797664866f),
    AI_PACK_UINTQ_ZP(115)))

/* Int quant #11 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(quantize_conv_pw_5_conv2d_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_U8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.05154530768300973f),
    AI_PACK_UINTQ_ZP(0)))

/* Int quant #12 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(quantize_conv_dw_6_conv2d_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_U8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.13034195619470934f),
    AI_PACK_UINTQ_ZP(118)))

/* Int quant #13 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(quantize_conv_pw_6_conv2d_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_U8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.04841501572552849f),
    AI_PACK_UINTQ_ZP(0)))

/* Int quant #14 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(quantize_conv_dw_7_conv2d_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_U8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.09044197306913489f),
    AI_PACK_UINTQ_ZP(121)))

/* Int quant #15 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(quantize_conv_pw_7_conv2d_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_U8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.04083850337009804f),
    AI_PACK_UINTQ_ZP(0)))

/* Int quant #16 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(quantize_conv_dw_8_conv2d_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_U8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.08513087478338503f),
    AI_PACK_UINTQ_ZP(108)))

/* Int quant #17 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(quantize_conv_pw_8_conv2d_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_U8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.04356102288938036f),
    AI_PACK_UINTQ_ZP(0)))

/* Int quant #18 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(quantize_conv_dw_9_conv2d_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_U8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.10167093463972503f),
    AI_PACK_UINTQ_ZP(137)))

/* Int quant #19 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(quantize_conv_pw_9_conv2d_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_U8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.05073295294069776f),
    AI_PACK_UINTQ_ZP(0)))

/* Int quant #20 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(quantize_conv_dw_10_conv2d_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_U8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.10075566534902536f),
    AI_PACK_UINTQ_ZP(135)))

/* Int quant #21 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(quantize_conv_pw_10_conv2d_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_U8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.04852033876905254f),
    AI_PACK_UINTQ_ZP(0)))

/* Int quant #22 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(quantize_conv_dw_11_conv2d_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_U8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.14729990117690142f),
    AI_PACK_UINTQ_ZP(148)))

/* Int quant #23 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(quantize_conv_pw_11_conv2d_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_U8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.019141720790489047f),
    AI_PACK_UINTQ_ZP(0)))

/* Int quant #24 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(quantize_conv_preds_conv2d_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_U8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.19155238282446768f),
    AI_PACK_UINTQ_ZP(157)))

/* Int quant #25 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(quantize_conv1_conv2d_weights_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_U8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.028749657612220914f),
    AI_PACK_UINTQ_ZP(145)))

/* Int quant #26 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(quantize_conv_dw_1_conv2d_weights_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_U8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.00546043784010644f),
    AI_PACK_UINTQ_ZP(134)))

/* Int quant #27 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(quantize_conv_pw_1_conv2d_weights_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_U8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0068471618727141735f),
    AI_PACK_UINTQ_ZP(125)))

/* Int quant #28 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(quantize_conv_dw_2_conv2d_weights_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_U8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.005415800038506003f),
    AI_PACK_UINTQ_ZP(126)))

/* Int quant #29 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(quantize_conv_pw_2_conv2d_weights_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_U8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.022798767276838713f),
    AI_PACK_UINTQ_ZP(134)))

/* Int quant #30 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(quantize_conv_dw_3_conv2d_weights_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_U8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.009301249186197917f),
    AI_PACK_UINTQ_ZP(131)))

/* Int quant #31 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(quantize_conv_pw_3_conv2d_weights_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_U8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.007141224075766171f),
    AI_PACK_UINTQ_ZP(142)))

/* Int quant #32 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(quantize_conv_dw_4_conv2d_weights_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_U8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.00672833662407071f),
    AI_PACK_UINTQ_ZP(120)))

/* Int quant #33 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(quantize_conv_pw_4_conv2d_weights_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_U8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.007368923869787478f),
    AI_PACK_UINTQ_ZP(116)))

/* Int quant #34 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(quantize_conv_dw_5_conv2d_weights_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_U8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.008096037658990599f),
    AI_PACK_UINTQ_ZP(125)))

/* Int quant #35 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(quantize_conv_pw_5_conv2d_weights_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_U8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.00600513406828338f),
    AI_PACK_UINTQ_ZP(111)))

/* Int quant #36 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(quantize_conv_dw_6_conv2d_weights_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_U8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.006019722246656231f),
    AI_PACK_UINTQ_ZP(115)))

/* Int quant #37 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(quantize_conv_pw_6_conv2d_weights_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_U8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0038148716384289313f),
    AI_PACK_UINTQ_ZP(120)))

/* Int quant #38 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(quantize_conv_dw_7_conv2d_weights_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_U8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.009372077268712661f),
    AI_PACK_UINTQ_ZP(117)))

/* Int quant #39 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(quantize_conv_pw_7_conv2d_weights_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_U8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0053149405647726616f),
    AI_PACK_UINTQ_ZP(118)))

/* Int quant #40 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(quantize_conv_dw_8_conv2d_weights_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_U8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.009086904338761873f),
    AI_PACK_UINTQ_ZP(117)))

/* Int quant #41 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(quantize_conv_pw_8_conv2d_weights_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_U8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.004248616625280941f),
    AI_PACK_UINTQ_ZP(145)))

/* Int quant #42 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(quantize_conv_dw_9_conv2d_weights_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_U8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.009203201181748335f),
    AI_PACK_UINTQ_ZP(130)))

/* Int quant #43 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(quantize_conv_pw_9_conv2d_weights_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_U8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.003779377306208891f),
    AI_PACK_UINTQ_ZP(128)))

/* Int quant #44 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(quantize_conv_dw_10_conv2d_weights_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_U8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.007860970029643938f),
    AI_PACK_UINTQ_ZP(129)))

/* Int quant #45 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(quantize_conv_pw_10_conv2d_weights_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_U8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.003648709549623377f),
    AI_PACK_UINTQ_ZP(136)))

/* Int quant #46 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(quantize_conv_dw_11_conv2d_weights_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_U8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0070540493609858495f),
    AI_PACK_UINTQ_ZP(104)))

/* Int quant #47 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(quantize_conv_pw_11_conv2d_weights_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_U8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0050823321529463224f),
    AI_PACK_UINTQ_ZP(127)))

/* Int quant #48 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(quantize_conv_preds_conv2d_weights_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_U8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.009781416724709904f),
    AI_PACK_UINTQ_ZP(149)))

/* Int quant #49 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(quantize_conv_pw_11_conv2d_scratch1_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_U8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.06917480019962087f),
    AI_PACK_UINTQ_ZP(0)))

/**  Tensor declarations section  *********************************************/
/* Tensor #0 */
AI_TENSOR_OBJ_DECLARE(
  quantize_input_2_output, AI_STATIC,
  0, 0x1,
  AI_SHAPE_INIT(4, 1, 3, 224, 224), AI_STRIDE_INIT(4, 1, 1, 3, 672),
  1, &quantize_input_2_output_array, &quantize_input_2_output_array_intq)

/* Tensor #1 */
AI_TENSOR_OBJ_DECLARE(
  quantize_conv1_conv2d_output, AI_STATIC,
  1, 0x1,
  AI_SHAPE_INIT(4, 1, 8, 112, 112), AI_STRIDE_INIT(4, 1, 1, 8, 896),
  1, &quantize_conv1_conv2d_output_array, &quantize_conv1_conv2d_output_array_intq)

/* Tensor #2 */
AI_TENSOR_OBJ_DECLARE(
  quantize_conv_dw_1_conv2d_output, AI_STATIC,
  2, 0x1,
  AI_SHAPE_INIT(4, 1, 8, 56, 56), AI_STRIDE_INIT(4, 1, 1, 8, 448),
  1, &quantize_conv_dw_1_conv2d_output_array, &quantize_conv_dw_1_conv2d_output_array_intq)

/* Tensor #3 */
AI_TENSOR_OBJ_DECLARE(
  quantize_conv_pw_1_conv2d_output, AI_STATIC,
  3, 0x1,
  AI_SHAPE_INIT(4, 1, 16, 56, 56), AI_STRIDE_INIT(4, 1, 1, 16, 896),
  1, &quantize_conv_pw_1_conv2d_output_array, &quantize_conv_pw_1_conv2d_output_array_intq)

/* Tensor #4 */
AI_TENSOR_OBJ_DECLARE(
  quantize_conv_dw_2_conv2d_output, AI_STATIC,
  4, 0x1,
  AI_SHAPE_INIT(4, 1, 16, 28, 28), AI_STRIDE_INIT(4, 1, 1, 16, 448),
  1, &quantize_conv_dw_2_conv2d_output_array, &quantize_conv_dw_2_conv2d_output_array_intq)

/* Tensor #5 */
AI_TENSOR_OBJ_DECLARE(
  quantize_conv_pw_2_conv2d_output, AI_STATIC,
  5, 0x1,
  AI_SHAPE_INIT(4, 1, 32, 28, 28), AI_STRIDE_INIT(4, 1, 1, 32, 896),
  1, &quantize_conv_pw_2_conv2d_output_array, &quantize_conv_pw_2_conv2d_output_array_intq)

/* Tensor #6 */
AI_TENSOR_OBJ_DECLARE(
  quantize_conv_dw_3_conv2d_output, AI_STATIC,
  6, 0x1,
  AI_SHAPE_INIT(4, 1, 32, 28, 28), AI_STRIDE_INIT(4, 1, 1, 32, 896),
  1, &quantize_conv_dw_3_conv2d_output_array, &quantize_conv_dw_3_conv2d_output_array_intq)

/* Tensor #7 */
AI_TENSOR_OBJ_DECLARE(
  quantize_conv_pw_3_conv2d_output, AI_STATIC,
  7, 0x1,
  AI_SHAPE_INIT(4, 1, 32, 28, 28), AI_STRIDE_INIT(4, 1, 1, 32, 896),
  1, &quantize_conv_pw_3_conv2d_output_array, &quantize_conv_pw_3_conv2d_output_array_intq)

/* Tensor #8 */
AI_TENSOR_OBJ_DECLARE(
  quantize_conv_dw_4_conv2d_output, AI_STATIC,
  8, 0x1,
  AI_SHAPE_INIT(4, 1, 32, 14, 14), AI_STRIDE_INIT(4, 1, 1, 32, 448),
  1, &quantize_conv_dw_4_conv2d_output_array, &quantize_conv_dw_4_conv2d_output_array_intq)

/* Tensor #9 */
AI_TENSOR_OBJ_DECLARE(
  quantize_conv_pw_4_conv2d_output, AI_STATIC,
  9, 0x1,
  AI_SHAPE_INIT(4, 1, 64, 14, 14), AI_STRIDE_INIT(4, 1, 1, 64, 896),
  1, &quantize_conv_pw_4_conv2d_output_array, &quantize_conv_pw_4_conv2d_output_array_intq)

/* Tensor #10 */
AI_TENSOR_OBJ_DECLARE(
  quantize_conv_dw_5_conv2d_output, AI_STATIC,
  10, 0x1,
  AI_SHAPE_INIT(4, 1, 64, 14, 14), AI_STRIDE_INIT(4, 1, 1, 64, 896),
  1, &quantize_conv_dw_5_conv2d_output_array, &quantize_conv_dw_5_conv2d_output_array_intq)

/* Tensor #11 */
AI_TENSOR_OBJ_DECLARE(
  quantize_conv_pw_5_conv2d_output, AI_STATIC,
  11, 0x1,
  AI_SHAPE_INIT(4, 1, 64, 14, 14), AI_STRIDE_INIT(4, 1, 1, 64, 896),
  1, &quantize_conv_pw_5_conv2d_output_array, &quantize_conv_pw_5_conv2d_output_array_intq)

/* Tensor #12 */
AI_TENSOR_OBJ_DECLARE(
  quantize_conv_dw_6_conv2d_output, AI_STATIC,
  12, 0x1,
  AI_SHAPE_INIT(4, 1, 64, 7, 7), AI_STRIDE_INIT(4, 1, 1, 64, 448),
  1, &quantize_conv_dw_6_conv2d_output_array, &quantize_conv_dw_6_conv2d_output_array_intq)

/* Tensor #13 */
AI_TENSOR_OBJ_DECLARE(
  quantize_conv_pw_6_conv2d_output, AI_STATIC,
  13, 0x1,
  AI_SHAPE_INIT(4, 1, 128, 7, 7), AI_STRIDE_INIT(4, 1, 1, 128, 896),
  1, &quantize_conv_pw_6_conv2d_output_array, &quantize_conv_pw_6_conv2d_output_array_intq)

/* Tensor #14 */
AI_TENSOR_OBJ_DECLARE(
  quantize_conv_dw_7_conv2d_output, AI_STATIC,
  14, 0x1,
  AI_SHAPE_INIT(4, 1, 128, 7, 7), AI_STRIDE_INIT(4, 1, 1, 128, 896),
  1, &quantize_conv_dw_7_conv2d_output_array, &quantize_conv_dw_7_conv2d_output_array_intq)

/* Tensor #15 */
AI_TENSOR_OBJ_DECLARE(
  quantize_conv_pw_7_conv2d_output, AI_STATIC,
  15, 0x1,
  AI_SHAPE_INIT(4, 1, 128, 7, 7), AI_STRIDE_INIT(4, 1, 1, 128, 896),
  1, &quantize_conv_pw_7_conv2d_output_array, &quantize_conv_pw_7_conv2d_output_array_intq)

/* Tensor #16 */
AI_TENSOR_OBJ_DECLARE(
  quantize_conv_dw_8_conv2d_output, AI_STATIC,
  16, 0x1,
  AI_SHAPE_INIT(4, 1, 128, 7, 7), AI_STRIDE_INIT(4, 1, 1, 128, 896),
  1, &quantize_conv_dw_8_conv2d_output_array, &quantize_conv_dw_8_conv2d_output_array_intq)

/* Tensor #17 */
AI_TENSOR_OBJ_DECLARE(
  quantize_conv_pw_8_conv2d_output, AI_STATIC,
  17, 0x1,
  AI_SHAPE_INIT(4, 1, 128, 7, 7), AI_STRIDE_INIT(4, 1, 1, 128, 896),
  1, &quantize_conv_pw_8_conv2d_output_array, &quantize_conv_pw_8_conv2d_output_array_intq)

/* Tensor #18 */
AI_TENSOR_OBJ_DECLARE(
  quantize_conv_dw_9_conv2d_output, AI_STATIC,
  18, 0x1,
  AI_SHAPE_INIT(4, 1, 128, 7, 7), AI_STRIDE_INIT(4, 1, 1, 128, 896),
  1, &quantize_conv_dw_9_conv2d_output_array, &quantize_conv_dw_9_conv2d_output_array_intq)

/* Tensor #19 */
AI_TENSOR_OBJ_DECLARE(
  quantize_conv_pw_9_conv2d_output, AI_STATIC,
  19, 0x1,
  AI_SHAPE_INIT(4, 1, 128, 7, 7), AI_STRIDE_INIT(4, 1, 1, 128, 896),
  1, &quantize_conv_pw_9_conv2d_output_array, &quantize_conv_pw_9_conv2d_output_array_intq)

/* Tensor #20 */
AI_TENSOR_OBJ_DECLARE(
  quantize_conv_dw_10_conv2d_output, AI_STATIC,
  20, 0x1,
  AI_SHAPE_INIT(4, 1, 128, 7, 7), AI_STRIDE_INIT(4, 1, 1, 128, 896),
  1, &quantize_conv_dw_10_conv2d_output_array, &quantize_conv_dw_10_conv2d_output_array_intq)

/* Tensor #21 */
AI_TENSOR_OBJ_DECLARE(
  quantize_conv_pw_10_conv2d_output, AI_STATIC,
  21, 0x1,
  AI_SHAPE_INIT(4, 1, 128, 7, 7), AI_STRIDE_INIT(4, 1, 1, 128, 896),
  1, &quantize_conv_pw_10_conv2d_output_array, &quantize_conv_pw_10_conv2d_output_array_intq)

/* Tensor #22 */
AI_TENSOR_OBJ_DECLARE(
  quantize_conv_dw_11_conv2d_output, AI_STATIC,
  22, 0x1,
  AI_SHAPE_INIT(4, 1, 128, 7, 7), AI_STRIDE_INIT(4, 1, 1, 128, 896),
  1, &quantize_conv_dw_11_conv2d_output_array, &quantize_conv_dw_11_conv2d_output_array_intq)

/* Tensor #23 */
AI_TENSOR_OBJ_DECLARE(
  quantize_conv_pw_11_conv2d_output, AI_STATIC,
  23, 0x1,
  AI_SHAPE_INIT(4, 1, 256, 1, 1), AI_STRIDE_INIT(4, 1, 1, 256, 256),
  1, &quantize_conv_pw_11_conv2d_output_array, &quantize_conv_pw_11_conv2d_output_array_intq)

/* Tensor #24 */
AI_TENSOR_OBJ_DECLARE(
  quantize_conv_preds_conv2d_output, AI_STATIC,
  24, 0x1,
  AI_SHAPE_INIT(4, 1, 18, 1, 1), AI_STRIDE_INIT(4, 1, 1, 18, 18),
  1, &quantize_conv_preds_conv2d_output_array, &quantize_conv_preds_conv2d_output_array_intq)

/* Tensor #25 */
AI_TENSOR_OBJ_DECLARE(
  quantize_conv_preds_conv2d_0_conversion_output, AI_STATIC,
  25, 0x0,
  AI_SHAPE_INIT(4, 1, 18, 1, 1), AI_STRIDE_INIT(4, 4, 4, 72, 72),
  1, &quantize_conv_preds_conv2d_0_conversion_output_array, NULL)

/* Tensor #26 */
AI_TENSOR_OBJ_DECLARE(
  act_softmax_output, AI_STATIC,
  26, 0x0,
  AI_SHAPE_INIT(4, 1, 18, 1, 1), AI_STRIDE_INIT(4, 4, 4, 72, 72),
  1, &act_softmax_output_array, NULL)

/* Tensor #27 */
AI_TENSOR_OBJ_DECLARE(
  quantize_conv1_conv2d_weights, AI_STATIC,
  27, 0x1,
  AI_SHAPE_INIT(4, 3, 3, 3, 8), AI_STRIDE_INIT(4, 1, 3, 9, 27),
  1, &quantize_conv1_conv2d_weights_array, &quantize_conv1_conv2d_weights_array_intq)

/* Tensor #28 */
AI_TENSOR_OBJ_DECLARE(
  quantize_conv1_conv2d_bias, AI_STATIC,
  28, 0x0,
  AI_SHAPE_INIT(4, 1, 8, 1, 1), AI_STRIDE_INIT(4, 4, 4, 32, 32),
  1, &quantize_conv1_conv2d_bias_array, NULL)

/* Tensor #29 */
AI_TENSOR_OBJ_DECLARE(
  quantize_conv_dw_1_conv2d_weights, AI_STATIC,
  29, 0x1,
  AI_SHAPE_INIT(4, 8, 3, 3, 1), AI_STRIDE_INIT(4, 1, 8, 24, 72),
  1, &quantize_conv_dw_1_conv2d_weights_array, &quantize_conv_dw_1_conv2d_weights_array_intq)

/* Tensor #30 */
AI_TENSOR_OBJ_DECLARE(
  quantize_conv_dw_1_conv2d_bias, AI_STATIC,
  30, 0x0,
  AI_SHAPE_INIT(4, 1, 8, 1, 1), AI_STRIDE_INIT(4, 4, 4, 32, 32),
  1, &quantize_conv_dw_1_conv2d_bias_array, NULL)

/* Tensor #31 */
AI_TENSOR_OBJ_DECLARE(
  quantize_conv_pw_1_conv2d_weights, AI_STATIC,
  31, 0x1,
  AI_SHAPE_INIT(4, 8, 1, 1, 16), AI_STRIDE_INIT(4, 1, 8, 8, 8),
  1, &quantize_conv_pw_1_conv2d_weights_array, &quantize_conv_pw_1_conv2d_weights_array_intq)

/* Tensor #32 */
AI_TENSOR_OBJ_DECLARE(
  quantize_conv_pw_1_conv2d_bias, AI_STATIC,
  32, 0x0,
  AI_SHAPE_INIT(4, 1, 16, 1, 1), AI_STRIDE_INIT(4, 4, 4, 64, 64),
  1, &quantize_conv_pw_1_conv2d_bias_array, NULL)

/* Tensor #33 */
AI_TENSOR_OBJ_DECLARE(
  quantize_conv_dw_2_conv2d_weights, AI_STATIC,
  33, 0x1,
  AI_SHAPE_INIT(4, 16, 3, 3, 1), AI_STRIDE_INIT(4, 1, 16, 48, 144),
  1, &quantize_conv_dw_2_conv2d_weights_array, &quantize_conv_dw_2_conv2d_weights_array_intq)

/* Tensor #34 */
AI_TENSOR_OBJ_DECLARE(
  quantize_conv_dw_2_conv2d_bias, AI_STATIC,
  34, 0x0,
  AI_SHAPE_INIT(4, 1, 16, 1, 1), AI_STRIDE_INIT(4, 4, 4, 64, 64),
  1, &quantize_conv_dw_2_conv2d_bias_array, NULL)

/* Tensor #35 */
AI_TENSOR_OBJ_DECLARE(
  quantize_conv_pw_2_conv2d_weights, AI_STATIC,
  35, 0x1,
  AI_SHAPE_INIT(4, 16, 1, 1, 32), AI_STRIDE_INIT(4, 1, 16, 16, 16),
  1, &quantize_conv_pw_2_conv2d_weights_array, &quantize_conv_pw_2_conv2d_weights_array_intq)

/* Tensor #36 */
AI_TENSOR_OBJ_DECLARE(
  quantize_conv_pw_2_conv2d_bias, AI_STATIC,
  36, 0x0,
  AI_SHAPE_INIT(4, 1, 32, 1, 1), AI_STRIDE_INIT(4, 4, 4, 128, 128),
  1, &quantize_conv_pw_2_conv2d_bias_array, NULL)

/* Tensor #37 */
AI_TENSOR_OBJ_DECLARE(
  quantize_conv_dw_3_conv2d_weights, AI_STATIC,
  37, 0x1,
  AI_SHAPE_INIT(4, 32, 3, 3, 1), AI_STRIDE_INIT(4, 1, 32, 96, 288),
  1, &quantize_conv_dw_3_conv2d_weights_array, &quantize_conv_dw_3_conv2d_weights_array_intq)

/* Tensor #38 */
AI_TENSOR_OBJ_DECLARE(
  quantize_conv_dw_3_conv2d_bias, AI_STATIC,
  38, 0x0,
  AI_SHAPE_INIT(4, 1, 32, 1, 1), AI_STRIDE_INIT(4, 4, 4, 128, 128),
  1, &quantize_conv_dw_3_conv2d_bias_array, NULL)

/* Tensor #39 */
AI_TENSOR_OBJ_DECLARE(
  quantize_conv_pw_3_conv2d_weights, AI_STATIC,
  39, 0x1,
  AI_SHAPE_INIT(4, 32, 1, 1, 32), AI_STRIDE_INIT(4, 1, 32, 32, 32),
  1, &quantize_conv_pw_3_conv2d_weights_array, &quantize_conv_pw_3_conv2d_weights_array_intq)

/* Tensor #40 */
AI_TENSOR_OBJ_DECLARE(
  quantize_conv_pw_3_conv2d_bias, AI_STATIC,
  40, 0x0,
  AI_SHAPE_INIT(4, 1, 32, 1, 1), AI_STRIDE_INIT(4, 4, 4, 128, 128),
  1, &quantize_conv_pw_3_conv2d_bias_array, NULL)

/* Tensor #41 */
AI_TENSOR_OBJ_DECLARE(
  quantize_conv_dw_4_conv2d_weights, AI_STATIC,
  41, 0x1,
  AI_SHAPE_INIT(4, 32, 3, 3, 1), AI_STRIDE_INIT(4, 1, 32, 96, 288),
  1, &quantize_conv_dw_4_conv2d_weights_array, &quantize_conv_dw_4_conv2d_weights_array_intq)

/* Tensor #42 */
AI_TENSOR_OBJ_DECLARE(
  quantize_conv_dw_4_conv2d_bias, AI_STATIC,
  42, 0x0,
  AI_SHAPE_INIT(4, 1, 32, 1, 1), AI_STRIDE_INIT(4, 4, 4, 128, 128),
  1, &quantize_conv_dw_4_conv2d_bias_array, NULL)

/* Tensor #43 */
AI_TENSOR_OBJ_DECLARE(
  quantize_conv_pw_4_conv2d_weights, AI_STATIC,
  43, 0x1,
  AI_SHAPE_INIT(4, 32, 1, 1, 64), AI_STRIDE_INIT(4, 1, 32, 32, 32),
  1, &quantize_conv_pw_4_conv2d_weights_array, &quantize_conv_pw_4_conv2d_weights_array_intq)

/* Tensor #44 */
AI_TENSOR_OBJ_DECLARE(
  quantize_conv_pw_4_conv2d_bias, AI_STATIC,
  44, 0x0,
  AI_SHAPE_INIT(4, 1, 64, 1, 1), AI_STRIDE_INIT(4, 4, 4, 256, 256),
  1, &quantize_conv_pw_4_conv2d_bias_array, NULL)

/* Tensor #45 */
AI_TENSOR_OBJ_DECLARE(
  quantize_conv_dw_5_conv2d_weights, AI_STATIC,
  45, 0x1,
  AI_SHAPE_INIT(4, 64, 3, 3, 1), AI_STRIDE_INIT(4, 1, 64, 192, 576),
  1, &quantize_conv_dw_5_conv2d_weights_array, &quantize_conv_dw_5_conv2d_weights_array_intq)

/* Tensor #46 */
AI_TENSOR_OBJ_DECLARE(
  quantize_conv_dw_5_conv2d_bias, AI_STATIC,
  46, 0x0,
  AI_SHAPE_INIT(4, 1, 64, 1, 1), AI_STRIDE_INIT(4, 4, 4, 256, 256),
  1, &quantize_conv_dw_5_conv2d_bias_array, NULL)

/* Tensor #47 */
AI_TENSOR_OBJ_DECLARE(
  quantize_conv_pw_5_conv2d_weights, AI_STATIC,
  47, 0x1,
  AI_SHAPE_INIT(4, 64, 1, 1, 64), AI_STRIDE_INIT(4, 1, 64, 64, 64),
  1, &quantize_conv_pw_5_conv2d_weights_array, &quantize_conv_pw_5_conv2d_weights_array_intq)

/* Tensor #48 */
AI_TENSOR_OBJ_DECLARE(
  quantize_conv_pw_5_conv2d_bias, AI_STATIC,
  48, 0x0,
  AI_SHAPE_INIT(4, 1, 64, 1, 1), AI_STRIDE_INIT(4, 4, 4, 256, 256),
  1, &quantize_conv_pw_5_conv2d_bias_array, NULL)

/* Tensor #49 */
AI_TENSOR_OBJ_DECLARE(
  quantize_conv_dw_6_conv2d_weights, AI_STATIC,
  49, 0x1,
  AI_SHAPE_INIT(4, 64, 3, 3, 1), AI_STRIDE_INIT(4, 1, 64, 192, 576),
  1, &quantize_conv_dw_6_conv2d_weights_array, &quantize_conv_dw_6_conv2d_weights_array_intq)

/* Tensor #50 */
AI_TENSOR_OBJ_DECLARE(
  quantize_conv_dw_6_conv2d_bias, AI_STATIC,
  50, 0x0,
  AI_SHAPE_INIT(4, 1, 64, 1, 1), AI_STRIDE_INIT(4, 4, 4, 256, 256),
  1, &quantize_conv_dw_6_conv2d_bias_array, NULL)

/* Tensor #51 */
AI_TENSOR_OBJ_DECLARE(
  quantize_conv_pw_6_conv2d_weights, AI_STATIC,
  51, 0x1,
  AI_SHAPE_INIT(4, 64, 1, 1, 128), AI_STRIDE_INIT(4, 1, 64, 64, 64),
  1, &quantize_conv_pw_6_conv2d_weights_array, &quantize_conv_pw_6_conv2d_weights_array_intq)

/* Tensor #52 */
AI_TENSOR_OBJ_DECLARE(
  quantize_conv_pw_6_conv2d_bias, AI_STATIC,
  52, 0x0,
  AI_SHAPE_INIT(4, 1, 128, 1, 1), AI_STRIDE_INIT(4, 4, 4, 512, 512),
  1, &quantize_conv_pw_6_conv2d_bias_array, NULL)

/* Tensor #53 */
AI_TENSOR_OBJ_DECLARE(
  quantize_conv_dw_7_conv2d_weights, AI_STATIC,
  53, 0x1,
  AI_SHAPE_INIT(4, 128, 3, 3, 1), AI_STRIDE_INIT(4, 1, 128, 384, 1152),
  1, &quantize_conv_dw_7_conv2d_weights_array, &quantize_conv_dw_7_conv2d_weights_array_intq)

/* Tensor #54 */
AI_TENSOR_OBJ_DECLARE(
  quantize_conv_dw_7_conv2d_bias, AI_STATIC,
  54, 0x0,
  AI_SHAPE_INIT(4, 1, 128, 1, 1), AI_STRIDE_INIT(4, 4, 4, 512, 512),
  1, &quantize_conv_dw_7_conv2d_bias_array, NULL)

/* Tensor #55 */
AI_TENSOR_OBJ_DECLARE(
  quantize_conv_pw_7_conv2d_weights, AI_STATIC,
  55, 0x1,
  AI_SHAPE_INIT(4, 128, 1, 1, 128), AI_STRIDE_INIT(4, 1, 128, 128, 128),
  1, &quantize_conv_pw_7_conv2d_weights_array, &quantize_conv_pw_7_conv2d_weights_array_intq)

/* Tensor #56 */
AI_TENSOR_OBJ_DECLARE(
  quantize_conv_pw_7_conv2d_bias, AI_STATIC,
  56, 0x0,
  AI_SHAPE_INIT(4, 1, 128, 1, 1), AI_STRIDE_INIT(4, 4, 4, 512, 512),
  1, &quantize_conv_pw_7_conv2d_bias_array, NULL)

/* Tensor #57 */
AI_TENSOR_OBJ_DECLARE(
  quantize_conv_dw_8_conv2d_weights, AI_STATIC,
  57, 0x1,
  AI_SHAPE_INIT(4, 128, 3, 3, 1), AI_STRIDE_INIT(4, 1, 128, 384, 1152),
  1, &quantize_conv_dw_8_conv2d_weights_array, &quantize_conv_dw_8_conv2d_weights_array_intq)

/* Tensor #58 */
AI_TENSOR_OBJ_DECLARE(
  quantize_conv_dw_8_conv2d_bias, AI_STATIC,
  58, 0x0,
  AI_SHAPE_INIT(4, 1, 128, 1, 1), AI_STRIDE_INIT(4, 4, 4, 512, 512),
  1, &quantize_conv_dw_8_conv2d_bias_array, NULL)

/* Tensor #59 */
AI_TENSOR_OBJ_DECLARE(
  quantize_conv_pw_8_conv2d_weights, AI_STATIC,
  59, 0x1,
  AI_SHAPE_INIT(4, 128, 1, 1, 128), AI_STRIDE_INIT(4, 1, 128, 128, 128),
  1, &quantize_conv_pw_8_conv2d_weights_array, &quantize_conv_pw_8_conv2d_weights_array_intq)

/* Tensor #60 */
AI_TENSOR_OBJ_DECLARE(
  quantize_conv_pw_8_conv2d_bias, AI_STATIC,
  60, 0x0,
  AI_SHAPE_INIT(4, 1, 128, 1, 1), AI_STRIDE_INIT(4, 4, 4, 512, 512),
  1, &quantize_conv_pw_8_conv2d_bias_array, NULL)

/* Tensor #61 */
AI_TENSOR_OBJ_DECLARE(
  quantize_conv_dw_9_conv2d_weights, AI_STATIC,
  61, 0x1,
  AI_SHAPE_INIT(4, 128, 3, 3, 1), AI_STRIDE_INIT(4, 1, 128, 384, 1152),
  1, &quantize_conv_dw_9_conv2d_weights_array, &quantize_conv_dw_9_conv2d_weights_array_intq)

/* Tensor #62 */
AI_TENSOR_OBJ_DECLARE(
  quantize_conv_dw_9_conv2d_bias, AI_STATIC,
  62, 0x0,
  AI_SHAPE_INIT(4, 1, 128, 1, 1), AI_STRIDE_INIT(4, 4, 4, 512, 512),
  1, &quantize_conv_dw_9_conv2d_bias_array, NULL)

/* Tensor #63 */
AI_TENSOR_OBJ_DECLARE(
  quantize_conv_pw_9_conv2d_weights, AI_STATIC,
  63, 0x1,
  AI_SHAPE_INIT(4, 128, 1, 1, 128), AI_STRIDE_INIT(4, 1, 128, 128, 128),
  1, &quantize_conv_pw_9_conv2d_weights_array, &quantize_conv_pw_9_conv2d_weights_array_intq)

/* Tensor #64 */
AI_TENSOR_OBJ_DECLARE(
  quantize_conv_pw_9_conv2d_bias, AI_STATIC,
  64, 0x0,
  AI_SHAPE_INIT(4, 1, 128, 1, 1), AI_STRIDE_INIT(4, 4, 4, 512, 512),
  1, &quantize_conv_pw_9_conv2d_bias_array, NULL)

/* Tensor #65 */
AI_TENSOR_OBJ_DECLARE(
  quantize_conv_dw_10_conv2d_weights, AI_STATIC,
  65, 0x1,
  AI_SHAPE_INIT(4, 128, 3, 3, 1), AI_STRIDE_INIT(4, 1, 128, 384, 1152),
  1, &quantize_conv_dw_10_conv2d_weights_array, &quantize_conv_dw_10_conv2d_weights_array_intq)

/* Tensor #66 */
AI_TENSOR_OBJ_DECLARE(
  quantize_conv_dw_10_conv2d_bias, AI_STATIC,
  66, 0x0,
  AI_SHAPE_INIT(4, 1, 128, 1, 1), AI_STRIDE_INIT(4, 4, 4, 512, 512),
  1, &quantize_conv_dw_10_conv2d_bias_array, NULL)

/* Tensor #67 */
AI_TENSOR_OBJ_DECLARE(
  quantize_conv_pw_10_conv2d_weights, AI_STATIC,
  67, 0x1,
  AI_SHAPE_INIT(4, 128, 1, 1, 128), AI_STRIDE_INIT(4, 1, 128, 128, 128),
  1, &quantize_conv_pw_10_conv2d_weights_array, &quantize_conv_pw_10_conv2d_weights_array_intq)

/* Tensor #68 */
AI_TENSOR_OBJ_DECLARE(
  quantize_conv_pw_10_conv2d_bias, AI_STATIC,
  68, 0x0,
  AI_SHAPE_INIT(4, 1, 128, 1, 1), AI_STRIDE_INIT(4, 4, 4, 512, 512),
  1, &quantize_conv_pw_10_conv2d_bias_array, NULL)

/* Tensor #69 */
AI_TENSOR_OBJ_DECLARE(
  quantize_conv_dw_11_conv2d_weights, AI_STATIC,
  69, 0x1,
  AI_SHAPE_INIT(4, 128, 3, 3, 1), AI_STRIDE_INIT(4, 1, 128, 384, 1152),
  1, &quantize_conv_dw_11_conv2d_weights_array, &quantize_conv_dw_11_conv2d_weights_array_intq)

/* Tensor #70 */
AI_TENSOR_OBJ_DECLARE(
  quantize_conv_dw_11_conv2d_bias, AI_STATIC,
  70, 0x0,
  AI_SHAPE_INIT(4, 1, 128, 1, 1), AI_STRIDE_INIT(4, 4, 4, 512, 512),
  1, &quantize_conv_dw_11_conv2d_bias_array, NULL)

/* Tensor #71 */
AI_TENSOR_OBJ_DECLARE(
  quantize_conv_pw_11_conv2d_weights, AI_STATIC,
  71, 0x1,
  AI_SHAPE_INIT(4, 128, 1, 1, 256), AI_STRIDE_INIT(4, 1, 128, 128, 128),
  1, &quantize_conv_pw_11_conv2d_weights_array, &quantize_conv_pw_11_conv2d_weights_array_intq)

/* Tensor #72 */
AI_TENSOR_OBJ_DECLARE(
  quantize_conv_pw_11_conv2d_bias, AI_STATIC,
  72, 0x0,
  AI_SHAPE_INIT(4, 1, 256, 1, 1), AI_STRIDE_INIT(4, 4, 4, 1024, 1024),
  1, &quantize_conv_pw_11_conv2d_bias_array, NULL)

/* Tensor #73 */
AI_TENSOR_OBJ_DECLARE(
  quantize_conv_preds_conv2d_weights, AI_STATIC,
  73, 0x1,
  AI_SHAPE_INIT(4, 256, 1, 1, 18), AI_STRIDE_INIT(4, 1, 256, 256, 256),
  1, &quantize_conv_preds_conv2d_weights_array, &quantize_conv_preds_conv2d_weights_array_intq)

/* Tensor #74 */
AI_TENSOR_OBJ_DECLARE(
  quantize_conv_preds_conv2d_bias, AI_STATIC,
  74, 0x0,
  AI_SHAPE_INIT(4, 1, 18, 1, 1), AI_STRIDE_INIT(4, 4, 4, 72, 72),
  1, &quantize_conv_preds_conv2d_bias_array, NULL)

/* Tensor #75 */
AI_TENSOR_OBJ_DECLARE(
  quantize_conv1_conv2d_scratch0, AI_STATIC,
  75, 0x0,
  AI_SHAPE_INIT(4, 1, 572, 1, 1), AI_STRIDE_INIT(4, 1, 1, 572, 572),
  1, &quantize_conv1_conv2d_scratch0_array, NULL)

/* Tensor #76 */
AI_TENSOR_OBJ_DECLARE(
  quantize_conv_dw_1_conv2d_scratch0, AI_STATIC,
  76, 0x0,
  AI_SHAPE_INIT(4, 1, 217, 1, 1), AI_STRIDE_INIT(4, 1, 1, 217, 217),
  1, &quantize_conv_dw_1_conv2d_scratch0_array, NULL)

/* Tensor #77 */
AI_TENSOR_OBJ_DECLARE(
  quantize_conv_pw_1_conv2d_scratch0, AI_STATIC,
  77, 0x0,
  AI_SHAPE_INIT(4, 1, 32, 1, 1), AI_STRIDE_INIT(4, 1, 1, 32, 32),
  1, &quantize_conv_pw_1_conv2d_scratch0_array, NULL)

/* Tensor #78 */
AI_TENSOR_OBJ_DECLARE(
  quantize_conv_dw_2_conv2d_scratch0, AI_STATIC,
  78, 0x0,
  AI_SHAPE_INIT(4, 1, 433, 1, 1), AI_STRIDE_INIT(4, 1, 1, 433, 433),
  1, &quantize_conv_dw_2_conv2d_scratch0_array, NULL)

/* Tensor #79 */
AI_TENSOR_OBJ_DECLARE(
  quantize_conv_pw_2_conv2d_scratch0, AI_STATIC,
  79, 0x0,
  AI_SHAPE_INIT(4, 1, 64, 1, 1), AI_STRIDE_INIT(4, 1, 1, 64, 64),
  1, &quantize_conv_pw_2_conv2d_scratch0_array, NULL)

/* Tensor #80 */
AI_TENSOR_OBJ_DECLARE(
  quantize_conv_dw_3_conv2d_scratch0, AI_STATIC,
  80, 0x0,
  AI_SHAPE_INIT(4, 1, 865, 1, 1), AI_STRIDE_INIT(4, 1, 1, 865, 865),
  1, &quantize_conv_dw_3_conv2d_scratch0_array, NULL)

/* Tensor #81 */
AI_TENSOR_OBJ_DECLARE(
  quantize_conv_pw_3_conv2d_scratch0, AI_STATIC,
  81, 0x0,
  AI_SHAPE_INIT(4, 1, 128, 1, 1), AI_STRIDE_INIT(4, 1, 1, 128, 128),
  1, &quantize_conv_pw_3_conv2d_scratch0_array, NULL)

/* Tensor #82 */
AI_TENSOR_OBJ_DECLARE(
  quantize_conv_dw_4_conv2d_scratch0, AI_STATIC,
  82, 0x0,
  AI_SHAPE_INIT(4, 1, 865, 1, 1), AI_STRIDE_INIT(4, 1, 1, 865, 865),
  1, &quantize_conv_dw_4_conv2d_scratch0_array, NULL)

/* Tensor #83 */
AI_TENSOR_OBJ_DECLARE(
  quantize_conv_pw_4_conv2d_scratch0, AI_STATIC,
  83, 0x0,
  AI_SHAPE_INIT(4, 1, 128, 1, 1), AI_STRIDE_INIT(4, 1, 1, 128, 128),
  1, &quantize_conv_pw_4_conv2d_scratch0_array, NULL)

/* Tensor #84 */
AI_TENSOR_OBJ_DECLARE(
  quantize_conv_dw_5_conv2d_scratch0, AI_STATIC,
  84, 0x0,
  AI_SHAPE_INIT(4, 1, 1729, 1, 1), AI_STRIDE_INIT(4, 1, 1, 1729, 1729),
  1, &quantize_conv_dw_5_conv2d_scratch0_array, NULL)

/* Tensor #85 */
AI_TENSOR_OBJ_DECLARE(
  quantize_conv_pw_5_conv2d_scratch0, AI_STATIC,
  85, 0x0,
  AI_SHAPE_INIT(4, 1, 256, 1, 1), AI_STRIDE_INIT(4, 1, 1, 256, 256),
  1, &quantize_conv_pw_5_conv2d_scratch0_array, NULL)

/* Tensor #86 */
AI_TENSOR_OBJ_DECLARE(
  quantize_conv_dw_6_conv2d_scratch0, AI_STATIC,
  86, 0x0,
  AI_SHAPE_INIT(4, 1, 1729, 1, 1), AI_STRIDE_INIT(4, 1, 1, 1729, 1729),
  1, &quantize_conv_dw_6_conv2d_scratch0_array, NULL)

/* Tensor #87 */
AI_TENSOR_OBJ_DECLARE(
  quantize_conv_pw_6_conv2d_scratch0, AI_STATIC,
  87, 0x0,
  AI_SHAPE_INIT(4, 1, 256, 1, 1), AI_STRIDE_INIT(4, 1, 1, 256, 256),
  1, &quantize_conv_pw_6_conv2d_scratch0_array, NULL)

/* Tensor #88 */
AI_TENSOR_OBJ_DECLARE(
  quantize_conv_dw_7_conv2d_scratch0, AI_STATIC,
  88, 0x0,
  AI_SHAPE_INIT(4, 1, 3457, 1, 1), AI_STRIDE_INIT(4, 1, 1, 3457, 3457),
  1, &quantize_conv_dw_7_conv2d_scratch0_array, NULL)

/* Tensor #89 */
AI_TENSOR_OBJ_DECLARE(
  quantize_conv_pw_7_conv2d_scratch0, AI_STATIC,
  89, 0x0,
  AI_SHAPE_INIT(4, 1, 512, 1, 1), AI_STRIDE_INIT(4, 1, 1, 512, 512),
  1, &quantize_conv_pw_7_conv2d_scratch0_array, NULL)

/* Tensor #90 */
AI_TENSOR_OBJ_DECLARE(
  quantize_conv_dw_8_conv2d_scratch0, AI_STATIC,
  90, 0x0,
  AI_SHAPE_INIT(4, 1, 3457, 1, 1), AI_STRIDE_INIT(4, 1, 1, 3457, 3457),
  1, &quantize_conv_dw_8_conv2d_scratch0_array, NULL)

/* Tensor #91 */
AI_TENSOR_OBJ_DECLARE(
  quantize_conv_pw_8_conv2d_scratch0, AI_STATIC,
  91, 0x0,
  AI_SHAPE_INIT(4, 1, 512, 1, 1), AI_STRIDE_INIT(4, 1, 1, 512, 512),
  1, &quantize_conv_pw_8_conv2d_scratch0_array, NULL)

/* Tensor #92 */
AI_TENSOR_OBJ_DECLARE(
  quantize_conv_dw_9_conv2d_scratch0, AI_STATIC,
  92, 0x0,
  AI_SHAPE_INIT(4, 1, 3457, 1, 1), AI_STRIDE_INIT(4, 1, 1, 3457, 3457),
  1, &quantize_conv_dw_9_conv2d_scratch0_array, NULL)

/* Tensor #93 */
AI_TENSOR_OBJ_DECLARE(
  quantize_conv_pw_9_conv2d_scratch0, AI_STATIC,
  93, 0x0,
  AI_SHAPE_INIT(4, 1, 512, 1, 1), AI_STRIDE_INIT(4, 1, 1, 512, 512),
  1, &quantize_conv_pw_9_conv2d_scratch0_array, NULL)

/* Tensor #94 */
AI_TENSOR_OBJ_DECLARE(
  quantize_conv_dw_10_conv2d_scratch0, AI_STATIC,
  94, 0x0,
  AI_SHAPE_INIT(4, 1, 3457, 1, 1), AI_STRIDE_INIT(4, 1, 1, 3457, 3457),
  1, &quantize_conv_dw_10_conv2d_scratch0_array, NULL)

/* Tensor #95 */
AI_TENSOR_OBJ_DECLARE(
  quantize_conv_pw_10_conv2d_scratch0, AI_STATIC,
  95, 0x0,
  AI_SHAPE_INIT(4, 1, 512, 1, 1), AI_STRIDE_INIT(4, 1, 1, 512, 512),
  1, &quantize_conv_pw_10_conv2d_scratch0_array, NULL)

/* Tensor #96 */
AI_TENSOR_OBJ_DECLARE(
  quantize_conv_dw_11_conv2d_scratch0, AI_STATIC,
  96, 0x0,
  AI_SHAPE_INIT(4, 1, 3457, 1, 1), AI_STRIDE_INIT(4, 1, 1, 3457, 3457),
  1, &quantize_conv_dw_11_conv2d_scratch0_array, NULL)

/* Tensor #97 */
AI_TENSOR_OBJ_DECLARE(
  quantize_conv_pw_11_conv2d_scratch0, AI_STATIC,
  97, 0x0,
  AI_SHAPE_INIT(4, 1, 512, 1, 1), AI_STRIDE_INIT(4, 1, 1, 512, 512),
  1, &quantize_conv_pw_11_conv2d_scratch0_array, NULL)

/* Tensor #98 */
AI_TENSOR_OBJ_DECLARE(
  quantize_conv_pw_11_conv2d_scratch1, AI_STATIC,
  98, 0x1,
  AI_SHAPE_INIT(4, 1, 256, 7, 7), AI_STRIDE_INIT(4, 1, 1, 256, 1792),
  1, &quantize_conv_pw_11_conv2d_scratch1_array, &quantize_conv_pw_11_conv2d_scratch1_array_intq)

/* Tensor #99 */
AI_TENSOR_OBJ_DECLARE(
  quantize_conv_preds_conv2d_scratch0, AI_STATIC,
  99, 0x0,
  AI_SHAPE_INIT(4, 1, 1024, 1, 1), AI_STRIDE_INIT(4, 1, 1, 1024, 1024),
  1, &quantize_conv_preds_conv2d_scratch0_array, NULL)



/**  Layer declarations section  **********************************************/


AI_TENSOR_CHAIN_OBJ_DECLARE(
  act_softmax_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &quantize_conv_preds_conv2d_0_conversion_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &act_softmax_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  act_softmax_layer, 40,
  NL_TYPE, 0x0, NULL,
  nl, forward_sm,
  &act_softmax_chain,
  NULL, &act_softmax_layer, AI_STATIC, 
  .nl_params = NULL, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  quantize_conv_preds_conv2d_0_conversion_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &quantize_conv_preds_conv2d_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &quantize_conv_preds_conv2d_0_conversion_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  quantize_conv_preds_conv2d_0_conversion_layer, 39,
  NL_TYPE, 0x0, NULL,
  nl, node_convert,
  &quantize_conv_preds_conv2d_0_conversion_chain,
  NULL, &act_softmax_layer, AI_STATIC, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  quantize_conv_preds_conv2d_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &quantize_conv_pw_11_conv2d_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &quantize_conv_preds_conv2d_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &quantize_conv_preds_conv2d_weights, &quantize_conv_preds_conv2d_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &quantize_conv_preds_conv2d_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  quantize_conv_preds_conv2d_layer, 39,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d_integer_UAUA,
  &quantize_conv_preds_conv2d_chain,
  NULL, &quantize_conv_preds_conv2d_0_conversion_layer, AI_STATIC, 
  .groups = 1, 
  .nl_func = NULL, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  quantize_conv_pw_11_conv2d_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &quantize_conv_dw_11_conv2d_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &quantize_conv_pw_11_conv2d_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &quantize_conv_pw_11_conv2d_weights, &quantize_conv_pw_11_conv2d_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &quantize_conv_pw_11_conv2d_scratch0, &quantize_conv_pw_11_conv2d_scratch1)
)

AI_LAYER_OBJ_DECLARE(
  quantize_conv_pw_11_conv2d_layer, 36,
  OPTIMIZED_CONV2D_TYPE, 0x0, NULL,
  conv2d_nl_pool, forward_conv2d_nl_pool_integer_UAUA,
  &quantize_conv_pw_11_conv2d_chain,
  NULL, &quantize_conv_preds_conv2d_layer, AI_STATIC, 
  .groups = 1, 
  .nl_func = NULL, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
  .pool_size = AI_SHAPE_2D_INIT(7, 7), 
  .pool_stride = AI_SHAPE_2D_INIT(7, 7), 
  .pool_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
  .pool_func = pool_func_ap_array_integer_UINT8, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  quantize_conv_dw_11_conv2d_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &quantize_conv_pw_10_conv2d_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &quantize_conv_dw_11_conv2d_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &quantize_conv_dw_11_conv2d_weights, &quantize_conv_dw_11_conv2d_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &quantize_conv_dw_11_conv2d_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  quantize_conv_dw_11_conv2d_layer, 33,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d_integer_UAUA,
  &quantize_conv_dw_11_conv2d_chain,
  NULL, &quantize_conv_pw_11_conv2d_layer, AI_STATIC, 
  .groups = 128, 
  .nl_func = NULL, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 1, 1, 1, 1), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  quantize_conv_pw_10_conv2d_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &quantize_conv_dw_10_conv2d_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &quantize_conv_pw_10_conv2d_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &quantize_conv_pw_10_conv2d_weights, &quantize_conv_pw_10_conv2d_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &quantize_conv_pw_10_conv2d_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  quantize_conv_pw_10_conv2d_layer, 31,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d_integer_UAUA,
  &quantize_conv_pw_10_conv2d_chain,
  NULL, &quantize_conv_dw_11_conv2d_layer, AI_STATIC, 
  .groups = 1, 
  .nl_func = NULL, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  quantize_conv_dw_10_conv2d_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &quantize_conv_pw_9_conv2d_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &quantize_conv_dw_10_conv2d_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &quantize_conv_dw_10_conv2d_weights, &quantize_conv_dw_10_conv2d_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &quantize_conv_dw_10_conv2d_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  quantize_conv_dw_10_conv2d_layer, 30,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d_integer_UAUA,
  &quantize_conv_dw_10_conv2d_chain,
  NULL, &quantize_conv_pw_10_conv2d_layer, AI_STATIC, 
  .groups = 128, 
  .nl_func = NULL, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 1, 1, 1, 1), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  quantize_conv_pw_9_conv2d_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &quantize_conv_dw_9_conv2d_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &quantize_conv_pw_9_conv2d_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &quantize_conv_pw_9_conv2d_weights, &quantize_conv_pw_9_conv2d_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &quantize_conv_pw_9_conv2d_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  quantize_conv_pw_9_conv2d_layer, 28,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d_integer_UAUA,
  &quantize_conv_pw_9_conv2d_chain,
  NULL, &quantize_conv_dw_10_conv2d_layer, AI_STATIC, 
  .groups = 1, 
  .nl_func = NULL, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  quantize_conv_dw_9_conv2d_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &quantize_conv_pw_8_conv2d_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &quantize_conv_dw_9_conv2d_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &quantize_conv_dw_9_conv2d_weights, &quantize_conv_dw_9_conv2d_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &quantize_conv_dw_9_conv2d_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  quantize_conv_dw_9_conv2d_layer, 27,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d_integer_UAUA,
  &quantize_conv_dw_9_conv2d_chain,
  NULL, &quantize_conv_pw_9_conv2d_layer, AI_STATIC, 
  .groups = 128, 
  .nl_func = NULL, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 1, 1, 1, 1), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  quantize_conv_pw_8_conv2d_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &quantize_conv_dw_8_conv2d_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &quantize_conv_pw_8_conv2d_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &quantize_conv_pw_8_conv2d_weights, &quantize_conv_pw_8_conv2d_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &quantize_conv_pw_8_conv2d_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  quantize_conv_pw_8_conv2d_layer, 25,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d_integer_UAUA,
  &quantize_conv_pw_8_conv2d_chain,
  NULL, &quantize_conv_dw_9_conv2d_layer, AI_STATIC, 
  .groups = 1, 
  .nl_func = NULL, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  quantize_conv_dw_8_conv2d_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &quantize_conv_pw_7_conv2d_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &quantize_conv_dw_8_conv2d_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &quantize_conv_dw_8_conv2d_weights, &quantize_conv_dw_8_conv2d_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &quantize_conv_dw_8_conv2d_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  quantize_conv_dw_8_conv2d_layer, 24,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d_integer_UAUA,
  &quantize_conv_dw_8_conv2d_chain,
  NULL, &quantize_conv_pw_8_conv2d_layer, AI_STATIC, 
  .groups = 128, 
  .nl_func = NULL, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 1, 1, 1, 1), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  quantize_conv_pw_7_conv2d_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &quantize_conv_dw_7_conv2d_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &quantize_conv_pw_7_conv2d_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &quantize_conv_pw_7_conv2d_weights, &quantize_conv_pw_7_conv2d_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &quantize_conv_pw_7_conv2d_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  quantize_conv_pw_7_conv2d_layer, 22,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d_integer_UAUA,
  &quantize_conv_pw_7_conv2d_chain,
  NULL, &quantize_conv_dw_8_conv2d_layer, AI_STATIC, 
  .groups = 1, 
  .nl_func = NULL, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  quantize_conv_dw_7_conv2d_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &quantize_conv_pw_6_conv2d_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &quantize_conv_dw_7_conv2d_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &quantize_conv_dw_7_conv2d_weights, &quantize_conv_dw_7_conv2d_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &quantize_conv_dw_7_conv2d_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  quantize_conv_dw_7_conv2d_layer, 21,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d_integer_UAUA,
  &quantize_conv_dw_7_conv2d_chain,
  NULL, &quantize_conv_pw_7_conv2d_layer, AI_STATIC, 
  .groups = 128, 
  .nl_func = NULL, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 1, 1, 1, 1), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  quantize_conv_pw_6_conv2d_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &quantize_conv_dw_6_conv2d_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &quantize_conv_pw_6_conv2d_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &quantize_conv_pw_6_conv2d_weights, &quantize_conv_pw_6_conv2d_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &quantize_conv_pw_6_conv2d_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  quantize_conv_pw_6_conv2d_layer, 19,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d_integer_UAUA,
  &quantize_conv_pw_6_conv2d_chain,
  NULL, &quantize_conv_dw_7_conv2d_layer, AI_STATIC, 
  .groups = 1, 
  .nl_func = NULL, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  quantize_conv_dw_6_conv2d_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &quantize_conv_pw_5_conv2d_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &quantize_conv_dw_6_conv2d_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &quantize_conv_dw_6_conv2d_weights, &quantize_conv_dw_6_conv2d_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &quantize_conv_dw_6_conv2d_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  quantize_conv_dw_6_conv2d_layer, 18,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d_integer_UAUA,
  &quantize_conv_dw_6_conv2d_chain,
  NULL, &quantize_conv_pw_6_conv2d_layer, AI_STATIC, 
  .groups = 64, 
  .nl_func = NULL, 
  .filter_stride = AI_SHAPE_2D_INIT(2, 2), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 2, 2), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  quantize_conv_pw_5_conv2d_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &quantize_conv_dw_5_conv2d_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &quantize_conv_pw_5_conv2d_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &quantize_conv_pw_5_conv2d_weights, &quantize_conv_pw_5_conv2d_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &quantize_conv_pw_5_conv2d_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  quantize_conv_pw_5_conv2d_layer, 16,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d_integer_UAUA,
  &quantize_conv_pw_5_conv2d_chain,
  NULL, &quantize_conv_dw_6_conv2d_layer, AI_STATIC, 
  .groups = 1, 
  .nl_func = NULL, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  quantize_conv_dw_5_conv2d_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &quantize_conv_pw_4_conv2d_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &quantize_conv_dw_5_conv2d_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &quantize_conv_dw_5_conv2d_weights, &quantize_conv_dw_5_conv2d_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &quantize_conv_dw_5_conv2d_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  quantize_conv_dw_5_conv2d_layer, 15,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d_integer_UAUA,
  &quantize_conv_dw_5_conv2d_chain,
  NULL, &quantize_conv_pw_5_conv2d_layer, AI_STATIC, 
  .groups = 64, 
  .nl_func = NULL, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 1, 1, 1, 1), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  quantize_conv_pw_4_conv2d_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &quantize_conv_dw_4_conv2d_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &quantize_conv_pw_4_conv2d_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &quantize_conv_pw_4_conv2d_weights, &quantize_conv_pw_4_conv2d_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &quantize_conv_pw_4_conv2d_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  quantize_conv_pw_4_conv2d_layer, 13,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d_integer_UAUA,
  &quantize_conv_pw_4_conv2d_chain,
  NULL, &quantize_conv_dw_5_conv2d_layer, AI_STATIC, 
  .groups = 1, 
  .nl_func = NULL, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  quantize_conv_dw_4_conv2d_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &quantize_conv_pw_3_conv2d_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &quantize_conv_dw_4_conv2d_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &quantize_conv_dw_4_conv2d_weights, &quantize_conv_dw_4_conv2d_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &quantize_conv_dw_4_conv2d_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  quantize_conv_dw_4_conv2d_layer, 12,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d_integer_UAUA,
  &quantize_conv_dw_4_conv2d_chain,
  NULL, &quantize_conv_pw_4_conv2d_layer, AI_STATIC, 
  .groups = 32, 
  .nl_func = NULL, 
  .filter_stride = AI_SHAPE_2D_INIT(2, 2), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 2, 2), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  quantize_conv_pw_3_conv2d_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &quantize_conv_dw_3_conv2d_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &quantize_conv_pw_3_conv2d_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &quantize_conv_pw_3_conv2d_weights, &quantize_conv_pw_3_conv2d_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &quantize_conv_pw_3_conv2d_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  quantize_conv_pw_3_conv2d_layer, 10,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d_integer_UAUA,
  &quantize_conv_pw_3_conv2d_chain,
  NULL, &quantize_conv_dw_4_conv2d_layer, AI_STATIC, 
  .groups = 1, 
  .nl_func = NULL, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  quantize_conv_dw_3_conv2d_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &quantize_conv_pw_2_conv2d_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &quantize_conv_dw_3_conv2d_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &quantize_conv_dw_3_conv2d_weights, &quantize_conv_dw_3_conv2d_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &quantize_conv_dw_3_conv2d_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  quantize_conv_dw_3_conv2d_layer, 9,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d_integer_UAUA,
  &quantize_conv_dw_3_conv2d_chain,
  NULL, &quantize_conv_pw_3_conv2d_layer, AI_STATIC, 
  .groups = 32, 
  .nl_func = NULL, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 1, 1, 1, 1), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  quantize_conv_pw_2_conv2d_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &quantize_conv_dw_2_conv2d_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &quantize_conv_pw_2_conv2d_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &quantize_conv_pw_2_conv2d_weights, &quantize_conv_pw_2_conv2d_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &quantize_conv_pw_2_conv2d_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  quantize_conv_pw_2_conv2d_layer, 7,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d_integer_UAUA,
  &quantize_conv_pw_2_conv2d_chain,
  NULL, &quantize_conv_dw_3_conv2d_layer, AI_STATIC, 
  .groups = 1, 
  .nl_func = NULL, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  quantize_conv_dw_2_conv2d_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &quantize_conv_pw_1_conv2d_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &quantize_conv_dw_2_conv2d_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &quantize_conv_dw_2_conv2d_weights, &quantize_conv_dw_2_conv2d_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &quantize_conv_dw_2_conv2d_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  quantize_conv_dw_2_conv2d_layer, 6,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d_integer_UAUA,
  &quantize_conv_dw_2_conv2d_chain,
  NULL, &quantize_conv_pw_2_conv2d_layer, AI_STATIC, 
  .groups = 16, 
  .nl_func = NULL, 
  .filter_stride = AI_SHAPE_2D_INIT(2, 2), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 2, 2), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  quantize_conv_pw_1_conv2d_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &quantize_conv_dw_1_conv2d_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &quantize_conv_pw_1_conv2d_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &quantize_conv_pw_1_conv2d_weights, &quantize_conv_pw_1_conv2d_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &quantize_conv_pw_1_conv2d_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  quantize_conv_pw_1_conv2d_layer, 4,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d_integer_UAUA,
  &quantize_conv_pw_1_conv2d_chain,
  NULL, &quantize_conv_dw_2_conv2d_layer, AI_STATIC, 
  .groups = 1, 
  .nl_func = NULL, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  quantize_conv_dw_1_conv2d_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &quantize_conv1_conv2d_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &quantize_conv_dw_1_conv2d_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &quantize_conv_dw_1_conv2d_weights, &quantize_conv_dw_1_conv2d_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &quantize_conv_dw_1_conv2d_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  quantize_conv_dw_1_conv2d_layer, 3,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d_integer_UAUA,
  &quantize_conv_dw_1_conv2d_chain,
  NULL, &quantize_conv_pw_1_conv2d_layer, AI_STATIC, 
  .groups = 8, 
  .nl_func = NULL, 
  .filter_stride = AI_SHAPE_2D_INIT(2, 2), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 2, 2), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  quantize_conv1_conv2d_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &quantize_input_2_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &quantize_conv1_conv2d_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &quantize_conv1_conv2d_weights, &quantize_conv1_conv2d_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &quantize_conv1_conv2d_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  quantize_conv1_conv2d_layer, 1,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d_integer_UAUA,
  &quantize_conv1_conv2d_chain,
  NULL, &quantize_conv_dw_1_conv2d_layer, AI_STATIC, 
  .groups = 1, 
  .nl_func = NULL, 
  .filter_stride = AI_SHAPE_2D_INIT(2, 2), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 2, 2), 
)


#if (AI_TOOLS_API_VERSION < AI_TOOLS_API_VERSION_1_5)

AI_NETWORK_OBJ_DECLARE(
  AI_NET_OBJ_INSTANCE, AI_STATIC,
  AI_BUFFER_INIT(AI_FLAG_NONE,  AI_BUFFER_FORMAT_U8,
    AI_BUFFER_SHAPE_INIT(AI_SHAPE_BCWH, 4, 1, 134776, 1, 1),
    134776, NULL, NULL),
  AI_BUFFER_INIT(AI_FLAG_NONE,  AI_BUFFER_FORMAT_U8,
    AI_BUFFER_SHAPE_INIT(AI_SHAPE_BCWH, 4, 1, 101144, 1, 1),
    101144, NULL, NULL),
  AI_TENSOR_LIST_IO_OBJ_INIT(AI_FLAG_NONE, AI_NETWORK_IN_NUM, &quantize_input_2_output),
  AI_TENSOR_LIST_IO_OBJ_INIT(AI_FLAG_NONE, AI_NETWORK_OUT_NUM, &act_softmax_output),
  &quantize_conv1_conv2d_layer, 0, NULL)

#else

AI_NETWORK_OBJ_DECLARE(
  AI_NET_OBJ_INSTANCE, AI_STATIC,
  AI_BUFFER_ARRAY_OBJ_INIT_STATIC(
  	AI_FLAG_NONE, 1,
    AI_BUFFER_INIT(AI_FLAG_NONE,  AI_BUFFER_FORMAT_U8,
      AI_BUFFER_SHAPE_INIT(AI_SHAPE_BCWH, 4, 1, 134776, 1, 1),
      134776, NULL, NULL)
  ),
  AI_BUFFER_ARRAY_OBJ_INIT_STATIC(
  	AI_FLAG_NONE, 1,
    AI_BUFFER_INIT(AI_FLAG_NONE,  AI_BUFFER_FORMAT_U8,
      AI_BUFFER_SHAPE_INIT(AI_SHAPE_BCWH, 4, 1, 101144, 1, 1),
      101144, NULL, NULL)
  ),
  AI_TENSOR_LIST_IO_OBJ_INIT(AI_FLAG_NONE, AI_NETWORK_IN_NUM, &quantize_input_2_output),
  AI_TENSOR_LIST_IO_OBJ_INIT(AI_FLAG_NONE, AI_NETWORK_OUT_NUM, &act_softmax_output),
  &quantize_conv1_conv2d_layer, 0, NULL)

#endif	/*(AI_TOOLS_API_VERSION < AI_TOOLS_API_VERSION_1_5)*/


/******************************************************************************/
AI_DECLARE_STATIC
ai_bool network_configure_activations(
  ai_network* net_ctx, const ai_network_params* params)
{
  AI_ASSERT(net_ctx)

  ai_ptr activations_map[1] = AI_C_ARRAY_INIT;

  if (ai_platform_get_activations_map(activations_map, 1, params)) {
    /* Updating activations (byte) offsets */
    quantize_conv1_conv2d_scratch0_array.data = AI_PTR(activations_map[0] + 0);
    quantize_conv1_conv2d_scratch0_array.data_start = AI_PTR(activations_map[0] + 0);
    quantize_conv1_conv2d_output_array.data = AI_PTR(activations_map[0] + 572);
    quantize_conv1_conv2d_output_array.data_start = AI_PTR(activations_map[0] + 572);
    quantize_conv_dw_1_conv2d_scratch0_array.data = AI_PTR(activations_map[0] + 100924);
    quantize_conv_dw_1_conv2d_scratch0_array.data_start = AI_PTR(activations_map[0] + 100924);
    quantize_conv_dw_1_conv2d_output_array.data = AI_PTR(activations_map[0] + 116);
    quantize_conv_dw_1_conv2d_output_array.data_start = AI_PTR(activations_map[0] + 116);
    quantize_conv_pw_1_conv2d_scratch0_array.data = AI_PTR(activations_map[0] + 0);
    quantize_conv_pw_1_conv2d_scratch0_array.data_start = AI_PTR(activations_map[0] + 0);
    quantize_conv_pw_1_conv2d_output_array.data = AI_PTR(activations_map[0] + 25204);
    quantize_conv_pw_1_conv2d_output_array.data_start = AI_PTR(activations_map[0] + 25204);
    quantize_conv_dw_2_conv2d_scratch0_array.data = AI_PTR(activations_map[0] + 0);
    quantize_conv_dw_2_conv2d_scratch0_array.data_start = AI_PTR(activations_map[0] + 0);
    quantize_conv_dw_2_conv2d_output_array.data = AI_PTR(activations_map[0] + 436);
    quantize_conv_dw_2_conv2d_output_array.data_start = AI_PTR(activations_map[0] + 436);
    quantize_conv_pw_2_conv2d_scratch0_array.data = AI_PTR(activations_map[0] + 0);
    quantize_conv_pw_2_conv2d_scratch0_array.data_start = AI_PTR(activations_map[0] + 0);
    quantize_conv_pw_2_conv2d_output_array.data = AI_PTR(activations_map[0] + 12980);
    quantize_conv_pw_2_conv2d_output_array.data_start = AI_PTR(activations_map[0] + 12980);
    quantize_conv_dw_3_conv2d_scratch0_array.data = AI_PTR(activations_map[0] + 0);
    quantize_conv_dw_3_conv2d_scratch0_array.data_start = AI_PTR(activations_map[0] + 0);
    quantize_conv_dw_3_conv2d_output_array.data = AI_PTR(activations_map[0] + 38068);
    quantize_conv_dw_3_conv2d_output_array.data_start = AI_PTR(activations_map[0] + 38068);
    quantize_conv_pw_3_conv2d_scratch0_array.data = AI_PTR(activations_map[0] + 0);
    quantize_conv_pw_3_conv2d_scratch0_array.data_start = AI_PTR(activations_map[0] + 0);
    quantize_conv_pw_3_conv2d_output_array.data = AI_PTR(activations_map[0] + 128);
    quantize_conv_pw_3_conv2d_output_array.data_start = AI_PTR(activations_map[0] + 128);
    quantize_conv_dw_4_conv2d_scratch0_array.data = AI_PTR(activations_map[0] + 25216);
    quantize_conv_dw_4_conv2d_scratch0_array.data_start = AI_PTR(activations_map[0] + 25216);
    quantize_conv_dw_4_conv2d_output_array.data = AI_PTR(activations_map[0] + 26084);
    quantize_conv_dw_4_conv2d_output_array.data_start = AI_PTR(activations_map[0] + 26084);
    quantize_conv_pw_4_conv2d_scratch0_array.data = AI_PTR(activations_map[0] + 0);
    quantize_conv_pw_4_conv2d_scratch0_array.data_start = AI_PTR(activations_map[0] + 0);
    quantize_conv_pw_4_conv2d_output_array.data = AI_PTR(activations_map[0] + 128);
    quantize_conv_pw_4_conv2d_output_array.data_start = AI_PTR(activations_map[0] + 128);
    quantize_conv_dw_5_conv2d_scratch0_array.data = AI_PTR(activations_map[0] + 12672);
    quantize_conv_dw_5_conv2d_scratch0_array.data_start = AI_PTR(activations_map[0] + 12672);
    quantize_conv_dw_5_conv2d_output_array.data = AI_PTR(activations_map[0] + 14404);
    quantize_conv_dw_5_conv2d_output_array.data_start = AI_PTR(activations_map[0] + 14404);
    quantize_conv_pw_5_conv2d_scratch0_array.data = AI_PTR(activations_map[0] + 0);
    quantize_conv_pw_5_conv2d_scratch0_array.data_start = AI_PTR(activations_map[0] + 0);
    quantize_conv_pw_5_conv2d_output_array.data = AI_PTR(activations_map[0] + 256);
    quantize_conv_pw_5_conv2d_output_array.data_start = AI_PTR(activations_map[0] + 256);
    quantize_conv_dw_6_conv2d_scratch0_array.data = AI_PTR(activations_map[0] + 12800);
    quantize_conv_dw_6_conv2d_scratch0_array.data_start = AI_PTR(activations_map[0] + 12800);
    quantize_conv_dw_6_conv2d_output_array.data = AI_PTR(activations_map[0] + 14532);
    quantize_conv_dw_6_conv2d_output_array.data_start = AI_PTR(activations_map[0] + 14532);
    quantize_conv_pw_6_conv2d_scratch0_array.data = AI_PTR(activations_map[0] + 0);
    quantize_conv_pw_6_conv2d_scratch0_array.data_start = AI_PTR(activations_map[0] + 0);
    quantize_conv_pw_6_conv2d_output_array.data = AI_PTR(activations_map[0] + 256);
    quantize_conv_pw_6_conv2d_output_array.data_start = AI_PTR(activations_map[0] + 256);
    quantize_conv_dw_7_conv2d_scratch0_array.data = AI_PTR(activations_map[0] + 6528);
    quantize_conv_dw_7_conv2d_scratch0_array.data_start = AI_PTR(activations_map[0] + 6528);
    quantize_conv_dw_7_conv2d_output_array.data = AI_PTR(activations_map[0] + 9988);
    quantize_conv_dw_7_conv2d_output_array.data_start = AI_PTR(activations_map[0] + 9988);
    quantize_conv_pw_7_conv2d_scratch0_array.data = AI_PTR(activations_map[0] + 0);
    quantize_conv_pw_7_conv2d_scratch0_array.data_start = AI_PTR(activations_map[0] + 0);
    quantize_conv_pw_7_conv2d_output_array.data = AI_PTR(activations_map[0] + 512);
    quantize_conv_pw_7_conv2d_output_array.data_start = AI_PTR(activations_map[0] + 512);
    quantize_conv_dw_8_conv2d_scratch0_array.data = AI_PTR(activations_map[0] + 6784);
    quantize_conv_dw_8_conv2d_scratch0_array.data_start = AI_PTR(activations_map[0] + 6784);
    quantize_conv_dw_8_conv2d_output_array.data = AI_PTR(activations_map[0] + 10244);
    quantize_conv_dw_8_conv2d_output_array.data_start = AI_PTR(activations_map[0] + 10244);
    quantize_conv_pw_8_conv2d_scratch0_array.data = AI_PTR(activations_map[0] + 0);
    quantize_conv_pw_8_conv2d_scratch0_array.data_start = AI_PTR(activations_map[0] + 0);
    quantize_conv_pw_8_conv2d_output_array.data = AI_PTR(activations_map[0] + 512);
    quantize_conv_pw_8_conv2d_output_array.data_start = AI_PTR(activations_map[0] + 512);
    quantize_conv_dw_9_conv2d_scratch0_array.data = AI_PTR(activations_map[0] + 6784);
    quantize_conv_dw_9_conv2d_scratch0_array.data_start = AI_PTR(activations_map[0] + 6784);
    quantize_conv_dw_9_conv2d_output_array.data = AI_PTR(activations_map[0] + 10244);
    quantize_conv_dw_9_conv2d_output_array.data_start = AI_PTR(activations_map[0] + 10244);
    quantize_conv_pw_9_conv2d_scratch0_array.data = AI_PTR(activations_map[0] + 0);
    quantize_conv_pw_9_conv2d_scratch0_array.data_start = AI_PTR(activations_map[0] + 0);
    quantize_conv_pw_9_conv2d_output_array.data = AI_PTR(activations_map[0] + 512);
    quantize_conv_pw_9_conv2d_output_array.data_start = AI_PTR(activations_map[0] + 512);
    quantize_conv_dw_10_conv2d_scratch0_array.data = AI_PTR(activations_map[0] + 6784);
    quantize_conv_dw_10_conv2d_scratch0_array.data_start = AI_PTR(activations_map[0] + 6784);
    quantize_conv_dw_10_conv2d_output_array.data = AI_PTR(activations_map[0] + 10244);
    quantize_conv_dw_10_conv2d_output_array.data_start = AI_PTR(activations_map[0] + 10244);
    quantize_conv_pw_10_conv2d_scratch0_array.data = AI_PTR(activations_map[0] + 0);
    quantize_conv_pw_10_conv2d_scratch0_array.data_start = AI_PTR(activations_map[0] + 0);
    quantize_conv_pw_10_conv2d_output_array.data = AI_PTR(activations_map[0] + 512);
    quantize_conv_pw_10_conv2d_output_array.data_start = AI_PTR(activations_map[0] + 512);
    quantize_conv_dw_11_conv2d_scratch0_array.data = AI_PTR(activations_map[0] + 6784);
    quantize_conv_dw_11_conv2d_scratch0_array.data_start = AI_PTR(activations_map[0] + 6784);
    quantize_conv_dw_11_conv2d_output_array.data = AI_PTR(activations_map[0] + 10244);
    quantize_conv_dw_11_conv2d_output_array.data_start = AI_PTR(activations_map[0] + 10244);
    quantize_conv_pw_11_conv2d_scratch0_array.data = AI_PTR(activations_map[0] + 0);
    quantize_conv_pw_11_conv2d_scratch0_array.data_start = AI_PTR(activations_map[0] + 0);
    quantize_conv_pw_11_conv2d_scratch1_array.data = AI_PTR(activations_map[0] + 16516);
    quantize_conv_pw_11_conv2d_scratch1_array.data_start = AI_PTR(activations_map[0] + 16516);
    quantize_conv_pw_11_conv2d_output_array.data = AI_PTR(activations_map[0] + 512);
    quantize_conv_pw_11_conv2d_output_array.data_start = AI_PTR(activations_map[0] + 512);
    quantize_conv_preds_conv2d_scratch0_array.data = AI_PTR(activations_map[0] + 768);
    quantize_conv_preds_conv2d_scratch0_array.data_start = AI_PTR(activations_map[0] + 768);
    quantize_conv_preds_conv2d_output_array.data = AI_PTR(activations_map[0] + 0);
    quantize_conv_preds_conv2d_output_array.data_start = AI_PTR(activations_map[0] + 0);
    quantize_conv_preds_conv2d_0_conversion_output_array.data = AI_PTR(activations_map[0] + 20);
    quantize_conv_preds_conv2d_0_conversion_output_array.data_start = AI_PTR(activations_map[0] + 20);
    
    return true;
  }
  AI_ERROR_TRAP(net_ctx, INIT_FAILED, NETWORK_ACTIVATIONS);
  return false;
}



/******************************************************************************/
AI_DECLARE_STATIC
ai_bool network_configure_weights(
  ai_network* net_ctx, const ai_network_params* params)
{
  AI_ASSERT(net_ctx)

  ai_ptr weights_map[1] = AI_C_ARRAY_INIT;

  if (ai_platform_get_weights_map(weights_map, 1, params)) {
    /* Updating weights (byte) offsets */
    
    quantize_conv1_conv2d_weights_array.format |= AI_FMT_FLAG_CONST;
    quantize_conv1_conv2d_weights_array.data = AI_PTR(weights_map[0] + 0);
    quantize_conv1_conv2d_weights_array.data_start = AI_PTR(weights_map[0] + 0);
    quantize_conv1_conv2d_bias_array.format |= AI_FMT_FLAG_CONST;
    quantize_conv1_conv2d_bias_array.data = AI_PTR(weights_map[0] + 216);
    quantize_conv1_conv2d_bias_array.data_start = AI_PTR(weights_map[0] + 216);
    quantize_conv_dw_1_conv2d_weights_array.format |= AI_FMT_FLAG_CONST;
    quantize_conv_dw_1_conv2d_weights_array.data = AI_PTR(weights_map[0] + 248);
    quantize_conv_dw_1_conv2d_weights_array.data_start = AI_PTR(weights_map[0] + 248);
    quantize_conv_dw_1_conv2d_bias_array.format |= AI_FMT_FLAG_CONST;
    quantize_conv_dw_1_conv2d_bias_array.data = AI_PTR(weights_map[0] + 320);
    quantize_conv_dw_1_conv2d_bias_array.data_start = AI_PTR(weights_map[0] + 320);
    quantize_conv_pw_1_conv2d_weights_array.format |= AI_FMT_FLAG_CONST;
    quantize_conv_pw_1_conv2d_weights_array.data = AI_PTR(weights_map[0] + 352);
    quantize_conv_pw_1_conv2d_weights_array.data_start = AI_PTR(weights_map[0] + 352);
    quantize_conv_pw_1_conv2d_bias_array.format |= AI_FMT_FLAG_CONST;
    quantize_conv_pw_1_conv2d_bias_array.data = AI_PTR(weights_map[0] + 480);
    quantize_conv_pw_1_conv2d_bias_array.data_start = AI_PTR(weights_map[0] + 480);
    quantize_conv_dw_2_conv2d_weights_array.format |= AI_FMT_FLAG_CONST;
    quantize_conv_dw_2_conv2d_weights_array.data = AI_PTR(weights_map[0] + 544);
    quantize_conv_dw_2_conv2d_weights_array.data_start = AI_PTR(weights_map[0] + 544);
    quantize_conv_dw_2_conv2d_bias_array.format |= AI_FMT_FLAG_CONST;
    quantize_conv_dw_2_conv2d_bias_array.data = AI_PTR(weights_map[0] + 688);
    quantize_conv_dw_2_conv2d_bias_array.data_start = AI_PTR(weights_map[0] + 688);
    quantize_conv_pw_2_conv2d_weights_array.format |= AI_FMT_FLAG_CONST;
    quantize_conv_pw_2_conv2d_weights_array.data = AI_PTR(weights_map[0] + 752);
    quantize_conv_pw_2_conv2d_weights_array.data_start = AI_PTR(weights_map[0] + 752);
    quantize_conv_pw_2_conv2d_bias_array.format |= AI_FMT_FLAG_CONST;
    quantize_conv_pw_2_conv2d_bias_array.data = AI_PTR(weights_map[0] + 1264);
    quantize_conv_pw_2_conv2d_bias_array.data_start = AI_PTR(weights_map[0] + 1264);
    quantize_conv_dw_3_conv2d_weights_array.format |= AI_FMT_FLAG_CONST;
    quantize_conv_dw_3_conv2d_weights_array.data = AI_PTR(weights_map[0] + 1392);
    quantize_conv_dw_3_conv2d_weights_array.data_start = AI_PTR(weights_map[0] + 1392);
    quantize_conv_dw_3_conv2d_bias_array.format |= AI_FMT_FLAG_CONST;
    quantize_conv_dw_3_conv2d_bias_array.data = AI_PTR(weights_map[0] + 1680);
    quantize_conv_dw_3_conv2d_bias_array.data_start = AI_PTR(weights_map[0] + 1680);
    quantize_conv_pw_3_conv2d_weights_array.format |= AI_FMT_FLAG_CONST;
    quantize_conv_pw_3_conv2d_weights_array.data = AI_PTR(weights_map[0] + 1808);
    quantize_conv_pw_3_conv2d_weights_array.data_start = AI_PTR(weights_map[0] + 1808);
    quantize_conv_pw_3_conv2d_bias_array.format |= AI_FMT_FLAG_CONST;
    quantize_conv_pw_3_conv2d_bias_array.data = AI_PTR(weights_map[0] + 2832);
    quantize_conv_pw_3_conv2d_bias_array.data_start = AI_PTR(weights_map[0] + 2832);
    quantize_conv_dw_4_conv2d_weights_array.format |= AI_FMT_FLAG_CONST;
    quantize_conv_dw_4_conv2d_weights_array.data = AI_PTR(weights_map[0] + 2960);
    quantize_conv_dw_4_conv2d_weights_array.data_start = AI_PTR(weights_map[0] + 2960);
    quantize_conv_dw_4_conv2d_bias_array.format |= AI_FMT_FLAG_CONST;
    quantize_conv_dw_4_conv2d_bias_array.data = AI_PTR(weights_map[0] + 3248);
    quantize_conv_dw_4_conv2d_bias_array.data_start = AI_PTR(weights_map[0] + 3248);
    quantize_conv_pw_4_conv2d_weights_array.format |= AI_FMT_FLAG_CONST;
    quantize_conv_pw_4_conv2d_weights_array.data = AI_PTR(weights_map[0] + 3376);
    quantize_conv_pw_4_conv2d_weights_array.data_start = AI_PTR(weights_map[0] + 3376);
    quantize_conv_pw_4_conv2d_bias_array.format |= AI_FMT_FLAG_CONST;
    quantize_conv_pw_4_conv2d_bias_array.data = AI_PTR(weights_map[0] + 5424);
    quantize_conv_pw_4_conv2d_bias_array.data_start = AI_PTR(weights_map[0] + 5424);
    quantize_conv_dw_5_conv2d_weights_array.format |= AI_FMT_FLAG_CONST;
    quantize_conv_dw_5_conv2d_weights_array.data = AI_PTR(weights_map[0] + 5680);
    quantize_conv_dw_5_conv2d_weights_array.data_start = AI_PTR(weights_map[0] + 5680);
    quantize_conv_dw_5_conv2d_bias_array.format |= AI_FMT_FLAG_CONST;
    quantize_conv_dw_5_conv2d_bias_array.data = AI_PTR(weights_map[0] + 6256);
    quantize_conv_dw_5_conv2d_bias_array.data_start = AI_PTR(weights_map[0] + 6256);
    quantize_conv_pw_5_conv2d_weights_array.format |= AI_FMT_FLAG_CONST;
    quantize_conv_pw_5_conv2d_weights_array.data = AI_PTR(weights_map[0] + 6512);
    quantize_conv_pw_5_conv2d_weights_array.data_start = AI_PTR(weights_map[0] + 6512);
    quantize_conv_pw_5_conv2d_bias_array.format |= AI_FMT_FLAG_CONST;
    quantize_conv_pw_5_conv2d_bias_array.data = AI_PTR(weights_map[0] + 10608);
    quantize_conv_pw_5_conv2d_bias_array.data_start = AI_PTR(weights_map[0] + 10608);
    quantize_conv_dw_6_conv2d_weights_array.format |= AI_FMT_FLAG_CONST;
    quantize_conv_dw_6_conv2d_weights_array.data = AI_PTR(weights_map[0] + 10864);
    quantize_conv_dw_6_conv2d_weights_array.data_start = AI_PTR(weights_map[0] + 10864);
    quantize_conv_dw_6_conv2d_bias_array.format |= AI_FMT_FLAG_CONST;
    quantize_conv_dw_6_conv2d_bias_array.data = AI_PTR(weights_map[0] + 11440);
    quantize_conv_dw_6_conv2d_bias_array.data_start = AI_PTR(weights_map[0] + 11440);
    quantize_conv_pw_6_conv2d_weights_array.format |= AI_FMT_FLAG_CONST;
    quantize_conv_pw_6_conv2d_weights_array.data = AI_PTR(weights_map[0] + 11696);
    quantize_conv_pw_6_conv2d_weights_array.data_start = AI_PTR(weights_map[0] + 11696);
    quantize_conv_pw_6_conv2d_bias_array.format |= AI_FMT_FLAG_CONST;
    quantize_conv_pw_6_conv2d_bias_array.data = AI_PTR(weights_map[0] + 19888);
    quantize_conv_pw_6_conv2d_bias_array.data_start = AI_PTR(weights_map[0] + 19888);
    quantize_conv_dw_7_conv2d_weights_array.format |= AI_FMT_FLAG_CONST;
    quantize_conv_dw_7_conv2d_weights_array.data = AI_PTR(weights_map[0] + 20400);
    quantize_conv_dw_7_conv2d_weights_array.data_start = AI_PTR(weights_map[0] + 20400);
    quantize_conv_dw_7_conv2d_bias_array.format |= AI_FMT_FLAG_CONST;
    quantize_conv_dw_7_conv2d_bias_array.data = AI_PTR(weights_map[0] + 21552);
    quantize_conv_dw_7_conv2d_bias_array.data_start = AI_PTR(weights_map[0] + 21552);
    quantize_conv_pw_7_conv2d_weights_array.format |= AI_FMT_FLAG_CONST;
    quantize_conv_pw_7_conv2d_weights_array.data = AI_PTR(weights_map[0] + 22064);
    quantize_conv_pw_7_conv2d_weights_array.data_start = AI_PTR(weights_map[0] + 22064);
    quantize_conv_pw_7_conv2d_bias_array.format |= AI_FMT_FLAG_CONST;
    quantize_conv_pw_7_conv2d_bias_array.data = AI_PTR(weights_map[0] + 38448);
    quantize_conv_pw_7_conv2d_bias_array.data_start = AI_PTR(weights_map[0] + 38448);
    quantize_conv_dw_8_conv2d_weights_array.format |= AI_FMT_FLAG_CONST;
    quantize_conv_dw_8_conv2d_weights_array.data = AI_PTR(weights_map[0] + 38960);
    quantize_conv_dw_8_conv2d_weights_array.data_start = AI_PTR(weights_map[0] + 38960);
    quantize_conv_dw_8_conv2d_bias_array.format |= AI_FMT_FLAG_CONST;
    quantize_conv_dw_8_conv2d_bias_array.data = AI_PTR(weights_map[0] + 40112);
    quantize_conv_dw_8_conv2d_bias_array.data_start = AI_PTR(weights_map[0] + 40112);
    quantize_conv_pw_8_conv2d_weights_array.format |= AI_FMT_FLAG_CONST;
    quantize_conv_pw_8_conv2d_weights_array.data = AI_PTR(weights_map[0] + 40624);
    quantize_conv_pw_8_conv2d_weights_array.data_start = AI_PTR(weights_map[0] + 40624);
    quantize_conv_pw_8_conv2d_bias_array.format |= AI_FMT_FLAG_CONST;
    quantize_conv_pw_8_conv2d_bias_array.data = AI_PTR(weights_map[0] + 57008);
    quantize_conv_pw_8_conv2d_bias_array.data_start = AI_PTR(weights_map[0] + 57008);
    quantize_conv_dw_9_conv2d_weights_array.format |= AI_FMT_FLAG_CONST;
    quantize_conv_dw_9_conv2d_weights_array.data = AI_PTR(weights_map[0] + 57520);
    quantize_conv_dw_9_conv2d_weights_array.data_start = AI_PTR(weights_map[0] + 57520);
    quantize_conv_dw_9_conv2d_bias_array.format |= AI_FMT_FLAG_CONST;
    quantize_conv_dw_9_conv2d_bias_array.data = AI_PTR(weights_map[0] + 58672);
    quantize_conv_dw_9_conv2d_bias_array.data_start = AI_PTR(weights_map[0] + 58672);
    quantize_conv_pw_9_conv2d_weights_array.format |= AI_FMT_FLAG_CONST;
    quantize_conv_pw_9_conv2d_weights_array.data = AI_PTR(weights_map[0] + 59184);
    quantize_conv_pw_9_conv2d_weights_array.data_start = AI_PTR(weights_map[0] + 59184);
    quantize_conv_pw_9_conv2d_bias_array.format |= AI_FMT_FLAG_CONST;
    quantize_conv_pw_9_conv2d_bias_array.data = AI_PTR(weights_map[0] + 75568);
    quantize_conv_pw_9_conv2d_bias_array.data_start = AI_PTR(weights_map[0] + 75568);
    quantize_conv_dw_10_conv2d_weights_array.format |= AI_FMT_FLAG_CONST;
    quantize_conv_dw_10_conv2d_weights_array.data = AI_PTR(weights_map[0] + 76080);
    quantize_conv_dw_10_conv2d_weights_array.data_start = AI_PTR(weights_map[0] + 76080);
    quantize_conv_dw_10_conv2d_bias_array.format |= AI_FMT_FLAG_CONST;
    quantize_conv_dw_10_conv2d_bias_array.data = AI_PTR(weights_map[0] + 77232);
    quantize_conv_dw_10_conv2d_bias_array.data_start = AI_PTR(weights_map[0] + 77232);
    quantize_conv_pw_10_conv2d_weights_array.format |= AI_FMT_FLAG_CONST;
    quantize_conv_pw_10_conv2d_weights_array.data = AI_PTR(weights_map[0] + 77744);
    quantize_conv_pw_10_conv2d_weights_array.data_start = AI_PTR(weights_map[0] + 77744);
    quantize_conv_pw_10_conv2d_bias_array.format |= AI_FMT_FLAG_CONST;
    quantize_conv_pw_10_conv2d_bias_array.data = AI_PTR(weights_map[0] + 94128);
    quantize_conv_pw_10_conv2d_bias_array.data_start = AI_PTR(weights_map[0] + 94128);
    quantize_conv_dw_11_conv2d_weights_array.format |= AI_FMT_FLAG_CONST;
    quantize_conv_dw_11_conv2d_weights_array.data = AI_PTR(weights_map[0] + 94640);
    quantize_conv_dw_11_conv2d_weights_array.data_start = AI_PTR(weights_map[0] + 94640);
    quantize_conv_dw_11_conv2d_bias_array.format |= AI_FMT_FLAG_CONST;
    quantize_conv_dw_11_conv2d_bias_array.data = AI_PTR(weights_map[0] + 95792);
    quantize_conv_dw_11_conv2d_bias_array.data_start = AI_PTR(weights_map[0] + 95792);
    quantize_conv_pw_11_conv2d_weights_array.format |= AI_FMT_FLAG_CONST;
    quantize_conv_pw_11_conv2d_weights_array.data = AI_PTR(weights_map[0] + 96304);
    quantize_conv_pw_11_conv2d_weights_array.data_start = AI_PTR(weights_map[0] + 96304);
    quantize_conv_pw_11_conv2d_bias_array.format |= AI_FMT_FLAG_CONST;
    quantize_conv_pw_11_conv2d_bias_array.data = AI_PTR(weights_map[0] + 129072);
    quantize_conv_pw_11_conv2d_bias_array.data_start = AI_PTR(weights_map[0] + 129072);
    quantize_conv_preds_conv2d_weights_array.format |= AI_FMT_FLAG_CONST;
    quantize_conv_preds_conv2d_weights_array.data = AI_PTR(weights_map[0] + 130096);
    quantize_conv_preds_conv2d_weights_array.data_start = AI_PTR(weights_map[0] + 130096);
    quantize_conv_preds_conv2d_bias_array.format |= AI_FMT_FLAG_CONST;
    quantize_conv_preds_conv2d_bias_array.data = AI_PTR(weights_map[0] + 134704);
    quantize_conv_preds_conv2d_bias_array.data_start = AI_PTR(weights_map[0] + 134704);
    return true;
  }
  AI_ERROR_TRAP(net_ctx, INIT_FAILED, NETWORK_WEIGHTS);
  return false;
}


/**  PUBLIC APIs SECTION  *****************************************************/

AI_DEPRECATED
AI_API_ENTRY
ai_bool ai_network_get_info(
  ai_handle network, ai_network_report* report)
{
  ai_network* net_ctx = AI_NETWORK_ACQUIRE_CTX(network);

  if (report && net_ctx)
  {
    ai_network_report r = {
      .model_name        = AI_NETWORK_MODEL_NAME,
      .model_signature   = AI_NETWORK_MODEL_SIGNATURE,
      .model_datetime    = AI_TOOLS_DATE_TIME,
      
      .compile_datetime  = AI_TOOLS_COMPILE_TIME,
      
      .runtime_revision  = ai_platform_runtime_get_revision(),
      .runtime_version   = ai_platform_runtime_get_version(),

      .tool_revision     = AI_TOOLS_REVISION_ID,
      .tool_version      = {AI_TOOLS_VERSION_MAJOR, AI_TOOLS_VERSION_MINOR,
                            AI_TOOLS_VERSION_MICRO, 0x0},
      .tool_api_version  = AI_STRUCT_INIT,

      .api_version            = ai_platform_api_get_version(),
      .interface_api_version  = ai_platform_interface_api_get_version(),
      
      .n_macc            = 11801396,
      .n_inputs          = 0,
      .inputs            = NULL,
      .n_outputs         = 0,
      .outputs           = NULL,
      .params            = AI_STRUCT_INIT,
      .activations       = AI_STRUCT_INIT,
      .n_nodes           = 0,
      .signature         = 0x0,
    };

    if (!ai_platform_api_get_network_report(network, &r)) return false;

    *report = r;
    return true;
  }
  return false;
}


AI_API_ENTRY
ai_bool ai_network_get_report(
  ai_handle network, ai_network_report* report)
{
  ai_network* net_ctx = AI_NETWORK_ACQUIRE_CTX(network);

  if (report && net_ctx)
  {
    ai_network_report r = {
      .model_name        = AI_NETWORK_MODEL_NAME,
      .model_signature   = AI_NETWORK_MODEL_SIGNATURE,
      .model_datetime    = AI_TOOLS_DATE_TIME,
      
      .compile_datetime  = AI_TOOLS_COMPILE_TIME,
      
      .runtime_revision  = ai_platform_runtime_get_revision(),
      .runtime_version   = ai_platform_runtime_get_version(),

      .tool_revision     = AI_TOOLS_REVISION_ID,
      .tool_version      = {AI_TOOLS_VERSION_MAJOR, AI_TOOLS_VERSION_MINOR,
                            AI_TOOLS_VERSION_MICRO, 0x0},
      .tool_api_version  = AI_STRUCT_INIT,

      .api_version            = ai_platform_api_get_version(),
      .interface_api_version  = ai_platform_interface_api_get_version(),
      
      .n_macc            = 11801396,
      .n_inputs          = 0,
      .inputs            = NULL,
      .n_outputs         = 0,
      .outputs           = NULL,
      .map_signature     = AI_MAGIC_SIGNATURE,
      .map_weights       = AI_STRUCT_INIT,
      .map_activations   = AI_STRUCT_INIT,
      .n_nodes           = 0,
      .signature         = 0x0,
    };

    if (!ai_platform_api_get_network_report(network, &r)) return false;

    *report = r;
    return true;
  }
  return false;
}

AI_API_ENTRY
ai_error ai_network_get_error(ai_handle network)
{
  return ai_platform_network_get_error(network);
}

AI_API_ENTRY
ai_error ai_network_create(
  ai_handle* network, const ai_buffer* network_config)
{
  return ai_platform_network_create(
    network, network_config, 
    &AI_NET_OBJ_INSTANCE,
    AI_TOOLS_API_VERSION_MAJOR, AI_TOOLS_API_VERSION_MINOR, AI_TOOLS_API_VERSION_MICRO);
}

AI_API_ENTRY
ai_error ai_network_create_and_init(
  ai_handle* network, const ai_handle activations[], const ai_handle weights[])
{
    ai_error err;
    ai_network_params params;

    err = ai_network_create(network, AI_NETWORK_DATA_CONFIG);
    if (err.type != AI_ERROR_NONE)
        return err;
    if (ai_network_data_params_get(&params) != true) {
        err = ai_network_get_error(*network);
        return err;
    }
#if defined(AI_NETWORK_DATA_ACTIVATIONS_COUNT)
    if (activations) {
        /* set the addresses of the activations buffers */
        for (int idx=0;idx<params.map_activations.size;idx++)
            AI_BUFFER_ARRAY_ITEM_SET_ADDRESS(&params.map_activations, idx, activations[idx]);
    }
#endif
#if defined(AI_NETWORK_DATA_WEIGHTS_COUNT)
    if (weights) {
        /* set the addresses of the weight buffers */
        for (int idx=0;idx<params.map_weights.size;idx++)
            AI_BUFFER_ARRAY_ITEM_SET_ADDRESS(&params.map_weights, idx, weights[idx]);
    }
#endif
    if (ai_network_init(*network, &params) != true) {
        err = ai_network_get_error(*network);
    }
    return err;
}

AI_API_ENTRY
ai_buffer* ai_network_inputs_get(ai_handle network, ai_u16 *n_buffer)
{
  if (network == AI_HANDLE_NULL) {
    network = (ai_handle)&AI_NET_OBJ_INSTANCE;
    ((ai_network *)network)->magic = AI_MAGIC_CONTEXT_TOKEN;
  }
  return ai_platform_inputs_get(network, n_buffer);
}

AI_API_ENTRY
ai_buffer* ai_network_outputs_get(ai_handle network, ai_u16 *n_buffer)
{
  if (network == AI_HANDLE_NULL) {
    network = (ai_handle)&AI_NET_OBJ_INSTANCE;
    ((ai_network *)network)->magic = AI_MAGIC_CONTEXT_TOKEN;
  }
  return ai_platform_outputs_get(network, n_buffer);
}

AI_API_ENTRY
ai_handle ai_network_destroy(ai_handle network)
{
  return ai_platform_network_destroy(network);
}

AI_API_ENTRY
ai_bool ai_network_init(
  ai_handle network, const ai_network_params* params)
{
  ai_network* net_ctx = ai_platform_network_init(network, params);
  if (!net_ctx) return false;

  ai_bool ok = true;
  ok &= network_configure_weights(net_ctx, params);
  ok &= network_configure_activations(net_ctx, params);

  ok &= ai_platform_network_post_init(network);

  return ok;
}


AI_API_ENTRY
ai_i32 ai_network_run(
  ai_handle network, const ai_buffer* input, ai_buffer* output)
{
  return ai_platform_network_process(network, input, output);
}

AI_API_ENTRY
ai_i32 ai_network_forward(ai_handle network, const ai_buffer* input)
{
  return ai_platform_network_process(network, input, NULL);
}



#undef AI_NETWORK_MODEL_SIGNATURE
#undef AI_NET_OBJ_INSTANCE
#undef AI_TOOLS_DATE_TIME
#undef AI_TOOLS_COMPILE_TIME

