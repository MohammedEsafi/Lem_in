/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_queue.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbareich <tbareich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 21:31:38 by mesafi            #+#    #+#             */
/*   Updated: 2020/02/27 18:49:44 by tbareich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "queue.h"

void	free_queue(t_queue *queue)
{
	t_list	*node;

	while (queue->size != 0)
	{
		node = dequeue(queue);
		ft_memdel((void **)&node->content);
		ft_memdel((void **)&node);
	}
}
