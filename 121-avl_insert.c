#include "binary_trees.h"


/**
 * find_parent - gets the node to be instered under
 *
 * @tree: tree pointer
 * @value: number to comapre to
 *
 * Return: 1 for bst 0 other wise
 */
bst_t *find_parent(bst_t *tree, int value)
{
	if (!tree || tree->n == value)
		return (NULL);

	if (value > tree->n)
	{
		if (tree->right)
			return (find_parent(tree->right, value));
		else
			return (tree);
	}
	else
	{
		if (tree->left)
			return (find_parent(tree->left, value));
		else
			return (tree);
	}
}


/**
 * bst_insert -  inserts a value in a BST
 *
 * @tree: double pointer to the tree
 * @value: value of the node to be added
 *
 * Return: pointer to the node or NULL
 */
bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *new;

	if (!*tree)
	{
		*tree = binary_tree_node(NULL, value);
		new = *tree;
		return (*tree);
	}

	new = find_parent(*tree, value);
	if (!new)
		return (new);

	new = binary_tree_node(new, value);
	if (value < new->parent->n)
		new->parent->left = new;
	else
		new->parent->right = new;
	return (new);
}

/**
 * avl_insert -  inserts a value in a AVL
 *
 * @tree: double pointer to the tree
 * @value: value of the node to be added
 *
 * Return: pointer to the node or NULL
 */
avl_t *avl_insert(avl_t **tree, int value)
{
	avl_t *new, *tmp;
	int bf, lbf, rbf;

	if (!tree)
		return (NULL);

	new = bst_insert(tree, value);
	for (tmp = new->parent; tmp; tmp = tmp->parent)
	{
		bf = binary_tree_balance(tmp);
		if (tmp->right)
			rbf = binary_tree_balance(tmp->right);
		if (tmp->left)
			lbf = binary_tree_balance(tmp->left);

		if (bf > 1 && lbf == 1)
			tmp = binary_tree_rotate_right(tmp);
		else if (bf < -1 && rbf == -1)
			tmp = binary_tree_rotate_left(tmp);
		else if (bf < -1 && rbf == 1)
		{
			tmp->right = binary_tree_rotate_right(tmp->right);
			tmp = binary_tree_rotate_left(tmp);
		}
		else if (bf > 1 && lbf == -1)
		{
			tmp->left = binary_tree_rotate_left(tmp->left);
			tmp = binary_tree_rotate_right(tmp);
		}
		else
			continue;
		if (*tree == tmp->left || *tree == tmp->right)
			*tree = tmp;
	}
	return (new);
}
