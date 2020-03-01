/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routes_maker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbareich <tbareich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/01 13:04:09 by tbareich          #+#    #+#             */
/*   Updated: 2020/03/01 19:07:44 by tbareich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lem_in.h"

static t_list	*get_the_way(t_lem_in *farm, char *resid_capacity,
					int onset, unsigned *all_edges, char *seen)
{
	t_path		*path;
	t_node		*node;

	path = (t_path *)malloc(sizeof(t_path));
	path->size = 1;
	path->list = NULL;
	ft_lstadd(&(path->list), ft_lstnew(&(farm->end), sizeof(int)));
	seen[farm->end] = 1;
	while (onset != farm->start)
	{
		// ft_printf("<< %d\n", onset);
		ft_lstadd(&(path->list), ft_lstnew(&onset, sizeof(int)));
		seen[onset] = 1;
		path->size += 1;
		node = farm->graph->adj_list[onset].head;
		while (node != NULL)
		{
			// ft_printf("-- %d\n", node->key);
			// ft_printf("-- %d\n", onset);
			if (resid_capacity[node->key * farm->graph->v + onset] == 0)
			{
				onset = node->key;
				break ;
			}
			ft_printf("-- %d\n", onset);
			node = node->next;
		}
	}
	ft_lstadd(&(path->list), ft_lstnew(&(farm->start), sizeof(int)));
	seen[farm->start] = 1;
	*all_edges += path->size;
	return (ft_lstnew(path, sizeof(t_path)));
}

int				routes_maker(t_lem_in *farm, char *seen, char *resid_capacity)
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
		if (resid_capacity[node->key * farm->graph->v + farm->end] == 0)
		{
			ft_lstadd(&routes, get_the_way(farm, resid_capacity,
					(int)node->key, &all_edges, seen));
			++size;
		}
		node = node->next;
	}
	score = ((all_edges + farm->ants) / size) + (((all_edges + farm->ants)
				% size) > 0);
	if (score <= farm->circuit.score)
	{
		farm->circuit.routes = routes;
		farm->circuit.score = score;
		farm->circuit.size = size;
	}
	else
		return (1);
	return (0);
}
