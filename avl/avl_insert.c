/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   avl_insert.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbareich <tbareich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 11:14:45 by tbareich          #+#    #+#             */
/*   Updated: 2020/02/25 11:36:27 by tbareich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "avl.h"

t_avl	*left_rot(t_avl *node)
{
	t_avl	*right;
	t_avl	*tmp;

	right = node->right;
	tmp = right->left;
	right->left = node;
	node->right = tmp;
	node->height = height(node);
	right->height = height(right);
	return (right);
}

t_avl	*right_rot(t_avl *node)
{
	t_avl	*left;
	t_avl	*tmp;

	left = node->left;
	tmp = left->right;
	left->right = node;
	node->left = tmp;
	node->height = height(node);
	left->height = height(left);
	return (left);
}

t_avl	*right_left_rot(t_avl *node)
{
	node->right = right_rot(node->right);
	return (left_rot(node));
}

t_avl	*left_right_rot(t_avl *node)
{
	node->left = left_rot(node->left);
	return (right_rot(node));
}

t_avl	*avl_insert(t_avl *root, int key)
{
	int		balance;

	if (root == 0)
		return (new_node(key, 0, 0));
	if (key < root->key)
		root->left = avl_insert(root->left, key);
	else if (key > root->key)
		root->right = avl_insert(root->right, key);
	else
		return (root);
	balance = get_balance(root);
	root->height = height(root);
	if (balance > 1 && key > root->right->key)
		return (left_rot(root));
	if (balance < -1 && key < root->left->key)
		return (right_rot(root));
	if (balance < -1 && key > root->left->key)
		return (left_right_rot(root));
	if (balance > 1 && key < root->right->key)
		right_left_rot(root);
	return (root);
}
