/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_the_links.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mesafi <mesafi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 19:02:28 by mesafi            #+#    #+#             */
/*   Updated: 2020/02/26 11:51:15 by mesafi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lem_in.h"

static int	ft_get_edge(t_lem_in *farm, char *line)
{
	char	*middle;

	if (!(middle = ft_strchr(line, '-')))
		return (1);
	*middle++ = '\0';
	// printf("1-> %s\n", line);
	// printf("2-> %s\n", middle);
	(void)farm;
	return (0);
}

int			get_the_links(t_lem_in *farm, int key)
{
	char	*line;
	int		respond;

	if (!(farm->graph = create_graph(key)))
		return (1);
	while (get_next_line(0, &line))
	{
		enqueue(&(farm->results), ft_lstnew(line, ft_strlen(line) + 1));
		respond = !(check_if_comment(line));
		if (respond != 0)
			respond = ft_get_edge(farm, line);
		ft_memdel((void **)&line);
		if (respond == 1)
			return (1);
	}
	return (0);
}
