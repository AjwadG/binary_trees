#include "binary_trees.h"


/**
 * is_bst - all the work
 *
 * @tree: tree pointer
 * @max: pointer to max value
 * @min: pointer to min value
 *
 * Return: 1 for bst 0 other wise
 */
int is_bst(const binary_tree_t *tree, int *min, int *max)
{
	if (!tree)
		return (1);

	if ((max && tree->n >= *max) || (min && tree->n <= *min))
		return (0);

	return (is_bst(tree->left, min, (int *) &tree->n) &&
			is_bst(tree->right, (int *) &tree->n, max));
}


/**
 * binary_tree_is_bst -  checks if a binary tree is a valid BST
 *
 * @tree: pointer to the tree
 * Return: 1 if its BST or 0 if tree is NULL or not BST
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (is_bst(tree, NULL, NULL));
}
