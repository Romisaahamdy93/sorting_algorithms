#include "sort.h"

/**
 * bubble_sort - Sorts an array of integers in ascending order
 * @array: Array to be sorted
 * @size: Size of the array
 */
void bubble_sort(int *array, size_t size)
{
int i, temp = 0, j = 0, swapped = 1;

if (!array || size < 2)
return;
j = size - 1;
for (i = 0; i < j; ++i)
{
if (array[i] > array[i + 1])
{
temp = array[i];
array[i] = array[i + 1];
array[i + 1] = temp;
swapped = 1;
print_array(array, size);
}
if (swapped == 1 && i == j - 1)
i = -1, swapped = 0, --j;
}
}
