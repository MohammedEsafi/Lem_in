/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbareich <tbareich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 13:39:20 by mesafi            #+#    #+#             */
/*   Updated: 2020/11/07 19:00:11 by tbareich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_lem_in		*ft_init(void)
{
	t_lem_in	*farm;

	farm = (t_lem_in *)malloc(sizeof(t_lem_in));
	farm->score = MAX_INT;
	farm->ants = 0;
	farm->numerator = 0;
	farm->seen = NULL;
	farm->capacity = NULL;
	farm->options = 0;
	farm->circuit = NULL;
	farm->rooms = NULL;
	farm->graph = NULL;
	farm->required_iter = -1;
	farm->start = -1;
	farm->end = -1;
	init_queue(&(farm->results));
	return (farm);
}

void			ft_free(t_lem_in *farm)
{
	free_queue(&(farm->results));
	free_circuit(farm->circuit);
	if (farm->seen != NULL)
		ft_memdel((void **)&(farm->seen));
	if (farm->capacity != NULL)
		ft_memdel((void **)&(farm->capacity));
	ft_memdel((void **)&farm);
}

void			ft_error_handler(t_lem_in *farm)
{
	ft_putstr("ERROR\n");
	ft_free(farm);
	exit(1);
}

int				main(int ac, char **av)
{
	t_lem_in	*farm;

	farm = ft_init();
	if (ac > 1)
		usage(farm, ac, av);
	if (ft_reader(farm) == 1)
		ft_error_handler(farm);
	if (ft_finder(farm) == 1)
		ft_error_handler(farm);
	if ((farm->options & 1) || (farm->options & 2))
		print_circuit(farm);
	else
		ft_print_results(farm);
	ft_free(farm);
	return (0);
}
