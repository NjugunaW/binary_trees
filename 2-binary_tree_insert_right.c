#include "binary_trees.h"

/**
 * binary_tree_insert_right - fnctn inserts node as right-child of another node
 *@parent: pointer to the node to insert the right-child in
 *@value: value to store in the new node
 * Return: pointer to the created node, or NULL on failure or if parent is NULL
 */
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *new_nde = NULL;

	if (parent == NULL)
		return (NULL);
	new_nde = malloc(sizeof(binary_tree_t));
	if (new_nde == NULL)
		return (NULL);

	new_nde->n = value;
	new_nde->parent = parent;
	new_nde->left = NULL;
	new_nde->right = NULL;
	if (parent->right == NULL)
		parent->right = new_nde;
	else
	{
		new_nde->right = parent->right;
		parent->right = new_nde;
		new_nde->right->parent = new_nde;
	}
	return (new_nde);
}
