#include "binary_trees.h"

/**
 * binary_tree_leaves - This function counts the leaves in a binary tree
 * @tree: A pointer node binary tree
 * Return: Number the leaves in a binary tree
 */
size_t binary_tree_leaves(const binary_tree_t *tree)
{
	size_t all_leaves = 0;

	if (!tree)
		return (0);
	if (!tree->left && !tree->right)
		all_leaves += 1;
	all_leaves += binary_tree_leaves(tree->left);
	all_leaves += binary_tree_leaves(tree->right);
	return (all_leaves);
}
