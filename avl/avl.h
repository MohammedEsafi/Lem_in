/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   avl.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbareich <tbareich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/16 11:50:32 by tbareich          #+#    #+#             */
/*   Updated: 2020/12/07 19:42:46 by tbareich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AVL_H

# define AVL_H

# include <stdlib.h>
# include "../libft/libft.h"
# include "../libft/ft_printf/ft_printf.h"

typedef struct	s_avl
{
	int				key;
	int				height;
	void			*content;
	size_t			content_size;
	struct s_avl	*left;
	struct s_avl	*right;
}				t_avl;

t_avl			*new_node(int key, void *content, size_t size);
t_avl			*new_node_elem(void *content, size_t size);
t_avl			*avl_insert_str(t_avl *root, char *str);
t_avl			*avl_insert(t_avl *root, int key);
t_avl			*avl_insert_elem(t_avl *root, void *content,
					size_t content_size, int (*f)(void *, void *));
int				height(t_avl *node);
int				get_balance(t_avl *node);
t_avl			*left_rot(t_avl *node);
t_avl			*right_rot(t_avl *node);
t_avl			*left_right_rot(t_avl *node);
t_avl			*right_left_rot(t_avl *node);
void			avl_print(t_avl *root);
void			avl_print_str(t_avl *root);\
void			avl_print_elem(t_avl *root, void (*print)(t_avl *));
t_avl			*avl_find(t_avl *root, int key);
t_avl			*avl_find_str(t_avl *root, char *str);
t_avl			*avl_find_elem(t_avl *root, void *content,
									int (*cmp)(void *, void *));
void			avl_inorder(t_avl *root, void *ptr, void (*f)(void *, void *));
void			avl_delete(t_avl **root, void (*del)(void*, size_t));

#endif
