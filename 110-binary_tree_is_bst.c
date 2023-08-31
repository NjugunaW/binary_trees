#include "binary_trees.h"
/**
 * find_node - This function finds the node in a tree
 * @root: The root of the tree to evaluate
 * @node: The node to find
 * Return: 1 if exits 0 if not
 */
int find_node(binary_tree_t *root, binary_tree_t *node)
{

	if (root == NULL)
		return (0);
	if (node == root)
		return (1);
	if (node->n < root->n)
		return (find_node(root->left, node));
	if (node->n > root->n)
		return (find_node(root->right, node));
	return (0);
}
/**
 * tree_cross - This function crosses the tree checking if each node
 * exist correctly
 * @root: The root node of the tree
 * @node: The current node to evaluate
 * Return: 1 if is BST 0 if not
 */
int tree_cross(binary_tree_t *root, binary_tree_t *node)
{
	if (root && node)
	{
		int auxiliary = 0;

		auxiliary = find_node(root, node);
		if (node->left)
			auxiliary &= tree_cross(root, node->left);
		if (node->right)
			auxiliary &= tree_cross(root, node->right);
		return (auxiliary);
	}
	return (0);
}
/**
 * binary_tree_is_bst - This function check if binary tree
 * is a BST
 * @tree: A pointer to the root node of the tree to check
 * Return: 1 if bst 0 if not
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (tree_cross((binary_tree_t *)tree, (binary_tree_t *)tree));
}
