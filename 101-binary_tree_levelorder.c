#include "binary_trees.h"

/**
 * level - crate array according to level
 *
 * @tree: pointer to tree node
 * @y: y of set
 * @list: list to put the numbers in
 */
void level(const binary_tree_t *tree, int y, int **list)
{
	list[y][0]++;
	list[y][list[y][0]] = tree->n;

	if (tree->left)
		level(tree->left, y + 1, list);
	if (tree->right)
		level(tree->right, y + 1, list);
}

/**
 * binary_tree_levelorder - func acording to level-order traversal
 *
 * @tree: pointer to the tree
 * @func: pointer to the function to be called on each node
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	int **order, i, j, h = (int) binary_tree_height(tree) + 1;

	if (!tree || !func)
		return;

	order = malloc(sizeof(int *) * h);
	if (!order)
		return;

	for (i = 0, j = 1; i < h; i++, j *= 2)
	{
		order[i] = malloc(sizeof(int) * (j + 1));
		order[i][0] = 0;
	}

	level(tree, 0, order);

	for (i = 0; i < h; i++)
	{
		for (j = 1; j <= order[i][0]; j++)
			func(order[i][j]);
		free(order[i]);
	}
	free(order);
}



/**
 * binary_tree_height - measures the height of a binary tree
 *
 * @tree: pointer to the tree
 *
 * Return: 0 if tree is null or the height of the node
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t left = 0, right = 0;

	if (!tree)
		return (0);

	if (tree->left)
		left += 1 + binary_tree_height(tree->left);

	if (tree->right)
		right += 1 + binary_tree_height(tree->right);

	return (left > right ? left : right);
}
