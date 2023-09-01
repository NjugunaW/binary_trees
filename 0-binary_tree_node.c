#include "binary_trees.h"

/**
 * binary_tree_node - function that creates a binary tree node.
 *@parent:  pointer to the parent node of the node to create
 *@value: the value to put in the new node
 * Return: pointer to the new node, or NULL on failure
 */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *_new_node;

	if (value == '\0')
		return (NULL);

	_new_node = malloc(sizeof(binary_tree_t));
	if (_new_node == NULL)
		return (NULL);

	_new_node->n = value;
	_new_node->parent = parent;
	_new_node->left = NULL;
	_new_node->right = NULL;

	return (_new_node);
}