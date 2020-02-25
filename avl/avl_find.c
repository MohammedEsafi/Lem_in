/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   avl_find.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbareich <tbareich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 13:00:11 by tbareich          #+#    #+#             */
/*   Updated: 2020/02/25 13:45:34 by tbareich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "avl.h"

t_avl	*avl_find(t_avl *root, int key)
{
	if (root == 0)
		return (0);
	if (key < root->key)
		return (avl_find(root->left, key));
	if (key > root->key)
		return (avl_find(root->right, key));
	return (root);
}

t_avl	*avl_find_str(t_avl *root, char *str)
{
	if (root == 0)
		return (0);
	if (ft_strcmp(str, root->content) < 0)
		return (avl_find_str(root->left, str));
	if (ft_strcmp(str, root->content) > 0)
		return (avl_find_str(root->right, str));
	return (root);
}
