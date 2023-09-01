#include "binary_trees.h"

/**
 * binary_tree_insert_right - fnctn inserts node as right-child of another node
 *@parent: pointer to the node to insert the right-child in
 *@value: value to store in the new node
 * Return: pointer to the created node, or NULL on failure or if parent is NULL
 */
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *_new_node = NULL;

	if (parent == NULL || value == '\0')
		return (NULL);

	_new_node = malloc(sizeof(binary_tree_t));
	if (_new_node == NULL)
		return (NULL);

	_new_node->n = value;
	_new_node->parent = parent;
	_new_node->left = NULL;
	_new_node->right = NULL;

	if (parent->right != NULL)
	{
		_new_node->right = parent->right;
		_new_node->right->parent = _new_node;
	}
	parent->right = _new_node;
	return (_new_node);
}
