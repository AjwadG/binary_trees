#include "binary_trees.h"


/**
 * array_to_bst - builds a Binary Search Tree from an array
 *
 * @array: array top convert to BST
 * @size: the size of the array
 *
 * Return: pointer to the BST or NULL
 */
bst_t *array_to_bst(int *array, size_t size)
{
	bst_t *root = NULL;
	size_t i;

	if (!array)
		return (NULL);

	for (i = 0; i < size; i++)
	{
		bst_insert(&root, array[i]);
	}

	return (root);
}
