#include "binary_trees.h"

/**
 * binary_tree_postorder - uses func on each node
 *
 * @tree: pointer to the tree to free
 * @func: pointer to the function to use
 */
void binary_tree_postorder(const binary_tree_t *tree, void (*func)(int))
{
	if (!tree || !func)
		return;
	if (tree->left)
		binary_tree_postorder(tree->left, func);
	if (tree->right)
		binary_tree_postorder(tree->right, func);
	func(tree->n);
}
