#include "binary_trees.h"
/**
 * bst_insert - This function inserts a value into a Binary Search Tree.
 * @tree: A double pointer to the root node of the BST to insert the value.
 * @value: A value to store in the node to be inserted.
 * Return: A pointer to the created node or Null on failure
 */
bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *auxiliary = NULL;

	if (tree == NULL)
		return (NULL);
	if (*tree == NULL)
	{
		*tree = binary_tree_node(NULL, value);
		return (*tree);
	}
	auxiliary = *tree;
	if (value < auxiliary->n)
	{
		if (auxiliary->left == NULL)
		{
			auxiliary->left = binary_tree_node(auxiliary, value);
			return (auxiliary->left);
		}
		return (bst_insert(&(auxiliary->left), value));
	}
	if (value > auxiliary->n)
	{
		if (auxiliary->right == NULL)
		{
			auxiliary->right = binary_tree_node(auxiliary, value);
			return (auxiliary->right);
		}
		return (bst_insert(&(auxiliary->right), value));
	}
	return (NULL);
}
