#include "binary_trees.h"

/**
 * binary_tree_insert_left - crates a new node
 *
 * @parent: pointer to the parent node of the node to create
 * @value: the value to put in the new node
 *
 * Description: inserts a node as the left-child of another node
 *
 * Return: a pointer to the new node, or NULL on failure
 */
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *new;

	if (!parent)
		return (NULL);

	new = malloc(sizeof(binary_tree_t));
	if (!new)
		return (NULL);

	new->n = value;
	new->parent = parent;
	new->left = parent->left;
	new->right = NULL;
	parent->left = new;
	if (new->left)
		new->left->parent = new;

	return (new);

}
