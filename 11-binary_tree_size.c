#include "binary_trees.h"

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
