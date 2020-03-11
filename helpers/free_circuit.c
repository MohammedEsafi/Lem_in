/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_circuit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbareich <tbareich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 14:22:22 by mesafi            #+#    #+#             */
/*   Updated: 2020/03/09 05:08:20 by tbareich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lem_in.h"

static void	del_child(t_list *child)
{
	ft_memdel((void **)&(child->content));
	ft_memdel((void **)&child);
}

static void	del_path(t_list *node)
{
	ft_lstiter(((t_path *)(node->content))->list, del_child);
	ft_memdel((void **)&(node->content));
	ft_memdel((void **)&node);
}

void		free_circuit(t_circuit *circuit)
{
	if (circuit == NULL)
		return ;
	ft_lstiter(circuit->routes, del_path);
	ft_memdel((void **)&circuit);
}
