/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_the_rooms.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbareich <tbareich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 09:04:05 by mesafi            #+#    #+#             */
/*   Updated: 2020/03/12 19:26:13 by tbareich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lem_in.h"

static int		rooms_cmp(void *elem1, void *elem2)
{
	return (ft_strcmp(((t_room *)elem1)->name, ((t_room *)elem2)->name));
}

static int		ft_fill(char *line, t_room *element, int *key)
{
	char	*indicator;

	indicator = ft_strrchr(line, ' ');
	if (indicator == NULL || !ft_is_number(indicator + 1))
		return (-1);
	element->coord_y = ft_atoi(indicator);
	*indicator = '\0';
	indicator = ft_strrchr(line, ' ');
	if (indicator == NULL || !ft_is_number(indicator + 1))
		return (-1);
	element->coord_x = ft_atoi(indicator);
	*indicator = '\0';
	if (*line == 'L')
		return (1);
	element->name = ft_strdup(line);
	element->key = *key;
	element->ant = -1;
	++(*key);
	return (0);
}

int				line_omit(char **line)
{
	ft_memdel((void **)line);
	return (1);
}

void			data_structuring(t_lem_in *farm, int key, int status,
					t_room *element)
{
	fill_start_end(farm, status, key - 1);
	farm->rooms = avl_insert_elem(farm->rooms, element, sizeof(t_room),
		rooms_cmp);
}

int				get_the_rooms(char **line, t_lem_in *farm, int *key)
{
	t_room		*element;
	int			respond;
	int			status;

	respond = 0;
	while (respond != -1 && get_next_line(0, line))
	{
		enqueue(&(farm->results), *line, ft_strlen(*line) + 1);
		status = respond;
		respond = check_if_comment(farm, *line);
		if ((respond > 0 && respond < 4) && line_omit(line))
			continue ;
		if (!(element = (t_room *)malloc(sizeof(t_room))) && line_omit(line))
			return (1);
		if ((respond = ft_fill(*line, element, key)) == -1)
			ft_memdel((void **)&element);
		else if (respond == 0)
			data_structuring(farm, *key, status, element);
		if (respond != -1)
			ft_memdel((void **)line);
		if (respond == 1)
			return (1);
	}
	return (0);
}
