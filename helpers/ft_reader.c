/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reader.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mesafi <mesafi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 14:07:38 by mesafi            #+#    #+#             */
/*   Updated: 2020/02/17 09:14:48 by mesafi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lem_in.h"

int			ft_reader(t_lem_in *farm)
{
	if (get_number_of_ants(farm) == 1)
		return (1);
	if (get_the_rooms(farm) == 1)
		return (1);
	// get_the_links
	return (0);
}
