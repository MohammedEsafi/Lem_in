/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enqueue.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mesafi <mesafi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 11:06:25 by mesafi            #+#    #+#             */
/*   Updated: 2020/02/16 09:58:18 by mesafi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "queue.h"

void	enqueue(t_queue *queue, t_list *node)
{
	queue->size += 1;
	if (queue->last == NULL)
	{
		queue->front = node;
		queue->last = node;
		return ;
	}
	queue->last->next = node;
	queue->last = node;
}
