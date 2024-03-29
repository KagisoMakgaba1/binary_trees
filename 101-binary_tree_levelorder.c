#include "binary_trees.h"
#include <stdlib.h>

/**
 * binary_tree_levelorder - Performs a level-order traversal of a binary tree
 * @tree: Pointer to the root node of the tree to traverse
 * @func: Pointer to a function to call for each node
 */

void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	int front = 0, rear = 0;
	binary_tree_t *current, **queue;

	if (tree == NULL || func == NULL)
		return;

	queue = malloc(sizeof(binary_tree_t *) * 1024);

	if (queue == NULL)
		return;

	queue[rear++] = (binary_tree_t *)tree;

	while (front < rear)
	{
		current = queue[front++];

		func(current->n);

		if (current->left)
			queue[rear++] = current->left;

		if (current->right)
			queue[rear++] = current->right;
	}

	free(queue);
}
