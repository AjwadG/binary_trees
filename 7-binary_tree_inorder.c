#include "binary_trees.h"

/**
 * binary_tree_inorder - uses func on each node
 *
 * @tree: pointer to the tree to free
 * @func: pointer to the function to use
 */
void binary_tree_inorder(const binary_tree_t *tree, void (*func)(int))
{
	if (!tree || !func)
		return;
	if (tree->left)
		binary_tree_inorder(tree->left, func);
	func(tree->n);
	if (tree->right)
		binary_tree_inorder(tree->right, func);
}
