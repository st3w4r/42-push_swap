# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ybarbier <ybarbier@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/11/03 11:35:46 by ybarbier          #+#    #+#              #
#    Updated: 2015/03/07 14:16:57 by ybarbier         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
PATH_SRC = ./src/
PATH_OBJ = ./
PATH_INC = ./libft/includes/

CC = cc
# CFLAGS = -Wall -Wextra -Werror -Wpadded -Ofast -I $(PATH_INC)
CFLAGS = -Ofast -I $(PATH_INC) -g
LIBS = -L libft/ -lft

HEAD = $(PATH_SRC)push_swap.h

SRC =	main.c \
		ps_parse.c \
		ps_stack.c \
		ft_error.c

OBJ = $(addprefix $(PATH_SRC), $(SRC:.c=.o))

all: $(NAME)

$(NAME): $(OBJ) $(HEAD)
	make -C libft/
	$(CC) $(OBJ) -o $(NAME) $(LIBS)


.PHONY: clean fclean

clean:
	make -C libft/ clean
	/bin/rm -f $(OBJ)

fclean: clean
	make -C libft/ fclean
	/bin/rm -f $(NAME)

re: fclean all
