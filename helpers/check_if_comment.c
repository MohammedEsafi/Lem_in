/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_if_comment.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbareich <tbareich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 09:04:34 by mesafi            #+#    #+#             */
/*   Updated: 2020/03/12 19:30:11 by tbareich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lem_in.h"

int		check_if_comment(t_lem_in *farm, char *line)
{
	if (*line == '#')
	{
		if (!ft_memcmp(line, "##start", 7))
			return (1);
		else if (!ft_memcmp(line, "##end", 5))
			return (2);
		else if (ft_strnequ(line,
			"#Here is the number of lines required: ", 39))
			farm->required_iter = ft_atoi(line + 39);
		return (3);
	}
	return (0);
}
