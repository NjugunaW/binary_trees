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
 * print_at_level - This function prints a node at a specific level
 * @tree: A pointer to the root node of the tree to traverse
 * @func: A pointer to a function to call for each node.
 * @level: The level to print
 */
void print_at_level(const binary_tree_t *tree, void (*func)(int), int level)
{
	if (tree && func)
	{
		if (level == 1)
			func(tree->n);
		else
		{
			print_at_level(tree->left, func, level - 1);
			print_at_level(tree->right, func, level - 1);
		}
	}

}

/**
 * binary_tree_levelorder -This function goes through a binary tree using
 * level-order traversal
 * @tree: A pointer to the root node of the tree to traverse
 * @func: A pointer to a function to call for each node.
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	size_t height = 0, i = 1;

	if (tree && func)
	{
		height = binary_tree_height(tree);
		while (i <= height + 1)
		{
			print_at_level(tree, func, i);
			i++;
		}
	}

}
