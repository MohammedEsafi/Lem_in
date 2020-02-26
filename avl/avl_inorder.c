/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   avl_inorder.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbareich <tbareich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 12:50:49 by tbareich          #+#    #+#             */
/*   Updated: 2020/02/26 13:14:23 by tbareich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "avl.h"

void		avl_inorder(t_avl *root, void *ptr, void (*f)(void *, void *))
{
	if (root == NULL)
		return ;
	avl_print(root->left);
	f(ptr, root);
	avl_print(root->right);
}
