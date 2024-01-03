#include "binary_trees.h"


/**
 * binary_tree_rotate_right - performs a right-rotation on a binary tree
 *
 * @tree: pointer to the tree
 *
 * Return: a pointer to the new root node of the tree once rotated
 */
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	binary_tree_t *rotate;

	if (!tree || !tree->left)
		return (NULL);

	rotate = tree->left;
	tree->left = rotate->right;
	rotate->right = tree;
	if (tree->left)
		tree->left->parent = tree;
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
