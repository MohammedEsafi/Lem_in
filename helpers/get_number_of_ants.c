/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_number_of_ants.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mesafi <mesafi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 09:01:23 by mesafi            #+#    #+#             */
/*   Updated: 2020/02/26 15:02:16 by mesafi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lem_in.h"

int		get_number_of_ants(char **line, t_lem_in *farm)
{
	int		respond;

	while (get_next_line(0, line))
	{
		enqueue(&(farm->results), ft_lstnew(*line, ft_strlen(*line) + 1));
		respond = check_if_comment(*line);
		if (respond == 0 && !ft_is_number(*line))
			respond = -1;
		else if (respond == 0)
			farm->ants = ft_atoi(*line);
		ft_memdel((void **)line);
		if (respond == -1)
			return (1);
		if (respond == 0)
			break ;
	}
	return (!(farm->ants));
}
