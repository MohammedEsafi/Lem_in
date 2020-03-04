/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_results.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbareich <tbareich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/16 10:05:41 by mesafi            #+#    #+#             */
/*   Updated: 2020/03/04 21:40:34 by tbareich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lem_in.h"

static int		ft_out(t_lem_in *farm, t_path *path)
{
	if (path->ants == 0)
		return (-1);
	path->ants -= 1;
	return (++(farm->numerator));
}

static void		ft_move(t_lem_in *farm, t_path *path, int from, int to)
{
	int		no_of_ant;
	char	*room;

	if (from == farm->start)
		no_of_ant = ft_out(farm, path);
	else
	{
		no_of_ant = ((t_room *)(farm->graph->adj_list[from].content))->ant;
		((t_room *)(farm->graph->adj_list[from].content))->ant = -1;
	}
	if (no_of_ant != -1)
	{
		if (to == farm->end)
			path->remnant -= 1;
		room = ((t_room *)(farm->graph->adj_list[to].content))->name;
		((t_room *)(farm->graph->adj_list[to].content))->ant = no_of_ant;
		ft_printf("L%d-%s ", no_of_ant, room);
	}
}

static t_list	*ft_goto(t_list *node, t_list *head, int *index)
{
	if (node->next == NULL)
	{
		*index = 0;
		if (node->next == NULL)
			ft_printf("\n");
		return (head);
	}
	else
	{
		*index += 1;
		return (node->next);
	}
}

static void		ants_trajects_printer(t_lem_in *farm)
{
	t_circuit	*circuit;
	t_list		*node;
	t_list		*room;
	t_path		*path;
	int			i;

	circuit = (t_circuit *)(farm->circuits.list[farm->best_circuit]);
	node = circuit->routes;
	i = 0;
	while (node != NULL)
	{
		path = (t_path *)(node->content);
		room = path->list;
		while (*((int *)(room->content)) != farm->start)
		{
			ft_move(farm, path, *((int *)(room->next->content)), *((int *)(room->content)));
			room = room->next;
		}
		if (path->remnant == 0)
		{
			ft_lstdelat(&(circuit->routes), i);
			--i;
		}
		node = ft_goto(node, circuit->routes, &i);
	}
}

void			ft_print_results(t_lem_in *farm)
{
	void		*content;
	t_queue		*results;

	results = &(farm->results);
	while (results->size != 0)
	{
		content = dequeue(results);
		ft_printf("%s\n", content);
		ft_memdel((void **)&content);
	}
	ft_printf("\n");
	ants_trajects_printer(farm);
}
