/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_finder.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mesafi <mesafi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 10:09:49 by mesafi            #+#    #+#             */
/*   Updated: 2020/03/05 14:30:17 by mesafi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lem_in.h"

static int	is_validated(t_lem_in *farm)
{
	if (farm->start == -1 || farm->end == -1)
		return (1);
	return (0);
}

int			ft_finder(t_lem_in *farm)
{
	char	*resid_capacity;
	char	*seen;

	if (!(resid_capacity = (char *)malloc(farm->graph->v * farm->graph->v)))
		return (1);
	if (!(seen = (char *)malloc(farm->graph->v)))
	{
		ft_memdel((void **)&resid_capacity);
		return (1);
	}
	ft_memset(resid_capacity, 1, farm->graph->v * farm->graph->v);
	ft_memset(seen, 0, farm->graph->v);
	if (is_validated(farm) == 1)
		return (1);
	while (TRUE)
	{
		if (edmonds_karp(farm, seen, resid_capacity) == 1)
			break ;
		if (routes_maker(farm, seen, resid_capacity) == 1)
			break ;
	}
	// ft_mmedel((void **)&resid_capacity);
	// ft_mmedel((void **)&seen);
	return (farm->circuit == NULL);
}
