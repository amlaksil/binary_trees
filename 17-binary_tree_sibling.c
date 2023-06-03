#include "binary_trees.h"

/**
 * binary_tree_sibling - finds the sibling of a node
 * @node: is a pointer to the node to find the sibling
 *
 * Return: a pointer to the sibling node. If node is NULL or the
 * parent is NULL, return NULL. If node has no sibling, return NULL
 */
binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
	if (!node || node->parent == NULL)
		return (NULL);
	if (node->parent->left == node)
	{	/* sibling for left node */
		if (node->parent->right != NULL)
			return (node->parent->right);
	}
	else if (node->parent->right == node)
	{	/* sibling for right node */
		if (node->parent->left != NULL)
			return (node->parent->left);
	}
	return (NULL);
}
