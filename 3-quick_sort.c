#include "sort.h"

/**
 * lomuto_partition - Lomuto partition scheme for QuickSort.
 * @array: Array to be partitioned.
 * @low: Index of the low boundary of the partition.
 * @high: Index of the high boundary of the partition.
 * @size: Size of the array.
 *
 * Return: Index of the pivot.
 */
int lomuto_partition(int *array, int low, int high, size_t size)
{
int pivot = array[high];
int i = low - 1;

for (int j = low; j <= high - 1; j++)
{
if (array[j] < pivot)
{
i++;
if (i != j)
{
array[i] ^= array[j];
array[j] ^= array[i];
array[i] ^= array[j];
print_array(array, size);
}
}
}

if (i + 1 != high)
{
array[i + 1] ^= array[high];
array[high] ^= array[i + 1];
array[i + 1] ^= array[high];
print_array(array, size);
}

return (i + 1);
}

/**
 * quick_sort_recursive - Recursive function to perform quicksort.
 * @array: Array to be sorted.
 * @low: Index of the low boundary of the partition.
 * @high: Index of the high boundary of the partition.
 * @size: Size of the array.
 */
void quick_sort_recursive(int *array, int low, int high, size_t size)
{
if (low < high)
{
int pivot_index = lomuto_partition(array, low, high, size);

quick_sort_recursive(array, low, pivot_index - 1, size);
quick_sort_recursive(array, pivot_index + 1, high, size);
}
}

/**
 * quick_sort - Sorts an array of integers in ascending order using QuickSort.
 * @array: Array to be sorted.
 * @size: Size of the array.
 */
void quick_sort(int *array, size_t size)
{
if (array && size > 1)
quick_sort_recursive(array, 0, size - 1, size);
}
