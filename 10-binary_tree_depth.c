#include "binary_trees.h"

/**
 * binary_tree_depth - measures the depth of a node
 *
 * @tree: pointer to the tree
 *
 * Return: 0 if tree is null or the depth of the node
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
	binary_tree_t *tmp;
	size_t depth = 0;

	if (!tree)
		return (0);

	for (tmp = tree->parent; tmp; depth++, tmp = tmp->parent)
		;

	return (depth);


}
