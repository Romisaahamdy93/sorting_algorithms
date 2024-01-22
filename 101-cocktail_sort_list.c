#include <stdio.h>
#include "sort.h"

/**
 * swap_nodes - Swaps two nodes in a doubly linked list
 * @list: Pointer to the head of the list
 * @a: Pointer to the first node
 * @b: Pointer to the second node
 */
void swap_nodes(listint_t **list, listint_t *a, listint_t *b)
{
if (a->prev)
a->prev->next = b;
else
*list = b;

if (b->next)
b->next->prev = a;

a->next = b->next;
b->prev = a->prev;
a->prev = b;
b->next = a;
}

/**
 * cocktail_sort_list - Sorts a doubly linked list using the Cocktail Shaker sort
 * algorithm
 * @list: Pointer to the head of the list
 */
void cocktail_sort_list(listint_t **list)
{
int swapped;
listint_t *current, *start, *end;

if (list == NULL || *list == NULL)
return;

do {
swapped = 0;
current = *list;

while (current->next != end) {
if (current->n > current->next->n) {
swap_nodes(list, current, current->next);
print_list(*list);
swapped = 1;
}
else
current = current->next;
}

if (swapped == 0)
break;

swapped = 0;
end = current;

while (current->prev != start) {
if (current->n < current->prev->n) {
swap_nodes(list, current->prev, current);
print_list(*list);
swapped = 1;
}
else
current = current->prev;
}

start = current;
} while (swapped);
}
