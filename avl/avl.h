/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   avl.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbareich <tbareich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/16 11:50:32 by tbareich          #+#    #+#             */
/*   Updated: 2020/02/19 06:48:14 by tbareich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AVL_H

# define AVL_H

typedef struct	s_avl
{
	int				key;
	int				height;
	void			*content;
	struct s_avl	*left;
	struct s_avl	*right;
}				t_avl;

t_avl			*new_node(int key, void *content);

#endif
