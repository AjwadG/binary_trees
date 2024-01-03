#include "binary_trees.h"


/**
 * binary_tree_rotate_left - performs a left-rotation on a binary tree
 *
 * @tree: pointer to the tree
 *
 * Return: a pointer to the new root node of the tree once rotated
 */
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *rotate;

	if (!tree || !tree->right)
		return (NULL);

	rotate = tree->right;
	tree->right = rotate->left;
	rotate->left = tree;
	if (tree->right)
		tree->right->parent = tree;
	rotate->parent = tree->parent;
	tree->parent = rotate;

	if (rotate->parent)
	{
		if (rotate->parent->left == tree)
			rotate->parent->left = rotate;
		else
			rotate->parent->right = rotate;
	}
	return (rotate);
}
