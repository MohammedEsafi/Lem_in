/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   avl_insert.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mesafi <mesafi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 11:14:45 by tbareich          #+#    #+#             */
/*   Updated: 2020/02/26 11:02:26 by mesafi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "avl.h"

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

t_avl	*avl_insert_str(t_avl *root, char *str)
{
	int		balance;

	if (root == 0)
		return (new_node(0, str, ft_strlen(str)));
	if (ft_strcmp(str, (const char *)root->content) < 0)
		root->left = avl_insert_str(root->left, str);
	else if (ft_strcmp(str, (const char *)root->content) > 0)
		root->right = avl_insert_str(root->right, str);
	else
		return (root);
	balance = get_balance(root);
	root->height = height(root);
	if (balance > 1 && ft_strcmp(str, root->right->content) > 0)
		return (left_rot(root));
	if (balance < -1 && ft_strcmp(str, root->left->content) < 0)
		return (right_rot(root));
	if (balance < -1 && ft_strcmp(str, root->left->content) > 0)
		return (left_right_rot(root));
	if (balance > 1 && ft_strcmp(str, root->right->content) < 0)
		return (right_left_rot(root));
	return (root);
}

t_avl	*avl_insert_elem(t_avl *root, void *content, size_t content_size,
							int (*f)(void *, void *))
{
	int		balance;

	if (root == 0)
		return (new_node_elem(content, content_size));
	if (f(content, root->content) < 0)
		root->left = avl_insert_elem(root->left, content, content_size, f);
	else if (f(content, root->content) > 0)
		root->right = avl_insert_elem(root->right, content, content_size, f);
	else
		return (root);
	balance = get_balance(root);
	root->height = height(root);
	if (balance > 1 && f(content, root->right->content) > 0)
		return (left_rot(root));
	if (balance < -1 && f(content, root->left->content) < 0)
		return (right_rot(root));
	if (balance < -1 && f(content, root->left->content) > 0)
		return (left_right_rot(root));
	if (balance > 1 && f(content, root->right->content) < 0)
		return (right_left_rot(root));
	return (root);
}
