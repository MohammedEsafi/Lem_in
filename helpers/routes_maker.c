/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routes_maker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mesafi <mesafi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/01 13:04:09 by tbareich          #+#    #+#             */
/*   Updated: 2020/03/02 18:41:56 by mesafi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lem_in.h"

static t_list	*get_the_way(t_lem_in *farm, char *resid_capacity,
					int onset, unsigned *total_edges, char *seen)
{
	t_path		*path;
	t_node		*node;

	path = (t_path *)malloc(sizeof(t_path));
	path->size = 1;
	path->list = NULL;
	path->ants = 0;
	ft_lstadd(&(path->list), ft_lstnew(&(farm->end), sizeof(int)));
	seen[farm->end] = 1;
	while (onset != farm->start)
	{
		ft_lstadd(&(path->list), ft_lstnew(&onset, sizeof(int)));
		seen[onset] = 1;
		path->size += 1;
		node = farm->graph->adj_list[onset].head;
		while (node != NULL)
		{
			if (resid_capacity[node->key * farm->graph->v + onset] == 0)
			{
				onset = node->key;
				break ;
			}
			node = node->next;
		}
	}
	ft_lstadd(&(path->list), ft_lstnew(&(farm->start), sizeof(int)));
	seen[farm->start] = 1;
	*total_edges += path->size;
	return (ft_lstnew(path, sizeof(t_path)));
}

int				routes_maker(t_lem_in *farm, char *seen, char *resid_capacity)
{
	t_node		*node;
	t_circuit	*circuit;
	unsigned	total_edges;

	node = farm->graph->adj_list[farm->end].head;
	circuit = (t_circuit *)malloc(sizeof(t_circuit));
	circuit->size = 0;
	circuit->routes = NULL;
	total_edges = 0;
	while (node != NULL)
	{
		if (resid_capacity[node->key * farm->graph->v + farm->end] == 0)
		{
			ft_lstadd(&(circuit->routes), get_the_way(farm, resid_capacity,
					(int)node->key, &total_edges, seen));
			circuit->size += 1;
		}
		node = node->next;
	}
	circuit->score = ((total_edges + farm->ants) / circuit->size);
	if (circuit->size == 0)
		ft_memdel((void **)&circuit);
	else
		append(&(farm->circuits), circuit);
	if (circuit->score < farm->best_score)
	{
		farm->best_score = circuit->score;
		farm->best_circuit = farm->circuits.cursor;
	}
	return (0);
}
