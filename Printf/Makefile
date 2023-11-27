# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: loosorio <loosorio@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/20 18:29:08 by loosorio          #+#    #+#              #
#    Updated: 2023/11/27 19:48:04 by loosorio         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC = cc
CFLAGS = -Werror -Wextra -Wall
SRC = ft_printf.c parameters.c parameters2.c main.c

OBJ = $(SRC:.c=.o)
all: $(NAME)
$(NAME): $(OBJ)
		ar -rcs $(NAME) $(OBJ)
clean:
		@echo "\nRemoving objects:"
		rm -f $(OBJ)
fclean: clean
		@echo "\nRemoving libftprintf.a:"
		rm -f $(NAME)
re: fclean all
.PHONY: all clean fclean re
