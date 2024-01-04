#include "binary_trees.h"


/**
 * avl_search - searches for a value in a AVL Tree
 *
 * @tree: tree pointer
 * @value: number to comapre to
 *
 * Return: node if found ro NULL
 */
avl_t *avl_search(const avl_t *tree, int value)
{
	if (!tree || tree->n == value)
		return ((avl_t *) tree);

	if (value > tree->n)
	{
		if (tree->right)
			return (avl_search(tree->right, value));
		else
			return (NULL);
	}
	else
	{
		if (tree->left)
			return (avl_search(tree->left, value));
		else
			return (NULL);
	}
}

/**
 * find_replace - gets first in-order successor
 *
 * @tree: tree pointer
 * @value: number to comapre to
 * @left: side of search
 *
 * Return: pointer to the node
 */
bst_t *find_replace(const avl_t *tree, int value, int left)
{
	if ((left && !tree->right) || (!left && !tree->left))
		return ((avl_t *) tree);

	if (left)
		return (find_replace(tree->right, value, left));
	return (find_replace(tree->left, value, left));
}

/**
 * swap - swaps all values of nodes
 *
 * @old: old node
 * @new: new node
 */
void swap(avl_t *old, avl_t *new)
{
	if (new->parent && new->parent->right == new)
		new->parent->right = NULL;
	if (new->parent && new->parent->left == new)
		new->parent->left = NULL;
	new->parent = old->parent;
	if (new->n > old->n || new->left == NULL)
		new->left = old->left;
	if (new->n < old->n || new->right == NULL)
		new->right = old->right;
	if (new->right)
		new->right->parent = new;
	if (new->left)
		new->left->parent = new;
	if (new->parent && new->parent->left == old)
		new->parent->left = new;
	else if (new->parent && new->parent->right == old)
		new->parent->right = new;

}


/**
 * fix_avl - dose the rotaions
 *
 * @root: root of the tree
 *
 * Return: the new root
 */
avl_t *fix_avl(avl_t **root)
{
	int bf, rbf, lbf;

	if (!*root)
		return (NULL);

	if ((*root)->right)
		(*root)->right = fix_avl(&(*root)->right);
	if ((*root)->left)
		(*root)->left = fix_avl(&(*root)->left);

	bf = binary_tree_balance(*root);
	rbf = binary_tree_balance((*root)->right);
	lbf = binary_tree_balance((*root)->left);

	if (bf > 1 && lbf >= 0)
		*root = binary_tree_rotate_right(*root);
	else if (bf < -1 && rbf <= 0)
		*root = binary_tree_rotate_left(*root);
	else if (bf < -1 && rbf == 1)
	{
		(*root)->right = binary_tree_rotate_right((*root)->right);
		*root = binary_tree_rotate_left(*root);
	}
	else if (bf > 1 && lbf == -1)
	{
		(*root)->left = binary_tree_rotate_left((*root)->left);
		*root = binary_tree_rotate_right(*root);
	}

	return (*root);
}


/**
 * avl_remove - removes a value from avl
 *
 * @root: tree pointer
 * @value: number to comapre to
 *
 * Return: root of tree or null
 */
avl_t *avl_remove(avl_t *root, int value)
{
	avl_t *old, *new = NULL;

	if (!root)
		return (NULL);
	old = avl_search(root, value);
	if (!old)
		return (NULL);
	if (old->right)
		new = find_replace(old->right, value, 0);
	else if (old->left)
		new = find_replace(old->left, value, 1);
	else
	{
		if (old->parent && old->parent->right == old)
			old->parent->right = NULL;
		else if (old->parent && old->parent->left == old)
			old->parent->left = NULL;
		free(old);
		return (fix_avl(&root));
	}
	swap(old, new);
	if (old == root)
		root = new;
	free(old);

	return (fix_avl(&root));
}
