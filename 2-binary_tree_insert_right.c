#include "binary_trees.h"

/**
 * binary_tree_insert_right - inserts a node as the right-child of another node
 * @parent: is a pointer to the node to insert the right-child in
 * @value: is the value to store in the new node
 *
 * Return: a pointer to the created node, or NULL on failure or if `parent`
 * is NULL. If `parent` already has a right-child, the new node must take its
 * place and the old right-child must be set as the right-child of the new node
 */
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *node, *right_child;

	if (!parent)
		return (NULL);
	node = binary_tree_node(parent, value);
	if (parent->right)
	{
		right_child = parent->right;
		parent->right = node;
		node->right = right_child;
		right_child->parent = node;
	}
	else
	{
		parent->right = node;
	}
	return (node);
}
