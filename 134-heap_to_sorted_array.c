#include "binary_trees.h"

/**
 * calc_size - calcs the size of the heap
 *
 * @tree: pointer to head of the heap
 * @size: pointer to store in the size
 *
 */
void calc_size(heap_t *tree, size_t *size)
{
	if (!tree)
		return;

	*size = *size + 1;

	if (tree->left)
		calc_size(tree->left, size);

	if (tree->right)
		calc_size(tree->right, size);
}
/**
 * heap_to_sorted_array - converts a Binary Max Heap to a sorted array
 *
 * @heap: heap tree head
 * @size: size of the array
 *
 * Return: pointer to the array or NULL
 */
int *heap_to_sorted_array(heap_t *heap, size_t *size)
{
	size_t i = *size = 0;
	int *array;

	if (!heap)
		return (NULL);

	calc_size(heap, size);
	array = malloc(sizeof(int) * (*size));
	if (!array)
		return (NULL);

	for (; i < *size; i++)
	{
		array[i] = heap_extract(&heap);
	}

	return (array);
}
