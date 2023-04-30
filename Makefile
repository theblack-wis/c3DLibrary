# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aerrajiy <aerrajiy@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/18 01:47:00 by aerrajiy          #+#    #+#              #
#    Updated: 2023/04/30 12:27:55 by aerrajiy         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = PARSE
CC = cc
CFLAGS = -Wall -Wextra -Werror -g3 -fsanitize=address
MSG = push default

SRC = core/map_parsing/reader.c core/map_parsing/read_texture_color.c core/map_parsing/read_map.c core/map_parsing/verify_info/tools_check.c core/ray_casting/draw_tools/pixel_tools.c core/ray_casting/2dMapRendering.c
OBJ = $(SRC:.c=.o)

INCLUDES = -I c3DLibrary/include/
c3DLibrary = c3DLibrary/Cub_library

all: $(NAME)

$(NAME): $(OBJ)
	make -C c3DLibrary/
	$(CC) -lmlx -framework OpenGL -framework AppKit $(CFLAGS) $(OBJ) $(c3DLibrary) -o $(NAME)

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