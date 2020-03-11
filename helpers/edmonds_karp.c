/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   edmonds_karp.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbareich <tbareich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 16:01:50 by tbareich          #+#    #+#             */
/*   Updated: 2020/03/11 16:10:23 by tbareich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lem_in.h"

int		node_seen(t_lem_in *farm, int current, int next,
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

int		edmonds_karp(t_lem_in *farm, char *seen, char *resid_capacity)
{
	int			*prev;
	char		*visited;
	t_queue		q;
	int			*current;
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
		current = (int *)dequeue(&q);
		node = (farm->graph->adj_list)[*current].head;
		while (node)
		{
			if (visited[node->key] == 0 &&
					resid_capacity[(*current) * farm->graph->v + node->key])
			{
				if (seen[node->key] &&
					node_seen(farm, *current, node->key, resid_capacity) == 0)
				{
					visited[*current] = 1;
					node = node->next;
					continue ;
				}
				if ((*current) != farm->start && seen[(*current)])
				{
					if (
				resid_capacity[prev[*current] * farm->graph->v + *current] != 1
				|| resid_capacity[*current * farm->graph->v + node->key] != 1)
					{
						enqueue(&q, (int*)&node->key, sizeof(int));
						visited[node->key] = 1;
						visited[*current] = 1;
						prev[node->key] = (*current);
					}
				}
				else
				{
					enqueue(&q, (int*)&node->key, sizeof(int));
					visited[node->key] = 1;
					visited[*current] = 1;
					prev[node->key] = (*current);
				}
				if ((int)node->key == farm->end)
					break ;
			}
			node = node->next;
		}
		if (node && (int)node->key == farm->end)
		{
			prev[node->key] = *current;
			*current = node->key;
			break ;
		}
		ft_memdel((void**)&current);
	}
	if (!node || (int)node->key != farm->end)
	{
		ft_memdel((void **)&current);
		ft_memdel((void **)&prev);
		ft_memdel((void **)&visited);
		free_queue(&q);
		return (1);
	}
	while ((*current) != farm->start)
	{
		resid_capacity[(*current) * farm->graph->v + prev[*current]] += 1;
		resid_capacity[prev[*current] * farm->graph->v + (*current)] -= 1;
		(*current) = prev[*current];
	}
	ft_memdel((void **)&current);
	ft_memdel((void **)&prev);
	ft_memdel((void **)&visited);
	free_queue(&q);
	return (0);
}
