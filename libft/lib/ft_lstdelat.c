/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelat.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbareich <tbareich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 03:31:22 by tbareich          #+#    #+#             */
/*   Updated: 2020/03/04 21:28:05 by tbareich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

t_list	*ft_lstdelat(t_list **alst, int index)
{
	t_list	*tmp;
	t_list	*prv;

	if (alst == NULL || index < 0 || *alst == NULL)
		return (NULL);
	if (index == 0)
	{
		return (ft_lstshift(alst));
	}
	tmp = *alst;
	prv = NULL;
	while (index--)
	{
		if (tmp == NULL)
			return (NULL);
		prv = tmp;
		tmp = tmp->next;
	}
	ft_printf("ffff\n");
	if (prv)
		prv->next = tmp->next;
	else
		prv = 0;
	ft_printf("ffff\n");
	return (tmp);
}
