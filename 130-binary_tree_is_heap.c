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
	int comp;
	int heap;

	if (!tree)
		return (0);

	comp = is_complete(tree);
	if (comp != 1 && comp != 2)
		return (0);

	heap = is_heap(tree);
	return (heap);

}
