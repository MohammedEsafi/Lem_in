/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mesafi <mesafi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 13:40:03 by mesafi            #+#    #+#             */
/*   Updated: 2020/02/14 21:25:17 by mesafi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H

/*
 ** Definitions
*/

# define LEM_IN_H

/*
 ** Includes
*/

# include "libft/libft.h"
# include "libft/graph/graph.h"
# include "libft/array_list/array_list.h"
# include <stdio.h>

/*
 ** Structures
*/

typedef struct	s_rooms
{
	char	*name;
	int		coord_x;
	int		coord_y;
}				t_rooms;

typedef struct	s_lem_in
{
	int				fd;
	unsigned int	ants;
	void			*rooms;
	t_graph			*graph;
	void			*start;
	void			*end;
}				t_lem_in;

/*
 ** Lem-in Functions
*/

int				ft_reader(t_lem_in *farm);
int				check_if_comment(char *line);
int				get_number_of_ants(t_lem_in *farm);
int				get_the_rooms(t_lem_in *farm);

#endif
