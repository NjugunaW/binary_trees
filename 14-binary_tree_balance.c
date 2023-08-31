#include "binary_trees.h"

/**
 * binary_tree_height - This function measures the height of a binary tree.
 *@tree: A pointer to the root node of the tree to measure the height.
 * Return: if tree is NULL, your function must return 0.
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	if (tree)
	{
		int left_size = 0, right_size = 0;

		if (tree->right)
			right_size = 1 + binary_tree_height(tree->right);
		if (tree->left)
			left_size = 1 + binary_tree_height(tree->left);
		if (left_size > right_size)
			return (left_size);
		else
			return (right_size);
	}
	else
		return (0);
}


/**
 * binary_tree_balance - This function measures the balance factor of a
 * binary tree.
 * @tree: A Pointer to root node to calculate balance factor.
 * Return: The balance factor of the tree.
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	size_t left_height = 0, right_height = 0;

	if (!tree)
		return (0);

	left_height = binary_tree_height(tree->left);
	right_height = binary_tree_height(tree->right);
	return (left_height - right_height);
}
