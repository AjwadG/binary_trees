#include "binary_trees.h"

/**
 * calc_tree_size - measures the size of a binary tree
 *
 * @tree: pointer to the tree
 *
 * Return: the size of the tree
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
 * is_complete - checks if a binary tree is complete
 *
 * @tree: pointer to the tree
 * @index: current node
 * @size: size of the tree
 *
 * Return: 1 if complete 0 other wise
 */
int is_complete(const binary_tree_t *tree, int index, int size)
{
	int left = 1, right = 1;

	if (!tree)
		return (0);

	if (index >= size)
		return (0);

	if (tree->left)
		left = is_complete(tree->left, index * 2 + 1, size);
	if (tree->right)
		right = is_complete(tree->right, index * 2 + 2, size);

	return (left * right);
}

/**
 * binary_tree_is_complete - checks if a binary tree is complete
 *
 * @tree: pointer to the tree
 *
 * Return: 1 if its complete or 0 if tree is NULL or not full
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	int size;

	if (!tree)
		return (0);

	size = calc_tree_size(tree) + 1;

	return (is_complete(tree, 0, size));
}
