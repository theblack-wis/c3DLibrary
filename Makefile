# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aerrajiy <aerrajiy@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/18 01:47:00 by aerrajiy          #+#    #+#              #
#    Updated: 2023/04/18 01:49:23 by aerrajiy         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = PARSE
CC = cc
CFLAGS = -Wall -Wextra -Werror -g -fsanitize=address

SRC = core/reader.c
OBJ = $(SRC:.c=.o)

INCLUDES = -I c3DLibrary/include/

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all