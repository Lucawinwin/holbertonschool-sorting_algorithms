#include "sort.h"

/**
* bubble_sort - function that sorts an array of integers in ascending order
* @array: array of integers
* @size: size of array
* Return: bubble sorted array
*/
void bubble_sort(int *array, size_t size)
{
	int tmp = 0, sw = 1;
	unsigned int i = 0;

	if (array == NULL || size < 2)
		return;

	while (sw != 0)
	{
		sw = 0;
		for (i = 0; i < size - 1; i++)
		{
			if (array[i] > array[i + 1])
			{
				tmp = array[i];
				array[i] = array[i + 1];
				array[i + 1] = tmp;
				sw = 1;
				print_array(array, size);
			}
		}
	}
}
