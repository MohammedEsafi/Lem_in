/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_edge.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbareich <tbareich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 19:43:06 by tbareich          #+#    #+#             */
/*   Updated: 2020/02/18 19:43:07 by tbareich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graph.h"
#include <stdlib.h>

static t_node	*new_node(unsigned int key)
{
	t_node		*node;

	if ((node = (t_node *)malloc(sizeof(t_node))) == 0)
		return (0);
	node->key = key;
	node->next = NULL;
	return (node);
}

int				add_edge(t_graph *graph, unsigned int src, unsigned int dest)
{
	t_node	*node;

	if ((node = new_node(dest)) == 0)
		return (-1);
	node->next = graph->adj_list[src].head;
	graph->adj_list[src].head = node;
	if ((node = new_node(src)) == 0)
	{
		ft_memdel((void **)&node);
		return (-1);
	}
	node->next = graph->adj_list[dest].head;
	graph->adj_list[dest].head = node;
	return (0);
}
