/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   avl_str_insert.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbareich <tbareich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 06:46:57 by tbareich          #+#    #+#             */
/*   Updated: 2020/02/20 12:12:07 by tbareich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <avl.h>

t_avl	*insert_str(t_avl *root, t_avl *node)
{
	int		balance;

	if (root == 0)
		return (node);
	if (ft_strcmp(node->content, root->content) < 0)
		root->left = insert_str(root->left, node);
	if (ft_strcmp(node->content, root->content) > 0)
		root->right = insert_str(root->right, node);
	else
		return (root);
	root->height = height(root);
	balance = get_balance(root);
	if (balance > 1 && ft_strcmp(node->content, root->right->content) > 0)
		return (left_rot(root));
	if (balance < -1 && ft_strcmp(node->content, root->left->content) < 0)
		return (right_rot(root));
	if (balance > 1 && ft_strcmp(node->content, root->left->content) > 0)
	{
		root->left = right_rot(root->left);
		return (left_rot(root));
	}
	if (balance < -1 && ft_strcmp(node->content, root->right->content) > 0)
	{
		root->right = right_rot(root->right);
		return (left_rot(root));
	}
	return (root);
}
