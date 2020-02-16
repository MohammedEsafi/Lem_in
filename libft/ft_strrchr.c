/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mesafi <mesafi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 22:58:36 by mesafi            #+#    #+#             */
/*   Updated: 2020/02/13 10:44:19 by mesafi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	int		n;
	char	*p;

	n = ft_strlen(str);
	p = (char *)str + n;
	while (n >= 0)
	{
		if (*p == c)
			return (p);
		p--;
		n--;
	}
	return (NULL);
}
