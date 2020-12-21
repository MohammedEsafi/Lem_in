/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   avl_delete.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbareich <tbareich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 17:55:17 by tbareich          #+#    #+#             */
/*   Updated: 2020/12/21 23:06:47 by tbareich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "avl.h"

void	avl_delete(t_avl **root, void (*del)(void*, size_t))
{
	if ((*root) == NULL)
		return ;
	avl_delete(&((*root)->left), del);
	avl_delete(&((*root)->right), del);
	del((*root)->content, (*root)->content_size);
	ft_memdel((void **)root);
}
