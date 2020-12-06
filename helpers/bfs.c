/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbareich <tbareich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 12:10:05 by tbareich          #+#    #+#             */
/*   Updated: 2020/12/06 11:28:32 by tbareich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lem_in.h"

static void		enqueue_nodes(t_edmonds_karp_params *params)
{
	enqueue(&(params->q), (int*)&(params->node)->key, sizeof(int));
	(params->visited)[(params->node)->key] = 1;
	(params->prev)[(params->node)->key] = (*(params->current));
}

static int		node_handler(t_lem_in *farm, char *seen, char *resid_capacity,
							t_edmonds_karp_params *params)
{
	if ((*(params->current)) != farm->start && seen[(*(params->current))])
	{
		if ((int)(params->node)->key != farm->start && (
		resid_capacity[(params->prev)[*(params->current)] * farm->graph->v +
		*(params->current)] == 2 ||
		resid_capacity[*(params->current) * farm->graph->v +
		(params->node)->key] == 2))
			enqueue_nodes(params);
	}
	else
		enqueue_nodes(params);
	return (0);
}

void			bfs(t_lem_in *farm, char *seen, char *resid_capacity,
							t_edmonds_karp_params *params)
{
	while ((params->q).size > 0)
	{
		(params->current) = (int *)dequeue(&(params->q));
		(params->node) = (farm->graph->adj_list)[*(params->current)].head;
		while ((params->node))
		{
			if ((params->visited)[(params->node)->key] == 0 &&
				resid_capacity[*(params->current)
				* farm->graph->v + (params->node)->key] != 0)
			{
				if ((int)(params->node)->key == farm->end)
					break ;
				node_handler(farm, seen, resid_capacity, params);
			}
			(params->node) = (params->node)->next;
		}
		if ((params->node) && (int)(params->node)->key == farm->end)
		{
			(params->prev)[(params->node)->key] = *(params->current);
			*(params->current) = (params->node)->key;
			break ;
		}
		ft_memdel((void**)&(params->current));
	}
}
