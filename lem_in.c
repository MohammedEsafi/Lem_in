/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbareich <tbareich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 13:39:20 by mesafi            #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2020/03/04 18:54:21 by tbareich         ###   ########.fr       */
=======
/*   Updated: 2020/03/04 16:18:02 by mesafi           ###   ########.fr       */
>>>>>>> 327fb7ec33497fa39eecc7587940245e594b7e93
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static t_lem_in	*ft_init(void)
{
	t_lem_in	*farm;

	farm = (t_lem_in *)malloc(sizeof(t_lem_in));
	farm->best_score = MAX_INT;
	farm->best_circuit = -1;
	farm->ants = 0;
	farm->numerator = 0;
	farm->ants_arrived = 0;
	farm->rooms = NULL;
	farm->graph = NULL;
	farm->start = -1;
	farm->end = -1;
	init_array_list(&(farm->circuits));
	init_queue(&(farm->results));
	return (farm);
}

static void		ft_error_handler(t_lem_in *farm)
{
	ft_putstr("ERROR\n");
	free_queue(&(farm->results));
	ft_memdel((void **)&farm);
	exit(1);
}

int			main(void)
{
	t_lem_in	*farm;

	farm = ft_init();
	if (ft_reader(farm) == 1)
		ft_error_handler(farm);
	if (ft_finder(farm) == 1)
		ft_error_handler(farm);
	ft_print_results(farm);
	return (0);
}
