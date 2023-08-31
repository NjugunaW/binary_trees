#include "binary_trees.h"

/**
 * binary_tree_node - function that creates a binary tree node.
 *@parent:  pointer to the parent node of the node to create
 *@value: the value to put in the new node
 * Return: pointer to the new node, or NULL on failure
 */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *new_nde = malloc(sizeof(binary_tree_t));

	if (new_nde == NULL)
		return (NULL);
	new_nde->n = value;
	new_nde->parent = parent;
	new_nde->left = NULL;
	new_nde->right = NULL;
	return (new_nde);