/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mesafi <mesafi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 13:39:20 by mesafi            #+#    #+#             */
/*   Updated: 2020/02/16 08:34:52 by mesafi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	error_handler(int status)
{
	if (status == 0)
		ft_putstr("ERROR");
	exit(1);
}

int		main(void)
{
	t_lem_in	*farm;

	farm = (t_lem_in *)malloc(sizeof(t_lem_in));
	if ((farm->fd = open("results", O_RDWR | O_CREAT, 0777)) < 0)
		error_handler(0);
	if (ft_reader(farm) == 1)
		error_handler(0);
	close(farm->fd);
	return (0);
}
