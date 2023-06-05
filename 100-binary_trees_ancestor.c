#include "binary_trees.h"

/**
 * binary_trees_ancestor - finds the lowest common ancestor of two nodes
 * @first: is a pointer to the first node
 * @second: is a pointer to the second node
 *
 * Return: a pointer to the lowest common ancestor node of the two given nodes
 * If no common ancestor was found, return NULL
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
		const binary_tree_t *second)
{
	const binary_tree_t *tmp;

	if (!first || !second)
		return (NULL);
	if (first->parent == NULL || second->parent == NULL)
		return (first->parent);
	/**
	 * Lowest common ancestor in a binary tree can be found by checking
	 * every parent of both the first and second node and comparing if they
	 * shared a common parent. If so the lowest common ancestor is the one
	 * they shared first.
	 */
	while (first->parent != NULL)
	{
		tmp = second;
		while (tmp->parent != NULL)
		{
			if (first == tmp->parent)
				return (tmp->parent);
			if (tmp == first->parent)
				return (first->parent);
			if (first->parent == tmp->parent)
				return (first->parent);
			tmp = tmp->parent;
		}
		first = first->parent;
	}
	return (NULL);
}
