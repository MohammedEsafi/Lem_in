/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbareich <tbareich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 13:39:20 by mesafi            #+#    #+#             */
/*   Updated: 2020/02/23 13:01:57 by tbareich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static t_lem_in	*ft_init(void)
{
	t_lem_in	*farm;

	farm = (t_lem_in *)malloc(sizeof(t_lem_in));
	farm->ants = 0;
	init_queue(&(farm->results));
	return (farm);
}

static void		ft_error_handler(t_lem_in *farm, int status)
{
	if (status == 0)
		ft_putstr("ERROR");
	free_queue(&(farm->results));
	free(farm);
	exit(1);
}

int			main(void)
{
	t_lem_in	*farm;

	farm = ft_init();
	if (ft_reader(farm) == 1)
		ft_error_handler(farm, 0);
	ft_print_results(&(farm->results));
	return (0);
}
