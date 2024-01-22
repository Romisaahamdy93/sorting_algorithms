#include <stdio.h>
#include "sort.h"

/**
 * lomuto_partition - Lomuto partition scheme
 * @array: Array to be partitioned
 * @low: Starting index of the partition
 * @high: Ending index of the partition
 * @size: Size of the array
 *
 * Return: Index of the pivot after partitioning
 */
size_t lomuto_partition(int *array, size_t low, size_t high, size_t size)
{
int pivot = array[high];
size_t i = low - 1, j;

for (j = low; j < high; j++)
{
if (array[j] <= pivot)
{
i++;
if (i != j)
{

array[i] = array[i] ^ array[j];
array[j] = array[i] ^ array[j];
array[i] = array[i] ^ array[j];

print_array(array, size);
}
}
}

if (i + 1 != high)
{
array[i + 1] = array[i + 1] ^ array[high];
array[high] = array[i + 1] ^ array[high];
array[i + 1] = array[i + 1] ^ array[high];

print_array(array, size);
}

return (i + 1);
}

/**
 * quicksort - Recursive function to perform quicksort
 * @array: Array to be sorted
 * @low: Starting index of the partition
 * @high: Ending index of the partition
 * @size: Size of the array
 */
void quicksort(int *array, size_t low, size_t high, size_t size)
{
if (low < high)
{
size_t pivot = lomuto_partition(array, low, high, size);

if (pivot != 0)
quicksort(array, low, pivot - 1, size);

quicksort(array, pivot + 1, high, size);
}
}

/**
 * quick_sort - Sorts an array of integers using the Quick sort algorithm
 * @array: Array to be sorted
 * @size: Size of the array
 */
void quick_sort(int *array, size_t size)
{
if (array == NULL || size < 2)
return;

quicksort(array, 0, size - 1, size);
}
