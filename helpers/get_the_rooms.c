/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_the_rooms.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mesafi <mesafi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 09:04:05 by mesafi            #+#    #+#             */
/*   Updated: 2020/02/16 09:45:22 by mesafi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lem_in.h"

// int		ft_fill(char *line, t_rooms *element, int status)
// {
// 	char	*indicator;

// 	indicator = ft_strrchr(line, ' ');
// 	if (indicator == NULL || !ft_isdigit(*indicator))
// 		return (1);
// 	element->coord_y = ft_atoi(indicator);
// 	indicator = '\0';
// 	indicator = ft_strrchr(line, ' ');
// 	if (indicator == NULL || !ft_isdigit(*indicator))
// 		return (1);
// 	element->coord_x = ft_atoi(indicator);
// 	indicator = '\0';
// 	element->name = ft_strdup(line);
// 	return (0);
// }

int		get_the_rooms(t_lem_in *farm)
{
	// t_rooms		*element;
	// int			respond;
	// char		*line;

	// respond = 1;
	// while (respond && get_next_line(0, &line))
	// {
	// 	write(farm->fd, line, ft_strlen(line));
	// 	write(farm->fd, "\n", 1);
	// 	respond = check_if_comment(line);
	// 	if (respond == 3)
	// 	{
	// 		ft_memdel((void **)line);
	// 		continue ;
	// 	}
	// 	element = (t_rooms *)malloc(sizeof(t_rooms));
	// 	if ((respond = ft_fill(*line, element, respond)) == 1)
	// 		free(element);
	// 	else if (respond == 0)
	// 		return (0);
	// 		// push `var element` to ... (I don't know yet)
	// }
	(void)farm;
	return (0);
}
