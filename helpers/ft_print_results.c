/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_results.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbareich <tbareich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/16 10:05:41 by mesafi            #+#    #+#             */
/*   Updated: 2020/03/02 13:00:01 by tbareich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lem_in.h"

static void		ants_trajects_printer(t_lem_in *farm, unsigned step)
{
	(void)farm;
	(void)step;
	return ;
}

void			ft_print_results(t_lem_in *farm)
{
	void		*content;
	t_queue		*results;
	unsigned	step;

	step = 0;
	results = &(farm->results);
	while (results->size != 0)
	{
		content = dequeue(results);
		ft_printf("%s\n", content);
		ft_memdel((void **)&content);
	}
	ft_printf("\n");
	ants_trajects_printer(farm, step);
}
