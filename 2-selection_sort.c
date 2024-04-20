#include "sort.h"
/**
 * print_arry - prints array
 * @array: array to sort
 * @size: size of array
 */
void print_arry(const int *array, size_t size)
{
	int i = 0;

	if (!array)
		return;
	while (i < size)
	{
		printf("%d", array[i]);
		if (i < size - 1)
			printf(", ");
		i++;
	}
	printf("\n");
}

/**
 * selection_sort - print doubly linked list
 * @array: array to sort
 * @size: size of array
 */
void selection_sort(int *array, size_t size)
{
	int smallest, i, idx = 0, temp, smallest_idx, swap_me = 0;

	if (!array || size == 0)
		return;

	smallest = array[0];
	while (idx < size)
	{
		i = idx;
		while (i < size)
		{
			if (array[i] < smallest)
			{
				smallest = array[i];
				smallest_idx = i;
			}
			i++;
		}

		if (array[idx] != smallest)
		{
			temp = array[idx];
			array[idx] = array[smallest_idx];
			array[smallest_idx] = temp;
			smallest = array[idx +  1];
			print_arry(array, size);
		}
		idx++;
	}
}
