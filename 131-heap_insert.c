#include "binary_trees.h"

/**
 * tree_balance - measures the balance of a binary tree
 *
 * @tree: pointer to the tree
 * @balance: mod of the function
 *
 * Return: BF
 */
int tree_balance(const heap_t *tree, int balance)
{
	int left = 0, right = 0;

	if (!tree)
		return (0);

	if (tree->left)
		left += 1 + tree_balance(tree->left, balance + 1);

	if (tree->right)
		right += 1 + tree_balance(tree->right, balance + 1);

	if (balance)
		return (left > right ? right : left);
	return (left - right);
}


/**
 * find_parent - gets the node to be instered under
 *
 * @tree: tree pointer
 *
 * Return: pointer to node or null
 */
heap_t *find_parent(heap_t *tree)
{
	int bf = tree_balance(tree, 0);

	if (!tree)
		return (NULL);

	if (!tree->right)
		return (tree);
	if (bf == 0)
		return (find_parent(tree->left));
	if (bf > 0 && tree_balance(tree->left, 0))
		return (find_parent(tree->left));
	return (find_parent(tree->right));
}


/**
 * heap_fix - dose the swaps
 *
 * @new: the new node of the tree
 *
 * Return: pointer to the new node
 */
heap_t *heap_fix(heap_t *new)
{
	heap_t *parent = new->parent;
	int tmp;

	if (!parent || new->n < parent->n)
		return (new);


	tmp = new->n;
	new->n = parent->n;
	parent->n = tmp;


	if (parent->parent)
		return (heap_fix(parent));
	return (parent);
}

/**
 * heap_insert -  inserts a value in a heap tree
 *
 * @root: double pointer to the tree
 * @value: value of the node to be added
 *
 * Return: pointer to the new node or NULL
 */
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *new, *parent;

	if (!root)
		return (NULL);
	if (!*root)
		return (*root = binary_tree_node(NULL, value));

	parent = find_parent(*root);
	if (!parent)
		return (NULL);

	new = binary_tree_node(parent, value);
	if (!new)
		return (NULL);

	if (parent->left)
		parent->right = new;
	else
		parent->left = new;

	new = heap_fix(new);

	return (new);
}
