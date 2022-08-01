#include "utils.h"

/**
 * @brief Bubble sorting algorithm on probabilities
 * @param prob pointer to probabilities buffer
 * @param classes pointer to classes buffer
 * @param size numer of values
 */
void UTILS_Bubblesort(float *prob, int *classes, int size)
{
	float p;
	int c;

	for (int i = 0; i < size; i++)
	{
		for (int ii = 0; ii < size - i - 1; ii++)
		{
			if (prob[ii] < prob[ii + 1])
			{
				p = prob[ii];
				prob[ii] = prob[ii + 1];
				prob[ii + 1] = p;
				c = classes[ii];
				classes[ii] = classes[ii + 1];
				classes[ii + 1] = c;
			}
		}
	}
}
