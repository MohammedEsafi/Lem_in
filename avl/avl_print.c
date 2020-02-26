/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   avl_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mesafi <mesafi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 10:49:35 by tbareich          #+#    #+#             */
/*   Updated: 2020/02/26 11:27:13 by mesafi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "avl.h"
#include "../libft/ft_printf/ft_printf.h"

void		avl_print(t_avl *root)
{
	if (root == NULL)
		return ;
	avl_print(root->left);
	ft_printf("%i\n", root->key);
	avl_print(root->right);
}

void		avl_print_str(t_avl *root)
{
	if (root == NULL)
		return ;
	avl_print_str(root->left);
	ft_printf("%d\t", root->height);
	ft_printf("%s\n", (char *)root->content);
	avl_print_str(root->right);
}

void		avl_print_elem(t_avl *root, void (*print)(t_avl *))
{
	if (root == NULL)
		return ;
	avl_print_elem(root->left, print);
	print(root);
	avl_print_elem(root->right, print);
}
