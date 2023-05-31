#include "binary_trees.h"

/**
 * binary_tree_insert_left - inserts a node as the left-child of another node
 * @parent: is a pointer to the node to insert the left-child in
 * @value: is the value to store in the new node
 *
 * Return: a pointer to the created node, or NULL on failure or
 * if `parent` is NULL. If `parent` already has a left-child, the
 * new node must take its place, and the old left-child must be set
 * as the left-child of the new node.
 */
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *node, *left_child;

	if (!parent)
		return (NULL);
	node = binary_tree_node(parent, value);
	if (parent->left)
	{
		left_child = parent->left;
		parent->left = node;
		node->left = left_child;
		left_child->parent = node;
	}
	else
	{
		parent->left = node;
	}
	return (node);
}
