/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_graph.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbareich <tbareich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 12:03:03 by mesafi            #+#    #+#             */
/*   Updated: 2020/02/26 14:32:33 by tbareich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graph.h"
#include <stdlib.h>

t_graph		*create_graph(unsigned int vertices)
{
	t_graph			*graph;
	unsigned int	i;

	if (!(graph = (t_graph *)malloc(sizeof(t_graph))))
		return (NULL);
	graph->num_vertices = vertices;
	if (!(graph->lists = (t_node **)malloc(sizeof(t_node *) * vertices)))
		return (NULL);
	i = 0;
	while (i < vertices)
	{
		graph->lists[i] = NULL;
		++i;
	}
	return (graph);
}
