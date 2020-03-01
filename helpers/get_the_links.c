/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_the_links.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mesafi <mesafi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 19:02:28 by mesafi            #+#    #+#             */
/*   Updated: 2020/03/01 13:23:16 by mesafi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lem_in.h"

static int	find_room(void *elem1, void *elem2)
{
	return (ft_strcmp(elem1, ((t_room *)elem2)->name));
}

static int	ft_get_edge(t_lem_in *farm, char *line)
{
	char	*middle;
	t_avl	*room1;
	t_avl	*room2;
	int		index;

	if (!(middle = ft_strchr(line, '-')))
		return (1);
	*middle = '\0';
	++middle;
	if (!(room1 = avl_find_elem(farm->rooms, line, find_room)))
		return (1);
	if (!(room2 = avl_find_elem(farm->rooms, middle, find_room)))
		return (1);
	add_edge(farm->graph, ((t_room *)(room1->content))->key,
		((t_room *)(room2->content))->key);
	index = ((t_room *)(room1->content))->key;
	farm->graph->adj_list[index].content = room1->content;
	farm->graph->adj_list[index].content_size = room1->content_size;
	index = ((t_room *)(room2->content))->key;
	farm->graph->adj_list[index].content = room2->content;
	farm->graph->adj_list[index].content_size = room2->content_size;
	return (0);
}

int			get_the_links(char **line, t_lem_in *farm, int key)
{
	int		respond;

	respond = 1;
	if (!(farm->graph = create_graph(key)))
		return (1);
	while (*line != NULL && respond > 0)
	{
		enqueue(&(farm->results), *line, ft_strlen(*line) + 1);
		respond = !(check_if_comment(*line));
		if (respond != 0)
			respond = ft_get_edge(farm, *line);
		ft_memdel((void **)line);
		if (respond == 1)
			return (1);
		respond = get_next_line(0, line);
	}
	return (0);
}
