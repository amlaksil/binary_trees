#include "binary_trees.h"
# define max(x, y) ((x > y) ? x : y)

/**
 * binary_tree_balance - measures the balance factor of a binary tree
 * @tree: is a pointer to the root node of the tree to measure
 * the balance factor
 *
 * Return: the balance factor a given node, or 0 if tree is NULL
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	int lh = 0, rh = 0, lhr = 0, rhl = 0;
	binary_tree_t *lptr, *rptr, *lptr_r, *rptr_l;

	if (!tree)
		return (0);
	lptr = tree->left;
	rptr = tree->right;
	while (lptr != NULL)
	{
		if (lptr->right != NULL)
		{
			lptr_r = lptr->right;
			while (lptr_r != NULL)
			{
				lhr++;
				lptr_r = lptr_r->right;
			}
		}
		lh++;
		lptr = lptr->left;
	}
	while (rptr != NULL)
	{
		if (rptr->left != NULL)
		{
			rptr_l = rptr->left;
			while (rptr_l != NULL)
			{
				rhl++;
				rptr_l = rptr_l->left;
			}
		}
		rh++;
		rptr = rptr->right;
	}
	return (max(lh, lhr) - max(rh, rhl));
}
