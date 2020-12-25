/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mesafi <mesafi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/19 14:24:36 by mesafi            #+#    #+#             */
/*   Updated: 2020/12/19 14:24:37 by mesafi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lem_in.h"

static void	del_child(t_list *child)
{
	ft_memdel((void **)&(child->content));
	ft_memdel((void **)&child);
}

void		del_path(t_list *node)
{
	ft_lstiter(((t_path *)(node->content))->list, del_child);
	ft_memdel((void **)&(node->content));
	ft_memdel((void **)&node);
}
