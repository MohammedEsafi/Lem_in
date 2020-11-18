/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbareich <tbareich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 12:10:05 by tbareich          #+#    #+#             */
/*   Updated: 2020/11/18 12:11:19 by tbareich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lem_in.h"

static int		node_seen(t_lem_in *farm, int current, int next,
					char *resid_capacity)
{
	t_node		*node;

	node = (farm->graph->adj_list)[next].head;
	while (node)
	{
		if ((int)node->key == farm->start)
		{
			node = node->next;
			continue ;
		}
		if ((resid_capacity[current * farm->graph->v + next] == 2 ||
			resid_capacity[next * farm->graph->v + node->key] == 2))
			return (1);
		node = node->next;
	}
	return (0);
}

static void		enqueue_nodes(t_edmonds_karp_params *params)
{
	enqueue(&(params->q), (int*)&(params->node)->key, sizeof(int));
	(params->visited)[(params->node)->key] = 1;
	(params->visited)[*(params->current)] = 1;
	(params->prev)[(params->node)->key] = (*(params->current));
}

static int		node_handler(t_lem_in *farm, char *seen, char *resid_capacity,
							t_edmonds_karp_params *params)
{
	if (seen[(params->node)->key] && node_seen(farm, *(params->current),
					(params->node)->key, resid_capacity) == 0)
	{
		(params->visited)[*(params->current)] = 1;
		(params->node) = (params->node)->next;
		return (1);
	}
	if (((*(params->current)) != farm->start && seen[(*(params->current))]))
	{
		if ((
		(resid_capacity[(params->prev)[*(params->current)] * farm->graph->v +
		*(params->current)] != 1 || resid_capacity[*(params->current) *
		farm->graph->v + (params->node)->key] != 1)))
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
				resid_capacity[(*(params->current))
				* farm->graph->v + (params->node)->key])
			{
				if (node_handler(farm, seen, resid_capacity, params))
					continue ;
				if ((int)(params->node)->key == farm->end)
					break ;
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
