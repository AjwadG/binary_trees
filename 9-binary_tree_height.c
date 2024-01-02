#include "binary_trees.h"

/**
 * binary_tree_height - measures the height of a binary tree
 *
 * @tree: pointer to the tree
 *
 * Return: 0 if tree is null or the height of the node
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t left = 0, right = 0;

	if (!tree)
		return (0);

	if (tree->left)
		left += 1 + binary_tree_height(tree->left);

	if (tree->right)
		right += 1 + binary_tree_height(tree->right);

	return (left > right ? left : right);
}
