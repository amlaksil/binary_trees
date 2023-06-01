#include "binary_trees.h"

/**
 * binary_tree_height - measures the height of a binary tree
 * @tree: is a pointer to the root node of the tree to measure the height
 *
 * Return: height of a tree. If tree is NULL, return 0
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t rh, lh;

	if (tree == NULL)
		return (0);
	if (tree->left == NULL && tree->right == NULL)
		return (0);
	lh = binary_tree_height(tree->left);
	rh = binary_tree_height(tree->right);
	return (lh > rh ? lh + 1 : rh + 1);
}
