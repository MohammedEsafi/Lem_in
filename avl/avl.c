/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   avl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbareich <tbareich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/16 12:00:22 by tbareich          #+#    #+#             */
/*   Updated: 2020/02/24 11:10:06 by tbareich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "avl.h"

int		height(t_avl *node)
{
	if (node == 0)
		return (0);
	if (node->left == 0 && node->right == 0)
		return (0);
	if (node->left == 0)
		return (node->right->height);
	if (node->right == 0)
		return (node->left->height);
	return (max(node->left->height, node->right->height) + 1);
}

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
	return (node);
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
	return (node);
}

int		get_balance(t_avl *node)
{
	unsigned	right;
	unsigned	left;

	right = 0;
	left = 0;
	if (node->right != 0)
		right = node->right->height;
	if (node->left != 0)
		left = node->left->height;
	return (right - left);
}

t_avl	*new_node(int key, void *content, size_t size)
{
	t_avl	*node;

	if ((node = (t_avl *)malloc(sizeof(t_avl))) == 0)
		return (0);
	node->key = key;
	node->height = 0;
	node->left = 0;
	node->right = 0;
	if (content == NULL)
	{
		node->content = 0;
		node->content_size = 0;
		return (node);
	}
	if ((node->content = malloc(sizeof(size))) == 0)
	{
		ft_memdel((void **)&node);
		return (0);
	}
	ft_memcpy(node->content, content, size);
	node->content_size = size;
	return (node);
}
