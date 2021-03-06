/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   avl_find.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mesafi <mesafi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 13:00:11 by tbareich          #+#    #+#             */
/*   Updated: 2020/02/26 11:53:03 by mesafi           ###   ########.fr       */
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

t_avl	*avl_find_elem(t_avl *root, void *content, int (*cmp)(void *, void *))
{
	if (root == 0)
		return (0);
	if (cmp(content, root->content) < 0)
		return (avl_find_elem(root->left, content, cmp));
	if (cmp(content, root->content) > 0)
		return (avl_find_elem(root->right, content, cmp));
	return (root);
}
