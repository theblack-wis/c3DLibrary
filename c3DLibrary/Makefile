# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aerrajiy <aerrajiy@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/20 21:30:37 by mabahani          #+#    #+#              #
#    Updated: 2023/04/18 01:13:02 by aerrajiy         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Cub_library

CC = cc

CFLAGS = -Wall -Wextra -Werror

LibFt_SRC = lib/ft_bzero.c lib/ft_isalnum.c lib/ft_isascii.c lib/ft_isprint.c lib/ft_memchr.c lib/ft_memcpy.c lib/ft_memset.c  lib/ft_strchr.c lib/ft_striteri.c lib/ft_strlcat.c lib/ft_strlen.c \
      lib/ft_strncmp.c lib/ft_strcmp.c lib/ft_strrchr.c lib/ft_substr.c lib/ft_toupper.c lib/ft_atoi.c lib/ft_calloc.c lib/ft_isalpha.c lib/ft_isdigit.c lib/ft_itoa.c lib/ft_memcmp.c lib/ft_memmove.c \
      lib/ft_split.c lib/ft_strdup.c lib/ft_strjoin.c lib/ft_strlcpy.c lib/ft_strmapi.c lib/ft_strnstr.c lib/ft_strtrim.c lib/ft_tolower.c lib/ft_putchar_fd.c lib/ft_putstr_fd.c lib/ft_putendl_fd.c \
      lib/ft_putnbr_fd.c

GnL_SRC = gnl/get_next_line.c gnl/get_next_line_utils.c

PrintF_SRC = printf/ft_printf.c	printf/srcs/ft_putchar.c printf/srcs/ft_putnbr.c printf/srcs/ft_putunsigned.c printf/srcs/ft_put_addr.c printf/srcs/ft_puthexa.c printf/srcs/ft_putstr.c printf/srcs/to_help.c

LibFt_OBJ = $(LibFt_SRC:.c=.o)
GnL_OBJ = $(GnL_SRC:.c=.o)
PrintF_OBJ = $(PrintF_SRC:.c=.o)

all: $(NAME)

$(NAME):$(LibFt_OBJ) $(GnL_OBJ) $(PrintF_OBJ)
	ar rc $(NAME) $(LibFt_OBJ) $(GnL_OBJ) $(PrintF_OBJ)

clean:
	rm -f $(LibFt_OBJ) $(GnL_OBJ) $(PrintF_OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean bonus re