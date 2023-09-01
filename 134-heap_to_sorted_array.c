}

/**
 * heap_to_sorted_array - Creates a sorted array from a max heap
 * @heap: Pointer to heap's node
 * @size: Pointer to arrays size
 *
 * Return: Pointer to array of integeres
 */
int *heap_to_sorted_array(heap_t *heap, size_t *size)
{
	int i, nodes, *arr = NULL;

	*size = 0;
	if (!heap)
		return (NULL);

	nodes = _count_nodes(heap);
	arr = malloc(sizeof(*arr) * nodes);
	if (!arr)
		return (NULL);

	*size = nodes;
	for (i = 0; i < nodes; i++)
		arr[i] = heap_extract(&heap);

	return (arr);
}

#include "binary_trees.h"

/**
 * _count_nodes - Counts the number of nodes inside a tree
 * @root: Pointer to tree's root node
 *
 * Return: Number of tree nodes
 */
int _count_nodes(binary_tree_t *root)
{
	if (!root)
		return (0);

	return (1 + _count_nodes(root->left) +
		    _count_nodes(root->right));
}