/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbareich <tbareich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 13:39:20 by mesafi            #+#    #+#             */
/*   Updated: 2020/03/12 21:01:41 by tbareich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static t_lem_in	*ft_init(void)
{
	t_lem_in	*farm;

	farm = (t_lem_in *)malloc(sizeof(t_lem_in));
	farm->score = MAX_INT;
	farm->ants = 0;
	farm->numerator = 0;
	farm->seen = NULL;
	farm->capacity = NULL;
	farm->options = 0;
	farm->circuit = NULL;
	farm->rooms = NULL;
	farm->graph = NULL;
	farm->required_iter = -1;
	farm->start = -1;
	farm->end = -1;
	init_queue(&(farm->results));
	return (farm);
}

static void		ft_free(t_lem_in *farm)
{
	free_queue(&(farm->results));
	free_circuit(farm->circuit);
	if (farm->seen != NULL)
		ft_memdel((void **)&(farm->seen));
	if (farm->capacity != NULL)
		ft_memdel((void **)&(farm->capacity));
	ft_memdel((void **)&farm);
}

static void		ft_error_handler(t_lem_in *farm)
{
	ft_putstr("ERROR\n");
	ft_free(farm);
	exit(1);
}

static void		print_path(t_lem_in *farm, t_list *path)
{
	int			room;

	if (path == NULL)
		return ;
	print_path(farm, path->next);
	room = *((int *)path->content);
	ft_printf("%s", ((t_room *)(farm->graph->adj_list[room].content))->name);
	if (room != farm->end)
		ft_printf("{green} -> {eoc}");
}

static void		print_circuit(t_lem_in *farm)
{
	t_list		*node;
	t_list		*path;

	if (farm->required_iter == -1)
		ft_printf("\n{red}required iterations : NOT DETECTED\n");
	else
		ft_printf("\n{red}required iterations : %d\n", farm->required_iter);
	ft_printf("\n{blue}total ants  : %d\n", farm->ants);
	ft_printf("total rooms : %d\n", farm->graph->v);
	ft_printf("{start room : %s\n",
			((t_room *)((farm->graph->adj_list[farm->start]).content))->name);
	ft_printf("{end room   : %s\n{eoc}",
			((t_room *)((farm->graph->adj_list[farm->end]).content))->name);
	ft_printf("\n{yellow}circuit size     : %d\n", farm->circuit->size);
	ft_printf("total edges      : %d\n", farm->circuit->total_edges);
	ft_printf("total iterations : %d \n\n{eoc}", farm->circuit->score - 1);
	if (!(farm->options & 2))
	{
		node = farm->circuit->routes;
		while (node)
		{
			path = ((t_path *)(node->content))->list;
			ft_printf("{magenta}( %d ) {eoc}", ((t_path *)
						(node->content))->ants);
			ft_printf("{magenta}[ %d ] :{eoc}  ", ((t_path *)
						(node->content))->size);
			print_path(farm, path);
			ft_printf("\n\n");
			node = node->next;
		}
	}
	ft_printf("{blue}─── infos about farm\n");
	ft_printf("{yellow}─── infos about circuits\n");
	ft_printf("{red}─── infos in files{eoc}\n");
	ft_printf("\n");
}

void			usage(t_lem_in *farm, int ac, char **av)
{
	int			i;

	i = 1;
	while (i < ac)
	{
		if (ft_strequ(av[i], "--help"))
		{
			ft_printf("Usage : ");
			ft_printf("./lem-in [--help | --info |--info-lite] \
[< map_file]\n");
			ft_printf("\toptions:\n");
			ft_printf("\t\t--help : read usage\n");
			ft_printf("\t\t--info: display program informations\n");
			ft_printf("\t\t--info-lite: display program informations \
(lite version)\n");
			exit(0);
		}
		if (ft_strequ(av[i], "--info"))
			farm->options |= 1;
		if (ft_strequ(av[i], "--info-lite"))
			farm->options |= 2;
		++i;
	}
}

int				main(int ac, char **av)
{
	t_lem_in	*farm;

	farm = ft_init();
	if (ac > 1)
		usage(farm, ac, av);
	if (ft_reader(farm) == 1)
		ft_error_handler(farm);
	if (ft_finder(farm) == 1)
		ft_error_handler(farm);
	if ((farm->options & 1) || (farm->options & 2))
		print_circuit(farm);
	else
		ft_print_results(farm);
	ft_free(farm);
	return (0);
}
