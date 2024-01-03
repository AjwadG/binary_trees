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

/**
 * find_replace - gets first in-order successor
 *
 * @tree: tree pointer
 * @value: number to comapre to
 * @left: side of search
 *
 * Return: pointer to the node
 */
bst_t *find_replace(const bst_t *tree, int value, int left)
{
	if ((left && !tree->right) || (!left && !tree->left))
		return ((bst_t *) tree);

	if (left)
		return (find_replace(tree->right, value, left));
	return (find_replace(tree->left, value, left));
}

/**
 * swap - swaps all values of nodes
 *
 * @old: old node
 * @new: new node
 */
void swap(bst_t *old, bst_t *new)
{
	if (new->left || new->right)
	{
		new->parent = NULL;
		return;
	}
	if (new->parent && new->parent->right == new)
		new->parent->right = NULL;
	else if (new->parent && new->parent->left == new)
		new->parent->left = NULL;
	new->parent = old->parent, new->left = old->left, new->right = old->right;
	if (new->right)
		new->right->parent = new;
	if (new->left)
		new->left->parent = new;
	if (new->parent && new->parent->left == old)
		new->parent->left = new;
	else if (new->parent && new->parent->right == old)
		new->parent->right = new;

}
/**
 * bst_remove - removes for a value in a Binary Search Tree
 *
 * @root: tree pointer
 * @value: number to comapre to
 *
 * Return: root of tree or null
 */
bst_t *bst_remove(bst_t *root, int value)
{
	bst_t *old, *new = NULL;

	if (!root)
		return (NULL);
	old = bst_search(root, value);
	if (!old)
		return (NULL);
	if (old->right)
		new = find_replace(old->right, value, 0);
	else if (old->left)
		new = find_replace(old->left, value, 1);
	else
	{
		if (old->parent && old->parent->right == old)
			old->parent->right = NULL;
		else if (old->parent && old->parent->left == old)
			old->parent->left = NULL;
		free(old);
		return (root == old ? NULL : root);
	}
	swap(old, new);

	free(old);

	return (!new->parent ? new : root);
}
