/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routes_maker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mesafi <mesafi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/01 13:04:09 by tbareich          #+#    #+#             */
/*   Updated: 2020/03/05 16:02:29 by mesafi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lem_in.h"

static void			ft_correct(t_lem_in *farm, t_circuit *circuit)
{
	t_list		*node;
	t_path		*path;
	int			i;
	
	node = circuit->routes;
	i = -1;
	while (node != NULL)
	{
		++i;
		path = (t_path *)(node->content);
		path->ants = circuit->score - path->size + (circuit->rest-- > 0);
		if (path->ants <= 0)
		{
			circuit->total_edges -= path->size;
			circuit->size -= 1;
			circuit->rest = (circuit->total_edges + farm->ants) % circuit->size;
			circuit->score = (circuit->total_edges + farm->ants) / circuit->size;
			ft_lstdelat(&(circuit->routes), i);
			i = -1;
			node = circuit->routes;
			continue ;
		}
		path->remnant = path->ants;
		node = node->next;
	}
}

static t_circuit	*init_circuit(void)
{
	t_circuit	*circuit;

	if (!(circuit = (t_circuit *)malloc(sizeof(t_circuit))))
		return (NULL);
	circuit->size = 0;
	circuit->routes = NULL;
	circuit->total_edges = 0;
	return (circuit);
}

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

static t_list		*get_the_way(t_lem_in *farm, char *resid_capacity,
					int onset, unsigned *total_edges, char *seen)
{
	t_path		*path;
	t_node		*node;

	if (!(path = init_path()))
		return (NULL);
	ft_lstadd(&(path->list), ft_lstnew(&(farm->start), sizeof(int)));
	seen[farm->start] = 1;
	while (onset != farm->end)
	{
		ft_lstadd(&(path->list), ft_lstnew(&onset, sizeof(int)));
		seen[onset] = 1;
		path->size += 1;
		node = farm->graph->adj_list[onset].head;
		while (node != NULL)
		{
			if (resid_capacity[node->key * farm->graph->v + onset] == 2)
			{
				onset = node->key;
				break ;
			}
			node = node->next;
		}
	}
	ft_lstadd(&(path->list), ft_lstnew(&(farm->end), sizeof(int)));
	seen[farm->end] = 1;
	*total_edges += path->size;
	return (ft_lstnew(path, sizeof(t_path)));
}

int					routes_maker(t_lem_in *farm, char *seen, char *resid_capacity)
{
	t_node		*node;
	t_circuit	*circuit;

	node = farm->graph->adj_list[farm->start].head;
	circuit = init_circuit();
	while (node != NULL)
	{
		if (resid_capacity[node->key * farm->graph->v + farm->start] == 2)
		{
			ft_lstadd(&(circuit->routes), get_the_way(farm, resid_capacity,
					(int)node->key, &(circuit->total_edges), seen));
			circuit->size += 1;
		}
		node = node->next;
	}
	circuit->rest = (circuit->total_edges + farm->ants) % circuit->size;
	circuit->score = ((circuit->total_edges + farm->ants) / circuit->size);
	ft_correct(farm, circuit);
	if (circuit->score < farm->score)
	{
		farm->score = circuit->score;
		free_circuits(farm->circuit);
		farm->circuit = circuit;
	}
	else
		free_circuits(circuit);
	return (0);
}
