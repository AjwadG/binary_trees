#include "binary_trees.h"

/**
 * binary_tree_nodes - counts the nodes in a binary tree
 *
 * @tree: pointer to the tree
 *
 * Return: number of nodes or 0 if tree is null
 */
size_t binary_tree_nodes(const binary_tree_t *tree)
{
	size_t nodes = 0;

	if (!tree)
		return (0);

	if (tree->left)
		nodes += binary_tree_nodes(tree->left);

	if (tree->right)
		nodes += binary_tree_nodes(tree->right);

	if (tree->left || tree->right)
		nodes++;

	return (nodes);
}
