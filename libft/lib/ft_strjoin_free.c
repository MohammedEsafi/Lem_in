/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_free.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbareich <tbareich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 20:15:02 by tbareich          #+#    #+#             */
/*   Updated: 2020/02/17 19:47:06 by tbareich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strjoin_free(char const *s1, char const *s2, int option)
{
	char	*str;

	if (s2 == NULL || *s2 == 0)
		str = ft_strdup(s1);
	else if (s1 == NULL || *s1 == 0)
		str = ft_strdup(s2);
	else
		str = ft_strjoin(s1, s2);
	if (option == 1 || option == 0)
		if (s1 != NULL)
			free((void *)s1);
	if (option == 2 || option == 0)
		if (s2 != NULL)
			free((void *)s2);
	return (str);
}
