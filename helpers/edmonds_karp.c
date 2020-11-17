/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   edmonds_karp.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbareich <tbareich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 16:01:50 by tbareich          #+#    #+#             */
/*   Updated: 2020/11/17 20:25:06 by tbareich         ###   ########.fr       */
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

static int		edmonds_karp_init(t_lem_in **farm, int **prev, char **visited,
							t_queue *q)
{
	init_queue(q);
	if (!(*prev = (int *)malloc(sizeof(int) * (*farm)->graph->v)))
		return (1);
	if (!(*visited = (char *)malloc((*farm)->graph->v)))
	{
		ft_memdel((void**)prev);
		return (1);
	}
	ft_memset(*visited, 0, (*farm)->graph->v);
	enqueue(q, &(*farm)->start, sizeof(int));
	(*visited)[(*farm)->start] = 1;
	return (0);
}

static void		edmonds_karp_free(int **prev, int **current, char **visited,
						t_queue *q)
{
	ft_memdel((void **)current);
	ft_memdel((void **)prev);
	ft_memdel((void **)visited);
	free_queue(q);
}

static void		enqueue_node(t_edmonds_karp *params)
{
	enqueue(&(params->q), (int*)&(params->node)->key, sizeof(int));
	(params->visited)[(params->node)->key] = 1;
	(params->visited)[*(params->current)] = 1;
	(params->prev)[(params->node)->key] = (*(params->current));
}

static int		node_handler(t_lem_in *farm, char *seen, char *resid_capacity,
							t_edmonds_karp *params)
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
			enqueue_node(params);
	}
	else
		enqueue_node(params);
	return (0);
}

static void		iterate_queue(t_lem_in *farm, char *seen, char *resid_capacity,
							t_edmonds_karp *params)
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

int				edmonds_karp(t_lem_in *farm, char *seen, char *resid_capacity)
{
	t_edmonds_karp	p;

	if (edmonds_karp_init(&farm, &(p.prev), &(p.visited), &(p.q)))
		return (1);
	iterate_queue(farm, seen, resid_capacity, &p);
	if (!(p.node) || (int)(p.node)->key != farm->end)
	{
		edmonds_karp_free(&(p.prev), &(p.current), &(p.visited), &(p.q));
		return (1);
	}
	while ((*(p.current)) != farm->start)
	{
		resid_capacity[(*(p.current)) * farm->graph->v +
		(p.prev)[*(p.current)]] += 1;
		resid_capacity[(p.prev)[*(p.current)] * farm->graph->v +
		(*(p.current))] -= 1;
		(*(p.current)) = (p.prev)[*(p.current)];
	}
	edmonds_karp_free(&(p.prev), &(p.current), &(p.visited), &(p.q));
	return (0);
}
