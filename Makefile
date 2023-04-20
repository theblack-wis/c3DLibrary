# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aerrajiy <aerrajiy@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/18 01:47:00 by aerrajiy          #+#    #+#              #
#    Updated: 2023/04/20 02:33:46 by aerrajiy         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = PARSE
CC = cc
CFLAGS = -Wall -Wextra -Werror -g -fsanitize=address
MSG = push default

SRC = core/reader.c core/read_texture_color.c core/read_map.c core/verify_info/tools_check.c
OBJ = $(SRC:.c=.o)

INCLUDES = -I c3DLibrary/include/
c3DLibrary = c3DLibrary/Cub_library

all: $(NAME)

$(NAME): $(OBJ)
	make -C c3DLibrary/
	$(CC) $(CFLAGS) $(OBJ) $(c3DLibrary) -o $(NAME)

clean:
	rm -f $(OBJ)
	make clean -C c3DLibrary/

fclean: clean
	rm -f $(NAME)
	make fclean -C c3DLibrary/

push:
	git add .
	git commit -m "$(MSG)"
	git push
re: fclean all