#include "binary_trees.h"

/**
 * binary_tree_is_perfect - check if a binary tree is perfect
 * @tree: is a pointer to the root node of the tree to check
 *
 * Return: 1 if binary tree is perfect, or 0
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	size_t num_none_leaf_nodes, num_leaf_nodes;

	if (!tree)
		return (0);
	/**
	 * For perfect binary tree the number of leaf nodes is a power of 2^n and
	 * No.of leaf nodes == No. of none-leaf nodes + 1.
	 * A tree with only the root node is also a perfect binary tree
	 */
	num_none_leaf_nodes = binary_tree_nodes(tree);
	num_leaf_nodes = binary_tree_leaves(tree);
	if (!tree->left && !tree->right && tree->parent == NULL)
		return (1);
	if ((num_leaf_nodes == num_none_leaf_nodes + 1) && (num_leaf_nodes % 2 == 0))
		return (1);
	else
		return (0);
}
/**
 * binary_tree_leaves - counts the leaves in a binary tree
 * @tree: is a pointer to the root node of the tree to count
 * the number of leaves
 *
 * Return: the number of leaves the node contains, or 0 if tree is NULL
 */
size_t binary_tree_leaves(const binary_tree_t *tree)
{
	size_t lf, rf;

	if (!tree)
		return (0);
	if (tree->left == NULL && tree->right == NULL)
		return (1);
	lf = binary_tree_leaves(tree->left);
	rf = binary_tree_leaves(tree->right);
	return (lf + rf);
}
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
