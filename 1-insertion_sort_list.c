#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list of integers
 *                      in ascending order using the Insertion sort algorithm.
 * @list: Pointer to the head of the doubly linked list.
 */

void insertion_sort_list(listint_t **list)
{
listint_t *current, *prev_node, *next_node;

if (!list || !(*list) || !((*list)->next))
return;

current = (*list)->next;

while (current)
{
next_node = current->next;

while (current->prev && current->n < current->prev->n)
{
prev_node = current->prev;
prev_node->next = current->next;

if (current->next)
current->next->prev = prev_node;

current->next = prev_node;
current->prev = prev_node->prev;

if (prev_node->prev)
prev_node->prev->next = current;
else
*list = current;

prev_node->prev = current;
print_list(*list);
}

current = next_node;
}
}
