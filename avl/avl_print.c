/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   avl_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbareich <tbareich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 10:49:35 by tbareich          #+#    #+#             */
/*   Updated: 2020/02/24 10:54:41 by tbareich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "avl.h"
#include "../libft/ft_printf/ft_printf.h"

void		print_str_avl(t_avl *root)
{
	if (root == NULL)
		return ;
	print_str_avl(root->left);
	ft_printf("%s\n", (char *)root->content);
	print_str_avl(root->right);
}
