#include "binary_trees.h"

/**
 * binary_tree_uncle - finds the uncle of a node
 * @node: is a pointer to the node to find the uncle
 *
 * Return: a pointer to the uncle node. If node is NULL, return NULL
 * If node has no uncle, return NULL
 */
binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
	if (!node)
		return (NULL);
	if (node->parent != NULL)
		if (node->parent->parent == NULL)
			return (NULL);
	if (node->parent->left == node)
	{
		if (node->parent->parent->left != NULL && node->parent->parent->left !=
				node->parent)
			return (node->parent->parent->left);
		else
			return (node->parent->parent->right);
	}
	else if (node->parent->right == node)
	{
		if (node->parent->parent->right != NULL && node->parent->parent->right !=
				node->parent)
			return (node->parent->parent->right);
		else
			return (node->parent->parent->left);
	}
	return (NULL);
}
