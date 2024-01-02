#include "binary_trees.h"

/**
 * calc_tree_size - measures the size of a binary tree
 *
 * @tree: pointer to the tree
 *
 * Return: the size of the tree - 1
 */
size_t calc_tree_size(const binary_tree_t *tree)
{
	size_t left = 0, right = 0;

	if (!tree)
		return (0);

	if (tree->left)
		left += 1 + calc_tree_size(tree->left);

	if (tree->right)
		right += 1 + calc_tree_size(tree->right);

	return (left + right);
}

/**
 * binary_tree_size - measures the size of a binary tree
 *
 * @tree: pointer to the tree
 *
 * Return: 0 if tree is null or the size of the tree
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (1 + calc_tree_size(tree));
}
