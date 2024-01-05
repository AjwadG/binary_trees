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
 * is_heap - checks if a binary tree is heap
 *
 * @tree: pointer to the tree
 * Return: 1 if is heap or 0
 */
int is_heap(const binary_tree_t *tree)
{
	int bigger = 1;

	if (!tree)
		return (bigger);

	bigger *= (!tree->left || tree->left->n < tree->n);
	bigger *= (!tree->right || tree->right->n < tree->n);

	if (!bigger)
		return (0);

	if (tree->left)
		bigger *= is_heap(tree->left);

	if (tree->right)
		bigger *= is_heap(tree->right);

	return (bigger);
}

/**
 * binary_tree_is_heap - checks if a binary tree is a valid heap tree
 *
 * @tree: pointer to the tree
 * Return: 1 if its heap or 0 if tree is NULL or not heap
 */
int binary_tree_is_heap(const binary_tree_t *tree)
{
	int size;

	if (!tree)
		return (0);

	size = calc_tree_size(tree) + 1;

	if (!is_complete(tree, 0, size))
		return (0);

	return (is_heap(tree));
}
