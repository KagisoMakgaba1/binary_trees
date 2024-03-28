#include "binary_trees.h"

bst_t *find_successor(bst_t *node);
bst_t *bst_remove(bst_t *root, int value);

/**
 * find_successor - Finds the in-order successor of a node in a BST
 * @node: Pointer to the node to find the successor for
 *
 * Return: Pointer to the in-order successor node, or NULL if not found
 */

bst_t *find_successor(bst_t *node)
{
	bst_t *current = node->right;

	while (current != NULL && current->left != NULL)
		current = current->left;

	return (current);
}


/**
 * bst_remove - Removes a node from a Binary Search Tree (BST)
 * @root: Pointer to the root node of the tree where to remove a node
 * @value: Value to remove in the tree
 *
 * Return: Pointer to the new root node of the tree after removing
 * the desired value
 */

bst_t *bst_remove(bst_t *root, int value)
{
	if (root == NULL)
		return (NULL);

	if (value < root->n)
		root->left = bst_remove(root->left, value);
	else if (value > root->n)
		root->right = bst_remove(root->right, value);
	else
	{
		if (root->left == NULL)
		{
			bst_t *temp = root->right;

			free(root);
			return (temp);
		}
		else if (root->right == NULL)
		{
			bst_t *temp = root->left;

			free(root);
			return (temp);
		}

		bst_t *successor = find_successor(root);

		root->n = successor->n;
		root->right = bst_remove(root->right, successor->n);
	}

	return (root);
}
