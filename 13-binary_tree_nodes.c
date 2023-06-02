#include "binary_trees.h"

/**
 * binary_tree_nodes - counts the node with at least 1 child in a binary tree
 * @tree: is a pointer to the root node of the tree to count the
 * number of nodes
 *
 * Return: number of node that have at least 1 child, or 0 if tree is NULL
 */
size_t binary_tree_nodes(const binary_tree_t *tree)
{
	size_t num_node_l, num_node_r;

	if (!tree)
		return (0);
	if (tree->left == NULL && tree->right == NULL)
		return (0);
	num_node_l = binary_tree_nodes(tree->left);
	num_node_r = binary_tree_nodes(tree->right);
	return (num_node_l + num_node_r + 1);
}
