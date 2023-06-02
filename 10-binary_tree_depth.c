#include "binary_trees.h"

/**
 * binary_tree_depth - measures the depth of a node in a binary tree
 * @tree: is a pointer to the node to measure the depth
 *
 * Return: depth of a node in a binary tree, if tree is NULL return  0
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
	size_t nd;

	if (!tree)
		return (0);
	if (tree->parent == NULL)
		return (0);
	nd = binary_tree_depth(tree->parent);
	return (nd + 1);
}
