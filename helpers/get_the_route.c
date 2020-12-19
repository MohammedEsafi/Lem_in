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

static t_path		*init_path(int index)
{
	t_path	*path;

	if (!(path = (t_path *)malloc(sizeof(t_path))))
		return (NULL);
	path->size = 1;
	path->list = ft_lstnew(&(index), sizeof(int));
	path->ants = 0;
	return (path);
}

static int			omit(t_path *path, int boolean)
{
	if (boolean)
	{
		ft_memdel((void **)&path);
		return (1);
	}
	return (0);
}

int					get_the_route(t_lem_in *farm, unsigned *total_edges,
								int prev[farm->graph->v], t_circuit *circuit)
{
	t_path		*path;
	t_list		*node;
	int			current;

	current = farm->end;
	if (!(path = init_path(current)))
		return (-1);
	farm->seen[current] = 1;
	node = path->list;
	while (current != farm->start)
	{
		current = prev[current];
		farm->seen[current] = 1;
		if (omit(path, (node->next = ft_lstnew(&(current), sizeof(int))) == 0))
			return (-1);
		path->size += 1;
		node = node->next;
	}
	node = (t_list *)malloc(sizeof(t_list));
	node->content_size = sizeof(t_path);
	node->content = path;
	ft_lstadd(&(circuit->routes), node);
	circuit->size += 1;
	*total_edges += path->size;
	return (0);
}
