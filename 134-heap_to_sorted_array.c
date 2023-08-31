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

/**
 * heap_to_sorted_array - Creates a sorted array from a max heap
 * @heap: Pointer to heap's node
 * @size: Pointer to arrays size
 *
 * Return: Pointer to array of integeres
 */
int *heap_to_sorted_array(heap_t *heap, size_t *size)
{
	int ax, ndes, *array = NULL;

	*size = 0;
	if (!heap)
		return (NULL);

	ndes = _count_nodes(heap);
	array = malloc(sizeof(*array) * ndes);
	if (!array)
		return (NULL);

	*size = ndes;
	for (ax = 0; ax < ndes; ax++)
		array[ax] = heap_extract(&heap);

	return (array);
}