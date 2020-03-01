/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbareich <tbareich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 13:40:03 by mesafi            #+#    #+#             */
/*   Updated: 2020/03/01 14:32:32 by tbareich         ###   ########.fr       */
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
# include "avl/avl.h"
# include <stdio.h>

/*
 ** Structures
*/

typedef struct	s_path
{
	unsigned	size;
	t_list		*list;
}				t_path;

typedef struct	s_circuit
{
	unsigned	score;
	unsigned	size;
	t_path		*routes;
}				t_circuit;

typedef struct	s_rooms
{
	char	*name;
	int		key;
	int		coord_x;
	int		coord_y;
}				t_rooms;

typedef struct	s_lem_in
{
	unsigned int	ants;
	t_avl			*rooms;
	t_graph			*graph;
	int				start;
	int				end;
	t_queue			results;
	t_circuit		circuit;
}				t_lem_in;

/*
 ** Lem-in Functions
*/

int				ft_reader(t_lem_in *farm);
int				check_if_comment(char *line);
int				get_number_of_ants(char **line, t_lem_in *farm);
int				get_the_rooms(char **line, t_lem_in *farm, int *key);
void			ft_print_results(t_queue *results);
int				get_the_links(char **line, t_lem_in *farm, int key);
int				ft_finder(t_lem_in *farm);
int				edmonds_karp(t_lem_in *farm, char *seen,
					char *resid_capacity);
int				routes_maker(t_lem_in *farm, char *resid_capacity);

#endif
