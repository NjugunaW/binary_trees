#include "binary_trees.h"

/**
 * array_to_bst - This function builds a Binary Search Tree from an array.
 * @array: A pointer to the first element of the array to be converted.
 * @size: The number of element in the array.
 * Return: A pointer to the root node of the created BST, or NULL on failure.
 */

bst_t *array_to_bst(int *array, size_t size)
{
	bst_t *tree;
	size_t index;

	if (array == NULL)
		return (NULL);
	tree = NULL;
	for (index = 0; index < size; index++)
	{
		bst_insert(&tree, array[index]);
	}
	return (tree);
}
