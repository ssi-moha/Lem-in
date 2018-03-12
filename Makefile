# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ssi-moha <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/03/02 19:27:46 by ssi-moha          #+#    #+#              #
#    Updated: 2018/03/10 12:54:24 by ssi-moha         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = lem-in

LIB = libft/libft.a

INCLUDE = lem_in.h

CC = gcc

CFLAGS = -Wall -Werror -Wextra

MAIN = main.c

SRC = check_double.c check_format.c check_link.c check_xy.c free_path.c\
	  free_rooms.c free_tab.c get_link.c get_next_line.c get_start.c get_xy.c\
	  is_space.c new_list.c new_room.c path_len.c read_input.c\
	  search_path.c set_tab.c take_path.c to_zero.c error_mess.c\
	  free_both.c stk_path.c

OBJ = $(SRC:.c=.o)

all : $(NAME)

$(NAME): $(OBJ)
	make -C libft
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(MAIN) $(LIB)

clean:
	rm -rf $(OBJ)
	make clean -C ./libft

fclean: clean
	rm -rf $(NAME)
	make fclean -C ./libft

re: fclean all
