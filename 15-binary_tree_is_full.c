#include "binary_trees.h"


/**
 * binary_tree_is_full - checks if a binary tree is full
 *
 * @tree: pointer to the tree
 *
 * Return: 1 if its full or 0 if tree is NULL or not full
 */
int binary_tree_is_full(const binary_tree_t *tree)
{
	int full = 1;

	if (!tree)
		return (0);

	if (tree->left)
		full *= binary_tree_is_full(tree->left);

	if (tree->right)
		full *= binary_tree_is_full(tree->right);

	if ((tree->right && tree->left) || (!tree->right && !tree->left))
		return (full);
	else
		return (0);

}
