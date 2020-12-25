/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   edmonds_karp.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbareich <tbareich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 16:01:50 by tbareich          #+#    #+#             */
/*   Updated: 2020/12/06 13:26:53 by tbareich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lem_in.h"

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

int				edmonds_karp(t_lem_in *farm, char *seen, char *resid_capacity)
{
	t_edmonds_karp_params	params;

	if (edmonds_karp_init(&farm, &(params.prev), &(params.visited),
		&(params.q)))
		return (1);
	bfs(farm, seen, resid_capacity, &params);
	if (!(params.node) || (int)(params.node)->key != farm->end)
	{
		edmonds_karp_free(&(params.prev), &(params.current), &(params.visited),
						&(params.q));
		return (1);
	}
	while (TRUE)
	{
		resid_capacity[(*(params.current)) * farm->graph->v +
		(params.prev)[*(params.current)]] += 1;
		resid_capacity[(params.prev)[*(params.current)] * farm->graph->v +
		(*(params.current))] -= 1;
		(*(params.current)) = (params.prev)[*(params.current)];
		if ((*(params.current)) == farm->start)
			break ;
	}
	edmonds_karp_free(&(params.prev), &(params.current), &(params.visited),
					&(params.q));
	return (0);
}
