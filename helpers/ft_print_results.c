/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_results.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mesafi <mesafi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/16 10:05:41 by mesafi            #+#    #+#             */
/*   Updated: 2020/02/16 10:06:59 by mesafi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lem_in.h"

void			ft_print_results(t_queue *results)
{
	t_list	*node;

	while (results->size != 0)
	{
		node = dequeue(results);
		ft_printf("%s\n", node->content);
		free(node->content);
		free(node);
	}
}