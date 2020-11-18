/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info_printers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbareich <tbareich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 18:51:20 by tbareich          #+#    #+#             */
/*   Updated: 2020/11/18 12:25:08 by tbareich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lem_in.h"

static void		print_infos(t_lem_in *farm)
{
	if (farm->required_iter == -1)
		ft_printf("\n{red}required iterations : NOT DETECTED\n");
	else
		ft_printf("\n{red}required iterations : %d\n", farm->required_iter);
	ft_printf("\n{blue}total ants  : %d\n", farm->ants);
	ft_printf("total rooms : %d\n", farm->graph->v);
	ft_printf("start room : %s\n",
			((t_room *)((farm->graph->adj_list[farm->start]).content))->name);
	ft_printf("end room   : %s\n{eoc}",
			((t_room *)((farm->graph->adj_list[farm->end]).content))->name);
	ft_printf("\n{yellow}circuit size     : %d\n", farm->circuit->size);
	ft_printf("total nodes      : %d\n", farm->circuit->total_edges);
	if ((unsigned)(farm->circuit->score) <= (unsigned)(farm->required_iter + 1))
		ft_printf("total iterations : {green}%d \n\n{eoc}", farm->circuit->score
					- 1);
	else
		ft_printf("total iterations : {red}%d \n\n{eoc}", farm->circuit->score
					- 1);
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

void			print_circuit(t_lem_in *farm)
{
	t_list		*node;
	t_list		*path;

	print_infos(farm);
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
