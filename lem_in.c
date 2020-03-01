/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mesafi <mesafi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 13:39:20 by mesafi            #+#    #+#             */
/*   Updated: 2020/03/01 11:00:01 by mesafi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

// static void		print(t_avl *elem)
// {
// 	ft_printf("%-20s", ((t_rooms *)elem->content)->name);
// 	ft_printf("%-20d\n", ((t_rooms *)elem->content)->key);
// }

// static void		ft_print_data(t_lem_in *farm)
// {
// 	ft_printf("{red}%-20s", "Name");
// 	ft_printf("%-20s{eoc}\n", "Key");
// 	avl_print_elem(farm->rooms, print);
// 	ft_printf("\n");
// 	print_graph(farm->graph);
// 	ft_printf("\n");
// 	ft_printf("{red}start :{eoc} %d\n", farm->start);
// 	ft_printf("{red}end   :{eoc} %d\n", farm->end);
// }

static t_lem_in	*ft_init(void)
{
	t_lem_in	*farm;

	farm = (t_lem_in *)malloc(sizeof(t_lem_in));
	farm->ants = 0;
	farm->rooms = NULL;
	farm->graph = NULL;
	farm->start = -1;
	farm->end = -1;
	init_queue(&(farm->results));
	return (farm);
}

static void		ft_error_handler(t_lem_in *farm)
{
	ft_putstr("ERROR\n");
	free_queue(&(farm->results));
	ft_memdel((void **)&farm);
	exit(1);
}

int			main(void)
{
	t_lem_in	*farm;

	farm = ft_init();
	if (ft_reader(farm) == 1)
		ft_error_handler(farm);
	if (ft_finder(farm) == 1)
		ft_error_handler(farm);
	// ft_print_results(&(farm->results));
	ft_print_data(farm);
	return (0);
}
