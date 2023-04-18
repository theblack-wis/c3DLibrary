/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aerrajiy <aerrajiy@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 01:40:53 by aerrajiy          #+#    #+#             */
/*   Updated: 2023/04/18 07:58:29 by aerrajiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include "../c3DLibrary/include/lib.h"
# include "../c3DLibrary/include/ft_printf.h"
# include "../c3DLibrary/include/gnl.h"

typedef struct s_parser
{
    char **texture;
    char **colors;
    char **map;
}   t_parser;

typedef struct s_reading
{
    int fd;
    char *line;
    char **data;
    int texture_count;
    int color_count;
}   t_reading;

int     check_structur(char *data);
char    *remove_new_line(char *str);
void    printParser(t_parser *parser);
void    read_texture_color(char *file, t_parser **parser);
void    check_texture_color(t_parser *parser);

void    read_map(char *file, t_parser **parser);
int     who_is_the_big_line(char *file);
int     count_line_number(char *file);
#endif