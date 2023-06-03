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
	if (!node || node->parent == NULL)
		return (NULL);
	if (node->parent->parent == NULL)
		return (NULL);
	if (node->parent->left == node)
	{       /* uncle for left node */
		if (node->parent->parent->left != NULL)
			return (node->parent->parent->left);
	}
	else if (node->parent->right == node)
	{ /* uncle for right node */
		if (node->parent->parent->right != NULL)
			return (node->parent->parent->right);
	}
	return (NULL);
}
