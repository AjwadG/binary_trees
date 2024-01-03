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
 * tree_balance - measures the balance fact of a binary tree
 *
 * @tree: pointer to the tree
 * @comp: is the tree left sided
 *
 * Return: the balance factor or 0 if tree is NULL
 */
int tree_balance(const binary_tree_t *tree, int comp)
{
	int balance;

	if (!tree)
		return (0);
	balance = tree_height(tree->left) - tree_height(tree->right);
	if (balance < 0)
		balance = -1;
	else
		balance = 1;

	if (comp < 0)
		return (comp);
	return (comp * balance);
}


/**
 * is_complete - checks if a binary tree is complete
 *
 * @tree: pointer to the tree
 * Return: 1, 2 if its complete or 0, > 2 if tree is NULL or not full
 */
int is_complete(const binary_tree_t *tree)
{
	int complete = 1;

	if (tree->left)
		complete *= is_complete(tree->left);

	if (tree->right)
		complete *= is_complete(tree->right);

	complete = tree_balance(tree, complete);

	if ((tree->right && tree->left) || (!tree->right && !tree->left))
		return (complete);
	else if (tree->left && !tree->left->left && !tree->left->right)
		return (2 * complete);
	else
		return (0);
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
	int stat;

	if (!tree)
		return (0);

	stat = is_complete(tree);

	if (stat == 1 || stat == 2)
		return (1);
	return (0);
}
