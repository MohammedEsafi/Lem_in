# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tbareich <tbareich@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/20 13:51:29 by mesafi            #+#    #+#              #
#    Updated: 2020/02/25 11:37:58 by tbareich         ###   ########.fr        #
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
				helpers/get_the_links.o\
				avl/avl.o \
				avl/avl_insert_str.o\
				avl/avl_insert.o\
				avl/avl_print.o
				
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
all: build $(NAME)

build:
	@if [ ! -f $(NAME) ] ; then \
		echo "⇾ building $(NAME)..." ; \
	fi;

$(NAME): $(OBJS) $(HEADER)
	@make -s -C libft
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
