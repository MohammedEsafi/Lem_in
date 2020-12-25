/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_start_end.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mesafi <mesafi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 09:41:01 by mesafi            #+#    #+#             */
/*   Updated: 2020/11/09 09:41:03 by mesafi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lem_in.h"

void		fill_start_end(t_lem_in *farm, int status, int key)
{
	if (status == 1)
		farm->start = key;
	else if (status == 2)
		farm->end = key;
}
