#include "binary_trees.h"


/**
 * bst_search - searches for a value in a Binary Search Tree
 *
 * @tree: tree pointer
 * @value: number to comapre to
 *
 * Return: 1 for bst 0 other wise
 */
bst_t *bst_search(const bst_t *tree, int value)
{
	if (!tree || tree->n == value)
		return ((bst_t *) tree);

	if (value > tree->n)
	{
		if (tree->right)
			return (bst_search(tree->right, value));
		else
			return (NULL);
	}
	else
	{
		if (tree->left)
			return (bst_search(tree->left, value));
		else
			return (NULL);
	}
}
