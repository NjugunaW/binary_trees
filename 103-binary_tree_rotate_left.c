#include "binary_trees.h"

/**
 * binary_tree_rotate_left -  This function performs a left-rotation
 * on a binary tree
 * @tree: A pointer to binare_tree_t
 * Return: The pointer to the new root node of the tree once rotated;
 */
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *auxiliary, *temporary;

	if (tree == NULL)
		return (NULL);
	if (tree->right)
	{
		temporary = tree->right->left;
		auxiliary = tree->right;
		auxiliary->parent = tree->parent;
		auxiliary->left = tree;
		tree->parent = auxiliary;
		tree->right = temporary;
		if (temporary)
			temporary->parent = tree;
		return (auxiliary);
	}
	return (NULL);
}
