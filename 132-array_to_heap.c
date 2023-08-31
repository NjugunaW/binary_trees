#include "binary_trees.h"

/**
 * array_to_heap - builds a Max Binary Heap tree from an array
 *
 * @array: pointer to the first element of the array
 * @size: number of element in the array
 * Return: pointer to the root node of the AVL tree
 */
heap_t *array_to_heap(int *array, size_t size)
{
	heap_t *mti;
	size_t ab;

	mti = NULL;

	for (ab = 0; ab < size; ab++)
	{
		heap_insert(&mti, array[ab]);
	}

	return (mti);
}