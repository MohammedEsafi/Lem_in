/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_finder.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mesafi <mesafi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 10:09:49 by mesafi            #+#    #+#             */
/*   Updated: 2020/03/05 13:27:11 by mesafi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lem_in.h"

// static void	ft_print_circuit(t_lem_in *farm)
// {
// 	t_list	*node;
// 	t_list	*list;
// 	t_path	*path;
// 	int		i;

// 	i = -1;
// 	ft_printf("BEST_GROUP_INDEX : %d\n", farm->best_circuit);
// 	ft_printf("BEST_SCORE : %d\n\n", farm->best_score);
// 	while (++i <= farm->circuits.cursor)
// 	{
// 		node = ((t_circuit *)(farm->circuits.list[i]))->routes;
// 		ft_printf("score : %d\n", ((t_circuit *)(farm->circuits.list[i]))->score);
// 		ft_printf("total edges : %d\n", ((t_circuit *)(farm->circuits.list[i]))->total_edges);
// 		ft_printf("number of paths : %d\n", ((t_circuit *)(farm->circuits.list[i]))->size);
// 		while (node != NULL)
// 		{
// 			path = (t_path *)(node->content);
// 			list = path->list;
// 			ft_printf(">> %d", path->ants);
// 			// ft_printf("   path size : %d", path->size);
// 			// while (list)
// 			// {
// 			// 	ft_printf("%s > ", ((t_room *)(farm->graph->
// 			// 				adj_list[*((int *)(list->content))].content))->name);
// 			// 	list = list->next;
// 			// }
// 			ft_printf("\n");
// 			node = node->next;
// 		}
// 		ft_printf("\n");
// 	}
// }

// static void	ft_print_circuit(t_lem_in *farm)
// {
// 	t_list	*node;
// 	t_list	*list;
// 	t_path	*path;
// 	int		rest;

// 	node = ((t_circuit *)(farm->circuits.list[farm->best_circuit]))->routes;
// 	rest = ((t_circuit *)(farm->circuits.list[farm->best_circuit]))->rest;
// 	// ft_printf("REST : %d\n", ((((t_circuit *)(farm->circuits.list[farm->best_circuit]))->total_edges + farm->ants) % ((t_circuit *)(farm->circuits.list[farm->best_circuit]))->size));
// 	ft_printf("Best Circuit : %d\n", farm->best_circuit);
// 	ft_printf("Best Score : %d\n", farm->best_score);
// 	ft_printf("Total Edges : %d\n", ((t_circuit *)(farm->circuits.list[farm->best_circuit]))->total_edges);
// 	// ft_printf("\nsize: %u\n", farm->circuit.size);
// 	// ft_printf("score: %u\n", farm->circuit.score);
// 	while (node != NULL)
// 	{
// 		path = (t_path *)(node->content);
// 		list = path->list;
// 		ft_printf("%d <<< ", ((t_circuit *)(farm->circuits.list[farm->best_circuit]))->score
// 		 - path->size + (rest-- > 0));
// 		// while (list)
// 		// {
// 		// 	ft_printf("%s -> ", ((t_room *)(farm->graph->
// 		// 				adj_list[*((int *)(list->content))].content))->name);
// 		// 	list = list->next;
// 		// }
// 		ft_printf("\n");
// 		node = node->next;
// 	}
// }

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
	}
	// ft_print_circuit(farm);
	return (farm->circuits.cursor == -1);
}
