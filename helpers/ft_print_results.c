/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_results.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbareich <tbareich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/16 10:05:41 by mesafi            #+#    #+#             */
/*   Updated: 2020/02/29 20:16:28 by tbareich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lem_in.h"

void			ft_print_results(t_queue *results)
{
	void	*content;

	while (results->size != 0)
	{
		content = dequeue(results);
		ft_printf("%s\n", content);
		ft_memdel((void **)&content);
	}
}
