/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graph.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mesafi <mesafi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 19:42:26 by tbareich          #+#    #+#             */
/*   Updated: 2020/02/26 14:43:26 by mesafi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GRAPH_H
# define GRAPH_H

/*
 ** Includes
*/

# include "../libft.h"

/*
 ** Structures
*/

typedef struct	s_graph
{
	unsigned		v;
	struct s_vertex	*adj_list;
}				t_graph;

typedef struct	s_node
{
	unsigned		key;
	struct s_node	*next;
}				t_node;

typedef struct	s_vertex
{
	void		*content;
	size_t		content_size;
	t_node		*head;
}				t_vertex;

/*
 ** Graph Functions
*/

t_graph			*create_graph(unsigned v);
int				add_edge(t_graph *graph, unsigned int src, unsigned int dest);
void			print_graph(t_graph *graph);

#endif
