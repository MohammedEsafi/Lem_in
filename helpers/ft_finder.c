/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_finder.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbareich <tbareich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 10:09:49 by mesafi            #+#    #+#             */
/*   Updated: 2020/03/02 15:14:26 by tbareich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lem_in.h"

static void	ft_print_circuit(t_lem_in *farm)
{
	t_list	*node;
	t_list	*list;
	t_path	*path;

	node = farm->circuit.routes;
	ft_printf("\nsize: %u\n", farm->circuit.size);
	ft_printf("score: %u\n", farm->circuit.score);
	while (node != NULL)
	{
		path = (t_path *)(node->content);
		list = path->list;
		while (list)
		{
			ft_printf("%s -> ", ((t_room *)(farm->graph->
						adj_list[*((int *)(list->content))].content))->name);
			list = list->next;
		}
		ft_printf("\n");
		node = node->next;
	}
}

static int	is_validated(t_lem_in *farm)
{
	if (farm->start == -1 || farm->end == -1)
		return (1);
	return (0);
}

int			ft_finder(t_lem_in *farm)
{
	char	*resid_capacity;
	char	*seen;

	if (!(resid_capacity = (char *)malloc(farm->graph->v * farm->graph->v)))
		return (1);
	if (!(seen = (char *)malloc(farm->graph->v)))
	{
		ft_memdel((void **)&resid_capacity);
		return (1);
	}
	ft_memset(resid_capacity, 1, farm->graph->v * farm->graph->v);
	ft_memset(seen, 0, farm->graph->v);
	if (is_validated(farm) == 1)
		return (1);
	while (TRUE)
	{
		if (edmonds_karp(farm, seen, resid_capacity) == 1)
			break ;
		if (routes_maker(farm, seen, resid_capacity) == 1)
			break ;
		ft_print_circuit(farm);
	}
	return (!farm->circuit.size);
}
