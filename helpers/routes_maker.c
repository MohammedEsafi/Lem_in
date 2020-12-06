/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routes_maker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbareich <tbareich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/01 13:04:09 by tbareich          #+#    #+#             */
/*   Updated: 2020/12/06 12:52:52 by tbareich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lem_in.h"

static t_list		*negative_case(t_lem_in *farm, t_circuit *circuit,
						t_path *path, int *i)
{
	circuit->total_edges -= path->size;
	circuit->size -= 1;
	circuit->rest = (circuit->total_edges + farm->ants) % circuit->size;
	circuit->score = (circuit->total_edges + farm->ants) /
						circuit->size;
	ft_lstdelat(&(circuit->routes), *i);
	*i = -1;
	return (circuit->routes);
}

static void			ft_circuit_score(t_lem_in *farm, t_circuit *circuit)
{
	t_list		*node;
	t_path		*path;
	int			i;

	node = circuit->routes;
	i = -1;
	circuit->rest = (circuit->total_edges + farm->ants) % circuit->size;
	circuit->score = ((circuit->total_edges + farm->ants) / circuit->size);
	while (node != NULL)
	{
		++i;
		path = (t_path *)(node->content);
		path->ants = circuit->score - path->size;
		if (path->ants <= 0)
		{
			node = negative_case(farm, circuit, path, &i);
			continue ;
		}
		path->ants += (circuit->rest-- > 0);
		path->remnant = path->ants;
		node = node->next;
	}
	circuit->rest = (circuit->total_edges + farm->ants) % circuit->size;
	circuit->score = (circuit->total_edges + farm->ants) /
						circuit->size - (circuit->rest == 0);
}

static void			ft_switcher(t_lem_in *farm, t_circuit *circuit)
{
	farm->score = circuit->score;
	free_circuit(farm->circuit);
	farm->circuit = circuit;
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

int					routes_maker(t_lem_in *farm)
{
	t_node		*node;
	t_circuit	*circuit;

	node = farm->graph->adj_list[farm->start].head;
	if (!(circuit = init_circuit()))
		return (1);
	get_the_ways(farm, &(circuit->total_edges), circuit);
	ft_circuit_score(farm, circuit);
	if (circuit->score < farm->score)
		ft_switcher(farm, circuit);
	else
		free_circuit(circuit);
	return (0);
}
