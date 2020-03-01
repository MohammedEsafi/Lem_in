/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_finder.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbareich <tbareich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 10:09:49 by mesafi            #+#    #+#             */
/*   Updated: 2020/02/29 19:57:51 by tbareich         ###   ########.fr       */
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
	if (is_validated(farm) == 1)
		return (1);
	if (edmonds_karp(farm) == 1)
		return (1);
	return (0);
}
