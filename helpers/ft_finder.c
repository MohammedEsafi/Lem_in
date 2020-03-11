/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_finder.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbareich <tbareich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 10:09:49 by mesafi            #+#    #+#             */
/*   Updated: 2020/03/11 20:36:55 by tbareich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lem_in.h"

static int	is_validated(t_lem_in *farm)
{
	if (farm->start == -1 || farm->end == -1)
		return (1);
	if (farm->start == farm->end)
		return (1);
	return (0);
}

int			ft_finder(t_lem_in *farm)
{
	if (!(farm->capacity = (char *)malloc(farm->graph->v * farm->graph->v)))
		return (1);
	if (!(farm->seen = (char *)malloc(farm->graph->v)))
		return (1);
	ft_memset(farm->capacity, 1, farm->graph->v * farm->graph->v);
	ft_memset(farm->seen, 0, farm->graph->v);
	if (is_validated(farm) == 1)
		return (1);
	while (TRUE)
	{
		if (edmonds_karp(farm, farm->seen, farm->capacity) == 1)
			break ;
		if (routes_maker(farm) == 1)
			break ;
	}
	return (farm->circuit == NULL);
}
