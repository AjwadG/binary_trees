#include "binary_trees.h"


/**
 * array_to_heap - builds a heap from an array
 *
 * @array: array top convert to heap
 * @size: the size of the array
 *
 * Return: pointer to the heap or NULL
 */
heap_t *array_to_heap(int *array, size_t size)
{
	heap_t *root = NULL;
	size_t i;

	if (!array)
		return (NULL);

	for (i = 0; i < size; i++)
	{
		heap_insert(&root, array[i]);
	}

	return (root);
}
