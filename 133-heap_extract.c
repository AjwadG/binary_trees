#include "binary_trees.h"


/**
 * find_node - gets the node to be swaped
 *
 * @tree: tree pointer
 * @last: pointer to store the last node
 * @lastd: dpeth of sotred value
 * @depth: current depth
 */
void find_node(heap_t *tree, heap_t **last, int *lastd, int depth)
{
	if (!tree)
		return;
	if (*lastd <= depth)
		*last = tree, *lastd = depth;

	if (tree->left)
		find_node(tree->left, last, lastd, depth + 1);

	if (tree->right)
		find_node(tree->right, last, lastd, depth + 1);
}


/**
 * heap_fix_rev - dose the swaps
 *
 * @root: root of the tree
 *
 */
void heap_fix_rev(heap_t *root)
{
	heap_t *node = root;
	int tmp;

	if (!root || (((root->left && root->n > root->left->n) || !root->left) &&
				((root->right && root->n > root->right->n) || !root->right)))
		return;


	if (node->left && node->left->n > node->n)
		node = node->left;
	if (root->right && root->right->n > node->n)
		node = root->right;

	tmp = node->n;
	node->n = root->n;
	root->n = tmp;

	heap_fix_rev(node);
}

/**
 * heap_extract - extracts root from heap tree
 *
 * @root: double pointer to the tree
 *
 * Return: value of root node
 */
int heap_extract(heap_t **root)
{
	heap_t *last = NULL;
	int extracted, depth = 0;

	if (!root || !*root)
		return (0);

	extracted = (*root)->n;

	find_node(*root, &last, &depth, 0);
	if (!last)
		return (0);
	(*root)->n = last->n;
	if (last == *root)
	{
		*root = NULL;
	}
	else
	{
		if (last->parent->left == last)
			last->parent->left = NULL;
		else
			last->parent->right = NULL;
		heap_fix_rev(*root);
	}

	free(last);
	return (extracted);


}
