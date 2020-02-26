/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mesafi <mesafi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 13:39:20 by mesafi            #+#    #+#             */
/*   Updated: 2020/02/26 11:36:43 by mesafi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

// static void		print(t_avl *elem)
// {
// 	ft_printf("%-20s ｜ ", ((t_rooms *)elem->content)->name);
// 	ft_printf("%-20d ｜ ", ((t_rooms *)elem->content)->key);
// 	ft_printf("%-20d\n", elem->height);
// }

static t_lem_in	*ft_init(void)
{
	t_lem_in	*farm;

	farm = (t_lem_in *)malloc(sizeof(t_lem_in));
	farm->ants = 0;
	farm->rooms = NULL;
	init_queue(&(farm->results));
	return (farm);
}

static void		ft_error_handler(t_lem_in *farm, int status)
{
	if (status == 0)
		ft_putstr("ERROR");
	free_queue(&(farm->results));
	free(farm);
	exit(1);
}

int			main(void)
{
	t_lem_in	*farm;

	farm = ft_init();
	if (ft_reader(farm) == 1)
		ft_error_handler(farm, 0);
	ft_print_results(&(farm->results));

	/* Display Avl */
	// ft_printf("%-20s ｜ ", "name");
	// ft_printf("%-20s ｜ ", "key");
	// ft_printf("%-20s\n", "height");
	// avl_print_elem(farm->rooms, print);
	return (0);
}
