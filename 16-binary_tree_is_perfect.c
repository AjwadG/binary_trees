#include "binary_trees.h"

/**
 * calc_side_size - measures the size of a binary tree side
 *
 * @tree: pointer to the tree
 *
 * Return: the size of the tree side
 */
int calc_side_size(const binary_tree_t *tree)
{
	int left = 0, right = 0;

	if (!tree)
		return (-1);

	if (tree->left)
		left += 1 + calc_side_size(tree->left);

	if (tree->right)
		right += 1 + calc_side_size(tree->right);

	return (left + right);
}

/**
 * binary_tree_is_perfect - checks if a binary tree is perfect
 *
 * @tree: pointer to the tree
 *
 * Return: 1 if its perfect, 0 if not or tree is null
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	int perfect;

	if (!tree)
		return (0);

	perfect = 1 + calc_side_size(tree->left);
	perfect -= 1 + calc_side_size(tree->right);

	return (perfect == 0 ? 1 : 0);
}
