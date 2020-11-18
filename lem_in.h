/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbareich <tbareich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 13:40:03 by mesafi            #+#    #+#             */
/*   Updated: 2020/11/17 19:23:11 by tbareich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H

/*
 ** Definitions
*/

# define LEM_IN_H

# define TRUE 1
# define FALSE 0

/*
 ** Includes
*/

# include "libft/libft.h"
# include "libft/graph/graph.h"
# include "libft/ft_printf/ft_printf.h"
# include "libft/queue/queue.h"
# include "libft/array_list/array_list.h"
# include "avl/avl.h"
# include <stdio.h>

/*
 ** Structures
*/

typedef struct	s_path
{
	int			ants;
	int			remnant;
	unsigned	size;
	t_list		*list;
}				t_path;

typedef struct	s_circuit
{
	unsigned	score;
	unsigned	total_edges;
	unsigned	size;
	int			rest;
	t_list		*routes;
}				t_circuit;

typedef struct	s_room
{
	char		*name;
	int			ant;
	int			key;
	int			coord_x;
	int			coord_y;
}				t_room;

typedef struct	s_lem_in
{
	unsigned		ants;
	unsigned		numerator;
	t_avl			*rooms;
	t_graph			*graph;
	char			*seen;
	char			*capacity;
	int				start;
	int				end;
	t_queue			results;
	unsigned		score;
	int				required_iter;
	t_circuit		*circuit;
	char			options;
}				t_lem_in;

typedef struct	s_edmonds_karp
{
	int			*prev;
	char		*visited;
	t_queue		q;
	int			*current;
	t_node		*node;
}				t_edmonds_karp;

/*
 ** Lem-in Functions
*/

int				ft_reader(t_lem_in *farm);
int				check_if_comment(t_lem_in *farm, char *line);
int				get_number_of_ants(char **line, t_lem_in *farm);
int				get_the_rooms(char **line, t_lem_in *farm, int *key);
void			ft_print_results(t_lem_in *farm);
int				get_the_links(char **line, t_lem_in *farm, int key);
int				ft_finder(t_lem_in *farm);
int				edmonds_karp(t_lem_in *farm, char *seen,
					char *resid_capacity);
int				routes_maker(t_lem_in *farm);
void			free_circuit(t_circuit *circuit);
void			ft_error_handler(t_lem_in *farm);
void			print_circuit(t_lem_in *farm);
void			usage(t_lem_in *farm, int ac, char **av);
void			fill_start_end(t_lem_in *farm, int status, int key);
int				get_the_route(t_lem_in *farm, unsigned *total_edges,
					int prev[farm->graph->v], t_circuit *circuit);
int				get_the_ways(t_lem_in *farm, unsigned *total_edges,
					t_circuit *circuit);

#endif
