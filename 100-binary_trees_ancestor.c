#include "binary_trees.h"

/**
 * binary_tree_depth - This function measures the
 * depth of a node in a binary tree
 *@tree: A pointer to the node to measure the depth.
 * Return: if tree is NULL, function must return 0.
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
	if (tree == NULL || tree->parent == NULL)
		return (0);
	else
		return (1 + binary_tree_depth(tree->parent));
}

/**
 * binary_trees_ancestor - This function finds the lowest
 * common ancestor of two nodes
 * @first: A pointer to the first node
 * @second: A pointer to the second node
 * Return: The lowest common ancestor
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
				     const binary_tree_t *second)
{
	size_t first_height = 0, second_height = 0;
	const binary_tree_t *aux = NULL;

	first_height = binary_tree_depth(first);
	second_height = binary_tree_depth(second);
	if (first_height && second_height)
	{
		if (first_height > second_height)
		{
			aux = first;
			first = second;
			second = aux;
		}
		while (first)
		{
			aux = second;
			while (aux)
			{
				if (first == aux)
					return ((binary_tree_t *)first);
				aux = aux->parent;
			}
			first = first->parent;
		}
	}
	else
	{
		return (NULL);
	}
	return (NULL);
}
