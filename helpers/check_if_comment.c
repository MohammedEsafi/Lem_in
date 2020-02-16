/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_if_comment.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mesafi <mesafi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 09:04:34 by mesafi            #+#    #+#             */
/*   Updated: 2020/02/14 20:09:45 by mesafi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lem_in.h"

int		check_if_comment(char *line)
{
	if (*line == '#')
	{
		if (!ft_memcmp(line, "##start", 7))
			return (1);
		else if (!ft_memcmp(line, "##end", 7))
			return (2);
		else
			return (3);
	}
	return (0);
}
