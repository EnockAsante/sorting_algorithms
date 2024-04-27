#include "sort.h"

/**
 * _swap - swaps
 * @idx_a: ref idx_a
 * @idx_b: ref idx_b
 */
void _swap(int *array, size_t idx_a, size_t idx_b)
{
	int temp;

	temp = array[idx_a];
	array[idx_a] = array[idx_b];
	array[idx_b] = temp;
}

/**
 * checker - check if array is sorted
 * @array: the array
 * @size: size of array
 * Return: 0 if check pased and 0 o/w
 */

int checker(int *array, size_t size)
{
	size_t i, j;

	if (!array)
		return (0);

	for (i = 0; i < size; i++)
	{
		for (j = i + 1; j < size; j++)
		{
			if (array[i] > array[j])
				return (0);
		}
	}
	return (1);
}

/**
 * piv_idx - check pivot index
 * @array: the array
 * @size: size of array
 * @value: number to determine it index
 * Return: the index
 */

size_t piv_idx(int *array, int value, size_t size)
{
	size_t i = 0;

	while (i < size)
	{
		if (array[i] == value)
			return (i);
		i++;
	}
	return (-1);
}

/**
 * quick_sort - sort array with quick_sort
 * @array: array to sort
 * @size: size of array
 */
void quick_sort(int *array, size_t size)
{
	int pivot, prev_pivot;
	size_t i = 0, pivot_ind = size - 1, u = 1;

	if (!array || !size)
		return;
	pivot = array[size - 1];

	while (1)
	{
		if ((array[i] > pivot && pivot_ind > i) || (array[i] < pivot && pivot_ind < i))
		{
			_swap(array, i, pivot_ind);
			print_array(array, size);
		}

		if (checker(array, size))
			break;

		else if (i == size - 1)
		{
			while (1)
			{
				prev_pivot = pivot;
				pivot = array[size - u];
				if (prev_pivot != pivot)
					break;
				u++;
			}
			i = 0;
		}
		pivot_ind = piv_idx(array, pivot, size);
		i++;
	}
}
