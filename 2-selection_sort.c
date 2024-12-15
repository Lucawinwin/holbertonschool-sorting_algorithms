#include "sort.h"

/**
 * selection_sort - sorts an array of ints in ascending order
 * @array: array to sort
 * @size: size of the array
 */

void selection_sort(int *array, size_t size)
{
	int aux = 0;
	unsigned int i, j = 0, min = 0;

	if (array == NULL || size == 0)
		return;

	for (i = 0; i < size - 1; i++)
	{
		min = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[min])
				min = j;
		}
		if (min != i)
		{
			aux = array[i];
			array[i] = array[min];
			array[min] = aux;
			print_array(array, size);
		}
	}
}
