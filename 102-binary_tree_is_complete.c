#include "binary_trees.h"
#include <stdlib.h>
#include <stdio.h>

size_t binary_tree_height(const binary_tree_t *tree);
int binary_tree_is_complete(const binary_tree_t *tree);
int is_complete_recursive(const binary_tree_t *tree, size_t index,
		size_t height, int complete_level);

/**
 * binary_tree_height - Measures the height of a binary tree
 * @tree: Pointer to the root node of the tree to measure the height
 *
 * Return: Height of the binary tree, or 0 if tree is NULL
 */

size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t left_height, right_height;

	if (tree == NULL)
		return (0);

	left_height = binary_tree_height(tree->left);
	right_height = binary_tree_height(tree->right);

	return ((left_height > right_height ? left_height : right_height) + 1);
}


/**
 * binary_tree_is_complete - Checks if a binary tree is complete
 * @tree: Pointer to the root node of the tree to check
 *
 * Return: 1 if the tree is complete, 0 otherwise
 */

int binary_tree_is_complete(const binary_tree_t *tree)
{
	size_t height, i;
	int complete_level = 0;

	if (tree == NULL)
		return (0);

	height = binary_tree_height(tree);

	for (i = 0; i < height - 1; i++)
		complete_level |= (1 << i);

	return (is_complete_recursive(tree, 0, height - 1, complete_level));
}


/**
 * is_complete_recursive - Helper function for binary_tree_is_complete
 * @tree: Pointer to the root node of the tree
 * @index: Index of the current node (starts from 0)
 * @height: Height of the tree
 * @complete_level: Bitmap representing the complete levels
 *
 * Return: 1 if the subtree rooted at tree is complete, 0 otherwise
 */

int is_complete_recursive(const binary_tree_t *tree, size_t index,
		size_t height, int complete_level)
{
	if (tree == NULL)
		return (1);

	if (index >= (size_t)(1 << height))
		return (0);

	return (is_complete_recursive(tree->left, 2 * index + 1, height - 1,
				complete_level) && is_complete_recursive(tree->right, 2 * index + 2,
					height - 1, complete_level));
}
