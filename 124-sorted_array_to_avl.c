#include "binary_trees.h"


/**
 * insert_avl - inserts node in avl
 *
 * @tree: root of the tree
 * @array: array of values
 * @start: start of the sub array
 * @end: end of the sub
 * @size: size of sub array
 * @l: left or riht side
 */
void insert_avl(avl_t *tree, int *array, int start, int end, int size, int l)
{
	int mid = size / 2 - (size % 2 == 0);

	if (!size)
		return;

	if (l)
	{
		tree->left = binary_tree_node(tree, array[start + mid]);
		insert_avl(tree->left, array, start, start + mid, mid, 1);
		insert_avl(tree->left, array, start + mid + 1, end, (size - 1 - mid), 0);
	}
	else
	{
		tree->right = binary_tree_node(tree, array[start + mid]);
		insert_avl(tree->right, array, start, start + mid, mid, 1);
		insert_avl(tree->right, array, start + mid + 1, end, (size - 1 - mid), 0);
	}
}

/**
 * sorted_array_to_avl - builds an AVL tree from an array
 *
 * @array: array to crate avl from
 * @size: size of the array
 *
 * Return: pointer to the AVL or NULL
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	avl_t *tree = NULL;
	int mid = size / 2 - (size % 2 == 0);

	if (!array || size == 0)
		return (NULL);

	tree = binary_tree_node(NULL, array[mid]);

	insert_avl(tree, array, 0, mid, mid, 1);
	insert_avl(tree, array, mid + 1, size, (size - 1 - mid), 0);

	return (tree);
}
