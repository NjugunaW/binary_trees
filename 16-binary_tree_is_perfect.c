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
 * binary_tree_size - This function  measures the size of
 * a binary tree
 *@tree: A pointer to the root node of the tree to measure the size.
 * Return: 0 if tree is Null
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	{
		size_t left_node, right_node;

		left_node = binary_tree_size(tree->left);
		right_node = binary_tree_size(tree->right);
		return (1 + left_node + right_node);
	}
}


/**
 * binary_tree_is_perfect - This function checks if a binary tree is perfect.
 *@tree: pointer to the root node of the tree to check.
 * Return: if tree is NULL, function must return 0.
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	size_t height = 0, perfect_tree_size = 0;

	if (tree == NULL)
		return (0);
	height = binary_tree_height(tree);
	perfect_tree_size = (1 << (height + 1)) - 1;
	if (perfect_tree_size == binary_tree_size(tree))
		return (1);
	else
		return (0);
}
