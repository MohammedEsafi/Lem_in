/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   avl_rot.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbareich <tbareich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 13:42:09 by tbareich          #+#    #+#             */
/*   Updated: 2020/02/25 13:42:11 by tbareich         ###   ########.fr       */
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
