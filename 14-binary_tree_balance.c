#include "binary_trees.h"


/**
 * tree_height - measures the height of a binary tree
 *
 * @tree: pointer to the tree
 *
 * Return: the height of the node or -1 if tree is NULL
 */
int tree_height(const binary_tree_t *tree)
{
	int left = 0, right = 0;

	if (!tree)
		return (-1);

	if (tree->left)
		left += 1 + tree_height(tree->left);

	if (tree->right)
		right += 1 + tree_height(tree->right);

	return (left > right ? left : right);
}


/**
 * binary_tree_balance - measures the balance fact of a binary tree
 *
 * @tree: pointer to the tree
 *
 * Return: the balance factor or 0 if tree is NULL
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (tree_height(tree->left) - tree_height(tree->right));
}
