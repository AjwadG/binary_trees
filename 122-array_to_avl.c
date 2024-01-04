#include "binary_trees.h"


/**
 * array_to_avl - builds a AVL from an array
 *
 * @array: array top convert to avl
 * @size: the size of the array
 *
 * Return: pointer to the avl or NULL
 */
avl_t *array_to_avl(int *array, size_t size)
{
	avl_t *root = NULL;
	size_t i;

	if (!array)
		return (NULL);

	for (i = 0; i < size; i++)
	{
		avl_insert(&root, array[i]);
	}

	return (root);
}
