#include "binary_trees.h"

/**
 * _count_hpnodes - Counts the number of nodes inside a tree
 * @root: Pointer to tree's root node
 *
 * Return: Number of tree nodes
 */
int _count_hpnodes(binary_tree_t *root)
{
	if (!root)
		return (0);

	return (1 + _count_hpnodes(root->left) +
		    _count_hpnodes(root->right));
}


/**
 * corr_pos - Puts a node value in a correct position in the heap
 * @parent: Pointer to heap's node
 */
void corr_pos(heap_t *parent)
{
	int arbtry;
	heap_t *big_child = NULL;

	if (!parent)
		return;

	while (parent && parent->left)
	{
		big_child = parent->left;

		if (parent->right && parent->right->n > parent->left->n)
			big_child = parent->right;

		if (big_child->n > parent->n)
		{
			arbtry = parent->n;
			parent->n = big_child->n;
			big_child->n = arbtry;
		}

		parent = big_child;
	}
}


/**
 * find_parent - Finds the parent node for a ceratin node
 * @root: Pointer to heap's node
 * @index: Index of the current node
 * @pind: Index been searched
 *
 * Return: Pointer to heap's node
 */
heap_t *find_parent(heap_t *root, int index, int pind)
{
	heap_t *left = NULL, *right = NULL;

	if (!root || index > pind)
		return (NULL);

	if (index == pind)
		return (root);

	left = find_parent(root->left, index * 2 + 1, pind);
	if (left)
		return (left);

	right = find_parent(root->right, index * 2 + 2, pind);
	if (right)
		return (right);

	return (NULL);
}


/**
 * rem_last_nde - Removes the last node of a heap
 * @root: Doublepointer to heap's root node
 * @parent: Pointer to parent node from which to remove the last node
 */
void rem_last_nde(heap_t **root, heap_t *parent)
{
	if (parent == *root && !parent->left)
	{
		free(*root);
		*root = NULL;

		return;
	}

	if (parent->right)
	{
		(*root)->n = parent->right->n;
		free(parent->right);
		parent->right = NULL;
	}
	else if (parent->left)
	{
		(*root)->n = parent->left->n;
		free(parent->left);
		parent->left = NULL;
	}

	corr_pos(*root);
}


/**
 * heap_extract - Extracts the max value of a heap
 * @root: Double pointer to heap's root node
 *
 * Return: Heap's max value
 */
int heap_extract(heap_t **root)
{
	int ndes, pind = 0, big_val = 0;
	heap_t *parent;

	if (!root || !(*root))
		return (0);

	big_val = (*root)->n;
	ndes = _count_hpnodes(*root);

	pind = (ndes - 2) / 2;
	parent = find_parent(*root, 0, pind);

	rem_last_nde(root, parent);

	return (big_val);
}
