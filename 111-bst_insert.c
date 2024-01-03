#include "binary_trees.h"


/**
 * find_parent - gets the node to be instered under
 *
 * @tree: tree pointer
 * @value: number to comapre to
 *
 * Return: 1 for bst 0 other wise
 */
bst_t *find_parent(bst_t *tree, int value)
{
	if (!tree || tree->n == value)
		return (NULL);

	if (value > tree->n)
	{
		if (tree->right)
			return (find_parent(tree->right, value));
		else
			return (tree);
	}
	else
	{
		if (tree->left)
			return (find_parent(tree->left, value));
		else
			return (tree);
	}
}


/**
 * bst_insert -  inserts a value in a BST
 *
 * @tree: double pointer to the tree
 * @value: value of the node to be added
 *
 * Return: pointer to the node or NULL
 */
bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *new;

	if (!*tree)
	{
		*tree = binary_tree_node(NULL, value);
		new = *tree;
		return (*tree);
	}

	new = find_parent(*tree, value);
	if (!new)
		return (new);

	new = binary_tree_node(new, value);
	if (value < new->parent->n)
		new->parent->left = new;
	else
		new->parent->right = new;
	return (new);
}
