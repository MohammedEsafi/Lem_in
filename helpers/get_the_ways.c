/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_the_ways.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbareich <tbareich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 08:27:23 by mesafi            #+#    #+#             */
/*   Updated: 2020/12/06 10:39:37 by tbareich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lem_in.h"

static int	ft_filler(int **prev, char **visited, int vertices)
{
	if (!(*prev = (int *)malloc(sizeof(int) * vertices)))
		return (-1);
	if (!(*visited = (char *)malloc(vertices)))
	{
		ft_memdel((void **)prev);
		return (-1);
	}
	ft_memset(*visited, 0, vertices);
	return (0);
}

static int	loophole(t_lem_in *farm, t_queue *q, char *visited, int *prev)
{
	t_node		*node;
	int			*current;

	current = (int *)dequeue(q);
	node = farm->graph->adj_list[*current].head;
	while (node != NULL)
	{
		if (farm->capacity[*current * farm->graph->v + node->key] == 0
			&& visited[node->key] == 0)
		{
			prev[node->key] = *current;
			if (node->key == (unsigned)farm->end)
			{
				ft_memdel((void **)&current);
				return (1);
			}
			enqueue(q, &node->key, sizeof(int));
			visited[node->key] = 1;
		}
		node = node->next;
	}
	ft_memdel((void **)&current);
	return (0);
}

int			get_the_ways(t_lem_in *farm,
						unsigned *total_edges, t_circuit *circuit)
{
	int			*prev;
	char		*visited;
	t_queue		q;

	init_queue(&q);
	if (ft_filler(&prev, &visited, farm->graph->v) == -1)
		return (-1);
	enqueue(&q, &farm->start, sizeof(int));
	visited[farm->start] = 1;
	while (q.size != 0)
	{
		if (loophole(farm, &q, visited, prev))
			get_the_route(farm, total_edges, prev, circuit);
	}
	free_queue(&q);
	ft_memdel((void **)&prev);
	ft_memdel((void **)&visited);
	return (0);
}
