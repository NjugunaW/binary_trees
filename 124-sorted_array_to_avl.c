#include "binary_trees.h"
/**
 * aux_sort - create the tree using the half element of the array
 * @parent: parent of the node to create
 * @array: sorted array
 * @begin: position where the array starts
 * @last: position where the array ends
 * Return: tree created
 */
avl_t *aux_sort(avl_t *parent, int *array, int begin, int last)
{
	avl_t *_root_;
	binary_tree_t *auxllry;
	int mid = 0;

	if (begin <= last)
	{
		mid = (begin + last) / 2;
		auxllry = binary_tree_node((binary_tree_t *)parent, array[mid]);
		if (auxllry == NULL)
			return (NULL);
		_root_ = (avl_t *)auxllry;
		_root_->left = aux_sort(_root_, array, begin, mid - 1);
		_root_->right = aux_sort(_root_, array, mid + 1, last);
		return (_root_);
	}
	return (NULL);
}
/**
 * sorted_array_to_avl - create a alv tree from sorted array
 * @array: sorted array
 * @size: size of the sorted array
 * Return: alv tree form sorted array
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	if (array == NULL || size == 0)
		return (NULL);
	return (aux_sort(NULL, array, 0, ((int)(size)) - 1));
}