#include "sort.h"

/**
 * bubble_sort - Sorts an array of integers in ascending order
 * @array: Array to be sorted
 * @size: Size of the array
 */
void bubble_sort(int *array, size_t size)
{
size_t i, j;
int temp;
if (!array || !size)
return;
i = 0;
while (i < size)
{
for (j = 0; j < size - i; j++)
{
if (array[j] > array[j + 1])
{
temp = array[j];
array[j] = array[j + 1];
array[j + 1] = temp;
print_array(array, size);
}
}
i++;
}
}
