# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pba <pba@student.42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/01/09 11:34:20 by pba               #+#    #+#              #
#    Updated: 2016/02/22 09:34:39 by pba              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all, mkdir_obj, clean, fclean, re

.SUFFIXES:

NAME		= fillit
CFLAGS		= -Wall -Wextra -Werror -g
HPATH_FIL	= includes/
HPATH_LIBFT	= libft/includes/
SPATH		= src/
OPATH		= obj/

SRC			= fillit.c \
			check_file.c \
			check_around.c \
			get_2dimtab.c \
			move_upleft.c \
			get_point.c \
			list_manager.c \
			get_list.c \
			reset_list.c \
			min_square.c \
			write_point.c \
			check_place.c \
			write_tetri.c \
			reset_tetri.c \
			put.c \
			resolve.c \
			error.c

OBJ			= $(SRC:%.c=$(OPATH)%.o)

all: mkdir_obj $(NAME)

$(NAME): $(OBJ)
	@echo "\033[32;01mObject files created.\033[0m"
	@echo "\033[36;01mCompiling libft...\033[0m"
	@make re -C libft
	@echo "\033[32;01mlibft.a created.\033[0m"
	@gcc -o $(NAME) $(OBJ) -L./libft/ -lft
	@echo "\033[32;01mLink done.\033[0m"

$(OPATH)%.o: $(SPATH)%.c
	@gcc $(CFLAGS) -c $< -I $(HPATH_FIL) -I $(HPATH_LIBFT) -o $@

mkdir_obj:
	@mkdir -p $(OPATH)
	@echo "\033[32;01mobj/ folder created.\033[0m"

clean:
	@rm -rf $(OBJ)
	@echo "Objects deleted."

fclean: clean
	@rm -rf $(NAME)
	@echo "$(NAME) deleted."

re: fclean all
