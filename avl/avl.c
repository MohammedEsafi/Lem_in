/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   avl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbareich <tbareich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/16 12:00:22 by tbareich          #+#    #+#             */
/*   Updated: 2020/02/25 11:37:14 by tbareich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "avl.h"

t_avl	*new_node(int key, void *content, size_t size)
{
	t_avl	*node;

	if ((node = (t_avl *)malloc(sizeof(t_avl))) == 0)
		return (0);
	node->key = key;
	node->height = 0;
	node->left = 0;
	node->right = 0;
	if (content == NULL || size == 0)
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

int		height(t_avl *node)
{
	if (node == 0 || (node->left == 0 && node->right == 0))
		return (0);
	if (node->left == 0)
		return (1 + node->right->height);
	if (node->right == 0)
		return (1 + node->left->height);
	return (1 + max(node->left->height, node->right->height));
}

int		get_balance(t_avl *node)
{
	unsigned	right;
	unsigned	left;

	right = 0;
	left = 0;
	if (node->right != 0)
		right = node->right->height + 1;
	if (node->left != 0)
		left = node->left->height + 1;
	return (right - left);
}
