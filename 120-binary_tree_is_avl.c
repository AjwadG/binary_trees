#include "binary_trees.h"


/**
 * is_bst - all the work
 *
 * @tree: tree pointer
 * @max: pointer to max value
 * @min: pointer to min value
 *
 * Return: 1 for bst 0 other wise
 */
int is_bst(const binary_tree_t *tree, int *min, int *max)
{
	if (!tree)
		return (1);

	if ((max && tree->n >= *max) || (min && tree->n <= *min))
		return (0);

	return (is_bst(tree->left, min, (int *) &tree->n) &&
			is_bst(tree->right, (int *) &tree->n, max));
}


/**
 * tree_height - measures the height of a binary tree
 *
 * @tree: pointer to the tree
 *
 * Return: the height of the node or -1 if tree is NULL
 */
int tree_height(const binary_tree_t *tree)
{
	int left = 0, right = 0;

	if (!tree)
		return (-1);

	if (tree->left)
		left += 1 + tree_height(tree->left);

	if (tree->right)
		right += 1 + tree_height(tree->right);

	return (left > right ? left : right);
}


/**
 * binary_tree_balance - measures the balance fact of a binary tree
 *
 * @tree: pointer to the tree
 *
 * Return: the balance factor or 0 if tree is NULL
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (tree_height(tree->left) - tree_height(tree->right));
}


/**
 * is_avl - all the work
 *
 * @tree: tree pointer
 *
 * Return: 1 if not dif
 */
int is_avl(const binary_tree_t *tree)
{
	int dif;

	if (!tree)
		return (1);

	dif = binary_tree_balance(tree);
	if (dif >= -1 && dif <= 1)
		dif = 1;
	else
		dif = 0;

	if (tree->right)
		dif *= is_avl(tree->right);
	if (tree->left)
		dif *= is_avl(tree->left);

	return (dif);
}


/**
 * binary_tree_is_avl -  checks if a binary tree is a valid AVL
 *
 * @tree: pointer to the tree
 * Return: 1 if its AVL or 0 if tree is NULL or not AVL
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	int bst;
	int avl;

	if (!tree)
		return (0);

	bst = is_bst(tree, NULL, NULL);
	avl = is_avl(tree);
	return (bst * avl);

}
