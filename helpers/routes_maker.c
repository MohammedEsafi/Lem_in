/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routes_maker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbareich <tbareich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/01 13:04:09 by tbareich          #+#    #+#             */
/*   Updated: 2020/03/02 17:17:40 by tbareich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lem_in.h"

static int		correct_score(t_lem_in *farm)
{
	t_list		*node;
	t_path		*path;
	unsigned	score;

	score = 0;
	node = farm->tmp_circuit.routes;
	while (node != NULL)
	{
		path = (t_path *)(node->content);
		ft_printf("<< %d\n", path->ants);
		if ((int)path->ants + path->size - 1 > score)
			score = path->ants + path->size - 1;
		node = node->next;
	}
	return (score);
}

static int		ft_split_ants(t_lem_in *farm, int rest)
{
	t_list		*node;
	t_path		*path;
	// int			score;

	// ft_printf("rest: %d\n", rest);
	node = farm->tmp_circuit.routes;
	while (node != NULL)
	{
		path = (t_path *)(node->content);
		if (rest < 0)
			path->ants = farm->tmp_circuit.score - path->size - 1;
		else if (rest > 0)
			path->ants = farm->tmp_circuit.score - path->size + 1;
		else
			path->ants = farm->tmp_circuit.score - path->size;
		if (rest > 0)
			--rest;
		else if (rest < 0)
			++rest;
		if (path->ants < 0)
		{
			rest += path->ants;
			path->ants = 0;
		}
		node = node->next;
	}
	node = farm->tmp_circuit.routes;
	while (node != NULL)
	{
		path = (t_path *)(node->content);
		if (rest > 0)
			path->ants += 1;
		else if (rest < 0)
			path->ants -= 1;
		if (rest > 0)
			--rest;
		else if (rest < 0)
			++rest;
		if (path->ants < 0)
		{
			rest += path->ants;
			path->ants = 0;
		}
		// ft_printf("Ants: %d\n", path->ants);
		node = node->next;
		if (node == NULL && rest != 0)
			node = farm->tmp_circuit.routes;
	}
	ft_printf("01: %d\n", farm->tmp_circuit.score);
	return (correct_score(farm));
}

static t_list	*get_the_way(t_lem_in *farm, char *resid_capacity,
					int onset, unsigned *all_edges, char *seen)
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
	*all_edges += path->size;
	return (ft_lstnew(path, sizeof(t_path)));
}

int				routes_maker(t_lem_in *farm, char *seen, char *resid_capacity)
{
	t_node		*node;
	t_list		*routes;
	unsigned	all_edges;

	node = farm->graph->adj_list[farm->end].head;
	farm->tmp_circuit.size = 0;
	farm->tmp_circuit.routes = NULL;
	all_edges = 0;
	routes = NULL;
	while (node != NULL)
	{
		if (resid_capacity[node->key * farm->graph->v + farm->end] == 0)
		{
			ft_lstadd(&(farm->tmp_circuit.routes), get_the_way(farm, resid_capacity,
					(int)node->key, &all_edges, seen));
			farm->tmp_circuit.size += 1;
		}
		node = node->next;
	}
	if (!farm->tmp_circuit.size)
		return (1);
	farm->tmp_circuit.score = ((all_edges + farm->ants) / farm->tmp_circuit.size);
	ft_printf("00: %d\n", farm->tmp_circuit.score);
	farm->tmp_circuit.score = ft_split_ants(farm, (all_edges + farm->ants) % farm->tmp_circuit.size);
	ft_printf("02: %d\n", farm->tmp_circuit.score);
	if (farm->tmp_circuit.score <= farm->circuit.score)
	{
		farm->circuit.routes = farm->tmp_circuit.routes;
		farm->circuit.score = farm->tmp_circuit.score;
		farm->circuit.size = farm->tmp_circuit.size;
		// farm->circuit.score = correct_score(farm);
	}
	return (0);
}
