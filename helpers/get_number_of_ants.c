/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_number_of_ants.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mesafi <mesafi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 09:01:23 by mesafi            #+#    #+#             */
/*   Updated: 2020/02/14 21:23:45 by mesafi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lem_in.h"

int		get_number_of_ants(t_lem_in *farm)
{
	char	*line;
	int		respond;

	while (get_next_line(0, &line))
	{
		write(farm->fd, line, ft_strlen(line));
		write(farm->fd, "\n", 1);
		respond = check_if_comment(line);
		if (respond == 0)
			farm->ants = ft_atoi(line);
		if (respond == 0 && !ft_is_number(line))
			respond = -1;
		ft_memdel((void **)&line);
		if (respond == -1)
			return (1);
		if (respond == 0)
			break ;
	}
	return (0);
}
