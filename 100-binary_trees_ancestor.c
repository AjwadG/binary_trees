#include "binary_trees.h"

/**
 * binary_trees_ancestor - lowest common ancestor of two nodes
 *
 * @first: pointer to the first node
 * @second: pointer to the second node
 *
 * Return: pointer to the common ancestor or NULL
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
		const binary_tree_t *second)
{
	const binary_tree_t *holder = second;

	while (first)
	{
		for (second = holder; second; second = second->parent)
		{
			if (first == second)
				return ((binary_tree_t *) first);
		}
		first = first->parent;
	}

	return (NULL);
}
