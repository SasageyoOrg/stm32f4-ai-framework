#include "utils.h"

/**
 * @brief Nearest Neighbor algorithm to resize the image buffer
 * @param input 		image buffer read from USB host
 * @param output 		image buffer used as input for the neural network
 * @param srcW, srcH	source width and height
 * @param dstW, dstH	destination width and height
 */
void UTILS_ResizeBuffer(const uint8_t* input, uint8_t* output, int srcW, int srcH, int dstW, int dstH)
{
	const int x_ratio = (int)((srcW << 16) / dstW);
	const int y_ratio = (int)((srcH << 16) / dstH);
	const int colors = 3;

	for (int y = 0; y < dstH; y++)
	{
		int y2_xsource = ((y * y_ratio) >> 16) * srcW;
		int i_xdest = y * dstW;

		for (int x = 0; x < dstW; x++)
		{
			int x2 = ((x * x_ratio) >> 16) ;
			int y2_x2_colors = (y2_xsource + x2) * colors;
			int i_x_colors = (i_xdest + x) * colors;

			output[i_x_colors]     = input[y2_x2_colors];
			output[i_x_colors + 1] = input[y2_x2_colors + 1];
			output[i_x_colors + 2] = input[y2_x2_colors + 2];
		}
	}
}
