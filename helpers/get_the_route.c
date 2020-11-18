/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_the_route.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mesafi <mesafi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 08:23:12 by mesafi            #+#    #+#             */
/*   Updated: 2020/11/18 08:23:14 by mesafi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lem_in.h"

static t_path		*init_path(void)
{
	t_path	*path;

	if (!(path = (t_path *)malloc(sizeof(t_path))))
		return (NULL);
	path->size = 1;
	path->list = NULL;
	path->ants = 0;
	return (path);
}

int					get_the_route(t_lem_in *farm, unsigned *total_edges,
								int prev[farm->graph->v], t_circuit *circuit)
{
	t_path		*path;
	t_list		*node;
	int			current;

	if (!(path = init_path()))
		return (-1);
	current = farm->end;
	ft_lstadd(&(path->list), ft_lstnew(&(current), sizeof(int)));
	farm->seen[current] = 1;
	node = path->list;
	while (current != farm->start)
	{
		current = prev[current];
		farm->seen[current] = 1;
		if ((node->next = ft_lstnew(&(current), sizeof(int))) == 0)
			return (-1);
		path->size += 1;
		node = node->next;
	}
	ft_lstadd(&(circuit->routes), ft_lstnew(path, sizeof(t_path)));
	circuit->size += 1;
	*total_edges += path->size;
	return (0);
}
