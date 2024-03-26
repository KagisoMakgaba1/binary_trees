#include "binary_trees.h"

/**
 * binary_tree_height - Measures the height of a binary tree.
 * @tree: Pointer to the root node of the tree to measure the height.
 *
 * Return: The height of the tree, or 0 if tree is NULL.
 */

size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t height_of_left, height_of_right;

	if (tree == NULL)
		return 0;

	height_of_left = tree->left ? 1 + binary_tree_height(tree->left) : 0;

	height_of_right = tree->right ? 1 + binary_tree_height(tree->right) : 0;

	return (height_of_left > height_of_right ? height_of_left : height_of_right);
}
