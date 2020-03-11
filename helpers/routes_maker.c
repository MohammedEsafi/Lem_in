/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routes_maker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbareich <tbareich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/01 13:04:09 by tbareich          #+#    #+#             */
/*   Updated: 2020/03/11 15:40:38 by tbareich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lem_in.h"

static void			ft_correct(t_lem_in *farm, t_circuit *circuit)
{
	t_list		*node;
	t_path		*path;
	int			i;

	node = circuit->routes;
	i = -1;
	while (node != NULL)
	{
		++i;
		path = (t_path *)(node->content);
		path->ants = circuit->score - path->size;
		if (path->ants <= 0)
		{
			circuit->total_edges -= path->size;
			circuit->size -= 1;
			circuit->rest = (circuit->total_edges + farm->ants) % circuit->size;
			circuit->score = (circuit->total_edges + farm->ants) /
								circuit->size - (circuit->rest == 0);
			ft_lstdelat(&(circuit->routes), i);
			i = -1;
			node = circuit->routes;
			continue ;
		}
		path->ants += (circuit->rest-- > 0);
		path->remnant = path->ants;
		node = node->next;
	}
}

static void			ft_switcher(t_lem_in *farm, t_circuit *circuit)
{
	farm->score = circuit->score;
	free_circuit(farm->circuit);
	farm->circuit = circuit;
}

static t_circuit	*init_circuit(void)
{
	t_circuit	*circuit;

	if (!(circuit = (t_circuit *)malloc(sizeof(t_circuit))))
		return (NULL);
	circuit->size = 0;
	circuit->routes = NULL;
	circuit->total_edges = 0;
	return (circuit);
}

static t_path		*init_path(void)
{
	t_path	*path;

	if (!(path = (t_path *)malloc(sizeof(t_path))))
		return (NULL);
	path->size = 1;
	path->list = NULL;
	path->ants = 0;
	return (path);
}

static int			get_the_route(t_lem_in *farm, unsigned *total_edges,
								int prev[farm->graph->v], t_circuit *circuit)
{
	t_path		*path;
	t_list		*node;
	int			current;

	if (!(path = init_path()))
		return (-1);
	current = farm->end;
	ft_lstadd(&(path->list), ft_lstnew(&(current), sizeof(int)));
	farm->seen[current] = 1;
	node = path->list;
	while (current != farm->start)
	{
		current = prev[current];
		farm->seen[current] = 1;
		if ((node->next = ft_lstnew(&(current), sizeof(int))) == 0)
			return (-1);
		path->size += 1;
		node = node->next;
	}
	ft_lstadd(&(circuit->routes), ft_lstnew(path, sizeof(t_path)));
	circuit->size += 1;
	*total_edges += path->size;
	return (0);
}

static int		get_the_way(t_lem_in *farm,
						unsigned *total_edges, t_circuit *circuit)
{
	t_node		*node;
	int			*prev;
	char		*visited;
	int			current;
	t_queue		q;

	init_queue(&q);
	if (!(prev = (int *)malloc(sizeof(int) * farm->graph->v)))
		return (-1);
	if (!(visited = (char *)malloc(farm->graph->v)))
	{
		ft_memdel((void**)&prev);
		return (-1);
	}
	ft_memset(visited, 0, farm->graph->v);
	enqueue(&q, &farm->start, sizeof(int));
	visited[farm->start] = 1;
	while (q.size != 0)
	{
		current = *((int *)dequeue(&q));
		node = farm->graph->adj_list[current].head;
		while (node != NULL)
		{
			if (farm->capacity[node->key * farm->graph->v + current] == 2
				&& visited[node->key] == 0)
			{
				prev[node->key] = current;
				if (node->key == (unsigned)farm->end)
				{
					get_the_route(farm, total_edges, prev, circuit);
					break ;
				}
				enqueue(&q, &node->key, sizeof(int));
				visited[node->key] = 1;
			}
			node = node->next;
		}
	}
	free_queue(&q);
	return (0);
}

void				print_circuit(t_lem_in *farm, t_circuit circuit)
{
	t_list		*node;
	t_list		*path;
	int			room;

	ft_printf("{red}circuit size : %d \n", circuit.size);
	ft_printf("circuit score : %d \n\n{eoc}", circuit.score);
	node = circuit.routes;
	while (node)
	{
		path = ((t_path *)(node->content))->list;
		ft_printf("{yellow}path size : %d {eoc}\n", ((t_path *)
					(node->content))->size);
		while (path)
		{
			room = *((int *)path->content);
			ft_printf("%s", ((t_room *)
						(farm->graph->adj_list[room].content))->name);
			if (path->next)
				ft_printf("{green} => {eoc}");
			path = path->next;
		}
		ft_printf("\n");
		node = node->next;
	}
	ft_printf("\n\n\n");
}

int					routes_maker(t_lem_in *farm)
{
	t_node		*node;
	t_circuit	*circuit;

	node = farm->graph->adj_list[farm->start].head;
	if (!(circuit = init_circuit()))
		return (1);
	get_the_way(farm, &(circuit->total_edges), circuit);
	circuit->rest = (circuit->total_edges + farm->ants) % circuit->size;
	circuit->score = ((circuit->total_edges + farm->ants) / circuit->size) -
						(circuit->rest == 0);
	// ft_printf("{blue}circuit size : %d \n", circuit->size);
	// ft_printf("circuit score : %d \n\n{eoc}", circuit->score);
	// print_circuit(farm, *circuit);
	ft_correct(farm, circuit);
	// ft_printf("{red}circuit size : %d \n", circuit->size);
	// ft_printf("circuit score : %d \n\n{eoc}", circuit->score);
	if (circuit->score < farm->score)
		ft_switcher(farm, circuit);
	else
		free_circuit(circuit);
	return (0);
}
