/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reader.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbareich <tbareich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 14:07:38 by mesafi            #+#    #+#             */
/*   Updated: 2020/03/12 17:16:09 by tbareich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lem_in.h"

int			ft_reader(t_lem_in *farm)
{
	int		key;
	char	*line;

	key = 0;
	if (get_number_of_ants(&line, farm) == 1)
		return (1);
	if (get_the_rooms(&line, farm, &key) == 1)
		return (1);
	if (get_the_links(&line, farm, key) == 1)
		return (1);
	return (0);
}
