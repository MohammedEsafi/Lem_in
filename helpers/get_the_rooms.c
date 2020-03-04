/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_the_rooms.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mesafi <mesafi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 09:04:05 by mesafi            #+#    #+#             */
/*   Updated: 2020/03/04 00:02:40 by mesafi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lem_in.h"

static void		fill_start_end(t_lem_in *farm, int status, int key)
{
	if (status == 1)
		farm->start = key;
	else if (status == 2)
		farm->end = key;
}

static int		rooms_cmp(void *elem1, void *elem2)
{
	return (ft_strcmp(((t_room *)elem1)->name, ((t_room *)elem2)->name));
}

static int		ft_fill(char *line, t_room *element, int status, int *key)
{
	char	*indicator;

	(void)status;
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
		respond = check_if_comment(*line);
		if (respond > 0 && respond < 4)
		{
			ft_memdel((void **)line);
			continue ;
		}
		if (!(element = (t_room *)malloc(sizeof(t_room))))
		{
			ft_memdel((void **)*line);
			return (1);
		}
		if ((respond = ft_fill(*line, element, status, key)) == -1)
			ft_memdel((void **)&element);
		else if (respond == 0)
		{
			fill_start_end(farm, status, *key - 1);
			farm->rooms = avl_insert_elem(farm->rooms, element, sizeof(t_room),
				rooms_cmp);
		}
		if (respond != -1)
			ft_memdel((void **)line);
		if (respond == 1)
			return (1);
	}
	return (0);
}
