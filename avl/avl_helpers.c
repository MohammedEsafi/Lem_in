/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   avl_helpers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbareich <tbareich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/16 12:00:22 by tbareich          #+#    #+#             */
/*   Updated: 2020/02/25 14:10:36 by tbareich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "avl.h"

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
