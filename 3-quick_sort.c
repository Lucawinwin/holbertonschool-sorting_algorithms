#include "sort.h"

/**
 *swap- swaps two integers in an array
 *@a: pointer to the first integer
 *@b: pointer to the second integer
 */
void swap(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * lomuto_partition - lomuto partition scheme
 * @array: array to be sorted
 * @low: starting index of the partition
 * @high: ending index of the partition
 * @size: size of the array
 * Return: index of the pivot element after partitioning
 */

int lomuto_partition(int *array, int low, int high, size_t size)
{
	int pivot;
	int i;
	int j;

	pivot = array[high];
	i = low - 1;

	for (j = low; j <= high - 1; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			if (i != j)
			{
				swap(&array[i], &array[j]);
				print_array(array, size);
			}
		}
	}
	if (array[i + 1] != array[high])
	{
		swap(&array[i + 1], &array[high]);
		print_array(array, size);
	}
	return (i + 1);
}


/**
 * quicksort_recursive - sorts the array using quicksort
 * @array: pointer to the array to be sorted
 * @low: starting index of the array
 * @high: ending index of the array
 * @size: size of the array
 */

void quicksort_recursive(int *array, int low, int high, size_t size)
{
	if (low < high)
	{
		int pivot;

		pivot = lomuto_partition(array, low, high, size);
		quicksort_recursive(array, low, pivot - 1, size);
		quicksort_recursive(array, pivot + 1, high, size);
	}
}

/**
 * quick_sort - calls quicksort to sort the array
 * @array: pointer to the array to be sorted
 * @size: size of the array
 */

void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	quicksort_recursive(array, 0, size - 1, size);
}
