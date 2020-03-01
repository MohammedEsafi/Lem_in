/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routes_maker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mesafi <mesafi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/01 13:04:09 by tbareich          #+#    #+#             */
/*   Updated: 2020/03/01 15:50:45 by mesafi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lem_in.h"

static t_list	*get_the_way(t_lem_in *farm, char *resid_capacity,
					unsigned onset, unsigned *all_edges)
{
	t_path		*path;
	t_node		*node;

	path = (t_path *)malloc(sizeof(t_path));
	path->size = 1;
	ft_lstadd(&(path->list), ft_lstnew(farm->end, sizeof(int)));
	while (onset != farm->start)
	{
		ft_lstadd(&(path->list), ft_lstnew(onset, sizeof(int)));
		path->size += 1;
		node = farm->graph->adj_list[onset].head;
		while (node != NULL)
		{
			if (resid_capacity[onset * farm->graph->v + node->key] == 1)
			{
				onset = node->key;
				break ;
			}
			node->next;
		}
	}
	ft_lstadd(&(path->list), ft_lstnew(farm->start, sizeof(int)));
	*all_edges += path->size;
	return (ft_lstnew(path, sizeof(t_path)));
}

int				routes_maker(t_lem_in *farm, char *resid_capacity)
{
	t_node		*node;
	t_list		*routes;
	unsigned	size;
	unsigned	score;
	unsigned	all_edges;

	node = farm->graph->adj_list[farm->end].head;
	size = 0;
	all_edges = 0;
	routes = NULL;
	while (node != NULL)
	{
		if (resid_capacity[farm->end * farm->graph->v + node->key] == 1)
		{
			ft_lstadd(&routes, get_the_way(farm, resid_capacity,
					node->key, &all_edges));
			++size;
		}
		node = node->next;
	}
	score = ((all_edges + farm->ants) / size) + !!((all_edges + farm->ants) % size);
	if (score < farm->circuit.score)
	{
		farm->circuit.routes = routes;
		farm->circuit.score = score;
		farm->circuit.size = size;
	}
	else
		return (1);
	return (0);
}
