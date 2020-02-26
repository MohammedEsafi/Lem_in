/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   avl_str_insert.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mesafi <mesafi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 06:46:57 by tbareich          #+#    #+#             */
/*   Updated: 2020/02/25 10:33:07 by mesafi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "avl.h"

t_avl	*avl_insert_str(t_avl *root, int key, void *content, size_t size)
{
	int		balance;

	if (root == 0)
		return (new_node(key, content, size));
	if (ft_strcmp((const char *)content, (const char *)root->content) < 0)
		root->left = avl_insert_str(root->left, key, content, size);
	else if (ft_strcmp((const char *)content, (const char *)root->content) > 0)
		root->right = avl_insert_str(root->right, key, content, size);
	else
		return (root);
	balance = get_balance(root);
	root->height = height(root);
	if (balance > 1 && ft_strcmp(content, root->right->content) > 0)
		return (left_rot(root));
	if (balance < -1 && ft_strcmp(content, root->left->content) < 0)
		return (right_rot(root));
	if (balance < -1 && ft_strcmp(content, root->left->content) > 0)
	{
		root->left = left_rot(root->left);
		return (right_rot(root));
	}
	if (balance > 1 && ft_strcmp(content, root->right->content) < 0)
	{
		root->right = right_rot(root->right);
		return (left_rot(root));
	}
	return (root);
}
