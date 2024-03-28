#include "binary_trees.h"

size_t binary_tree_height(const binary_tree_t *tree);
int binary_tree_balance(const binary_tree_t *tree);
avl_t *avl_rotate_left(avl_t *tree);
avl_t *avl_rotate_right(avl_t *tree);
avl_t *avl_insert(avl_t **tree, int value);

/**
 * binary_tree_height - Measures the height of a binary tree
 * @tree: Pointer to the root node of the tree
 *
 * Return: Height of the tree, or 0 if tree is NULL
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
 * binary_tree_balance - Measures the balance factor of a binary tree
 * @tree: Pointer to the root node of the tree
 *
 * Return: Balance factor of the tree, or 0 if tree is NULL
 */

int binary_tree_balance(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (binary_tree_height(tree->left) - binary_tree_height(tree->right));
}


/**
 * avl_rotate_left - Performs a left rotation on an AVL tree
 * @tree: Pointer to the root node of the AVL tree
 *
 * Return: Pointer to the new root node after rotation
 */

avl_t *avl_rotate_left(avl_t *tree)
{
	avl_t *new_root = tree->right;

	tree->right = new_root->left;
	if (new_root->left != NULL)
		new_root->left->parent = tree;
	new_root->left = tree;
	new_root->parent = tree->parent;
	tree->parent = new_root;

	return (new_root);
}


/**
 * avl_rotate_right - Performs a right rotation on an AVL tree
 * @tree: Pointer to the root node of the AVL tree
 *
 * Return: Pointer to the new root node after rotation
 */

avl_t *avl_rotate_right(avl_t *tree)
{
	avl_t *new_root = tree->left;

	tree->left = new_root->right;
	if (new_root->right != NULL)
		new_root->right->parent = tree;
	new_root->right = tree;
	new_root->parent = tree->parent;
	tree->parent = new_root;

	return (new_root);
}


/**
 * avl_insert - Inserts a value in an AVL Tree
 * @tree: Double pointer to the root node of the AVL tree
 * @value: Value to store in the node to be inserted
 *
 * Return: Pointer to the created node, or NULL on failure
 */

avl_t *avl_insert(avl_t **tree, int value)
{
	int balance = binary_tree_balance(*tree);

	if (tree == NULL)
		return (NULL);

	if (*tree == NULL)
	{
		*tree = binary_tree_node(NULL, value);
		if (*tree == NULL)
			return (NULL);
		return (*tree);
	}

	avl_t *inserted_node;

	if (value < (*tree)->n)
	{
		inserted_node = avl_insert(&((*tree)->left), value);
		if (inserted_node == NULL)
			return (NULL);
	}
	else if (value > (*tree)->n)
	{
		inserted_node = avl_insert(&((*tree)->right), value);
		if (inserted_node == NULL)
			return (NULL);
	}
	else
	{
		return (NULL);
	}

	if (balance > 1 && value < (*tree)->left->n)
		return (avl_rotate_right(*tree));
	if (balance < -1 && value > (*tree)->right->n)
		return (avl_rotate_left(*tree));
	if (balance > 1 && value > (*tree)->left->n)
	{
		(*tree)->left = avl_rotate_left((*tree)->left);
		return (avl_rotate_right(*tree));
	}
	if (balance < -1 && value < (*tree)->right->n)
	{
		(*tree)->right = avl_rotate_right((*tree)->right);
		return (avl_rotate_left(*tree));
	}

	return (inserted_node);
}
