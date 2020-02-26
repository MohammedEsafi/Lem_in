/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   avl_create.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mesafi <mesafi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 14:10:22 by tbareich          #+#    #+#             */
/*   Updated: 2020/02/26 11:52:43 by mesafi           ###   ########.fr       */
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
	if ((node->content = malloc(size)) == 0)
	{
		ft_memdel((void **)&node);
		return (0);
	}
	ft_memcpy(node->content, content, size);
	node->content_size = size;
	return (node);
}

t_avl	*new_node_elem(void *content, size_t size)
{
	t_avl	*node;

	if ((node = (t_avl *)malloc(sizeof(t_avl))) == 0)
		return (0);
	node->key = 0;
	node->height = 0;
	node->left = 0;
	node->right = 0;
	if (content == NULL || size == 0)
	{
		node->content = 0;
		node->content_size = 0;
		return (node);
	}
	if ((node->content = malloc(size)) == 0)
	{
		ft_memdel((void **)&node);
		return (0);
	}
	ft_memcpy(node->content, content, size);
	node->content_size = size;
	return (node);
}
