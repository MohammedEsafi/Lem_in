# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tbareich <tbareich@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/20 13:51:29 by mesafi            #+#    #+#              #
#    Updated: 2020/11/18 12:11:51 by tbareich         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Usage:
# make			# compile all binary
# make clean	# remove all binaries and objects
# make fclean	# remove created library
# make re		# Get recompiled

# Standard variables
NAME		= lem-in
LIBFT		= libft/libft.a
FT_PRINTF	= libft/libftprintf.a
HEADER		= lem_in.h
OBJS		= lem_in.o \
				helpers/ft_reader.o \
				helpers/check_if_comment.o \
				helpers/get_number_of_ants.o \
				helpers/get_the_rooms.o \
				helpers/ft_print_results.o \
				helpers/get_the_links.o \
				avl/avl_rot.o \
				avl/avl_inorder.o \
				avl/avl_find.o \
				avl/avl_insert.o \
				avl/avl_helpers.o \
				avl/avl_create.o \
				avl/avl_print.o \
				helpers/ft_finder.o \
				helpers/edmonds_karp.o \
				helpers/routes_maker.o \
				helpers/free_circuit.o \
				helpers/info_printers.o \
				helpers/fill_start_end.o \
				helpers/get_the_route.o \
				helpers/get_the_ways.o \
				helpers/bfs.o \
				helpers/del_path.o

CC			= gcc
CFLAGS		= -Wall -Wextra -Werror

# Colors
BLACK		= \033[30m
RED			= \033[31m
GREEN		= \033[32m
YELLOW		= \033[93m
BLUE		= \033[34m
MAGENTA		= \033[35m
CYAN		= \033[36m
WHITE		= \033[37m
RESET		= \033[0m

# Start rules
all:  $(NAME)

build:
	@if [ ! -f $(NAME) ] ; then \
		echo "⇾ building $(NAME)..." ; \
	fi;
	@make -s -C libft

$(NAME): build $(OBJS) $(HEADER)
	@if [ ! -f $(NAME) ] ; then \
		echo "⇾ $(NAME) $(GREEN)done$(RESET)"; \
	else \
		echo "⇾ $(NAME) $(GREEN)updated$(RESET)"; \
	fi;
	@gcc $(CFLAGS) $(LIBFT) $(FT_PRINTF) $(OBJS) -o $(NAME)

%.o: %.c
	@$(CC) -c $(CFLAGS) $< -o $@
	@if [[ -f $(NAME) ]] ; then \
		echo "⇾ $@ $(GREEN)updated$(RESET)" ; \
	fi;

clean:
	@make -s clean -C libft
	@rm -f $(OBJS)
	@echo "⇾ $(NAME) $(RED)cleaned$(RESET)"
	
fclean: clean
	@rm -f $(FT_PRINTF)
	@rm -f $(LIBFT)
	@echo "⇾ libft.a $(RED)deleted$(RESET)"
	@rm -f $(NAME)
	@echo "⇾ $(NAME) $(RED)deleted$(RESET)"

re: fclean all

.PHONY: all clean fclean re build
