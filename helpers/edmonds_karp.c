/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   edmonds_karp.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbareich <tbareich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 16:01:50 by tbareich          #+#    #+#             */
/*   Updated: 2020/03/01 19:07:39 by tbareich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lem_in.h"

int		edmonds_karp(t_lem_in *farm, char *seen, char *resid_capacity)
{
	int			*prev;
	char		*visited;
	t_queue		q;
	int			current;
	t_node		*node;

	init_queue(&q);
	if (!(prev = (int *)malloc(sizeof(int) * farm->graph->v)))
		return (1);
	if (!(visited = (char *)malloc(farm->graph->v)))
	{
		ft_memdel((void**)&prev);
		return (1);
	}
	ft_memset(visited, 0, farm->graph->v);
	enqueue(&q, &farm->start, sizeof(int));
	visited[farm->start] = 1;
	while (q.size > 0)
	{
		current = *((int *)dequeue(&q));
		node = (farm->graph->adj_list)[current].head;
		while (node)
		{
			if (visited[node->key] == 0 &&
					(resid_capacity + current * farm->graph->v)[node->key])
			{
				if (seen[current] && current != farm->start)
				{
					if (resid_capacity[prev[current] * farm->graph->v + current]
					&& resid_capacity[current * farm->graph->v + prev[current]]
					&& resid_capacity[current * farm->graph->v + node->key]
					&& resid_capacity[node->key * farm->graph->v + current])
					{
						visited[current] = 0;
					}
					else
					{
						enqueue(&q, (int*)&node->key, sizeof(int));
						visited[node->key] = 1;
						prev[node->key] = current;
					}
				}
				else
				{
					enqueue(&q, (int*)&node->key, sizeof(int));
					visited[node->key] = 1;
					prev[node->key] = current;
				}
				if ((int)node->key == farm->end)
					break ;
			}
			node = node->next;
		}
		if (node && (int)node->key == farm->end)
			break ;
	}
	if (node && (int)node->key == farm->end)
	{
		prev[node->key] = current;
		current = node->key;
	}
	else
		return (1);
	while (current != farm->start)
	{
		if (resid_capacity[prev[current] * farm->graph->v + current] == resid_capacity[current * farm->graph->v + prev[current]])
		{
			resid_capacity[prev[current] * farm->graph->v + current] = 0;
			resid_capacity[current * farm->graph->v + prev[current]] = 1;
		}
		else
		{
			resid_capacity[prev[current] * farm->graph->v + current] = !resid_capacity[prev[current] * farm->graph->v + current] ;
			resid_capacity[current * farm->graph->v + prev[current]] = !resid_capacity[current * farm->graph->v + prev[current]];
		}
		current = prev[current];
	}
	return (0);
}
