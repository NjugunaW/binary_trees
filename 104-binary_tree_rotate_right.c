#include "binary_trees.h"

/**
 * binary_tree_rotate_right -  This function performs a rigth-rotation
 * on a binary tree
 * @tree: A pointer to binare_tree_t
 * Return: The pointer to the new root node of the tree once rotated;
 */
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	binary_tree_t *auxiliary, *temporary;

	if (tree == NULL)
		return (NULL);
	if (tree->left)
	{
		temporary = tree->left->right;
		auxiliary = tree->left;
		auxiliary->parent = tree->parent;
		auxiliary->right = tree;
		tree->parent = auxiliary;
		tree->left = temporary;
		if (temporary)
			temporary->parent = tree;
		return (auxiliary);
	}
	return (NULL);
}
