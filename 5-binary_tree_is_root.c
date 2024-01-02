#include "binary_trees.h"

/**
 * binary_tree_is_root -  checks if a node is root
 *
 * @node: pointer to the node
 *
 * Return: 1 if node is the root, otherwise 0 or node is NULL
 */
int binary_tree_is_root(const binary_tree_t *node)
{
	if (!node || node->parent)
		return (0);
	return (1);
}
