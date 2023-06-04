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
	binary_tree_t *fp[1024];
	binary_tree_t *sp[1024];
	int i = 0, j = 0, m = 0, k, n;

	if (!first || !second)
		return (NULL);
	if (first->parent == NULL || second->parent == NULL)
		return (NULL);
	if (first->parent == second)
		return ((binary_tree_t *)second);
	if (second->parent == first)
		return ((binary_tree_t *)first);
	/**
	 * Lowest common ancestor in a binary tree can be found by storing paths
	 * from first parent to the root node and second parent to the root node. And
	 * then look simultaneously into the values stored in data structure, and
	 * look for the first match.
	 */
	while (first != NULL)
		fp[i] = first->parent, first = first->parent, i++;
	while (second != NULL)
		sp[j] = second->parent, second = second->parent, j++;
	k = (i > j) ? j : i;
	while (m < k)
	{
		n = 0;
		while (n < k)
		{
			if (fp[m] == sp[n])
				return (fp[m]);
			n++;
		}
		m++;
	}
	return (NULL);
}
