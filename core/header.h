/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aerrajiy <aerrajiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 01:40:53 by aerrajiy          #+#    #+#             */
/*   Updated: 2023/04/20 02:32:39 by aerrajiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include "../c3DLibrary/include/lib.h"
# include "../c3DLibrary/include/ft_printf.h"
# include "../c3DLibrary/include/gnl.h"

typedef struct s_map
{
	int row;
	int col;
	char **map;
}   t_map;

typedef struct s_parser
{
	char    **texture;
	char    **colors;
	t_map   *map;
}   t_parser;

typedef struct s_reading
{
	int fd;
	char *line;
	char **data;
	int texture_count;
	int color_count;
}   t_reading;

void	texture_color_Filter(t_parser *parser);
void	read_texture_color(char *file, t_parser **parser);

int		count_line_number(char *file);
int		who_is_the_big_line(char *file);
char	*allocat_saver(char *line, int size);
void	map_Filter(t_map *map);
void	read_map(char *file, t_parser **parser);

char	*remove_new_line(char *str);
int		check_structur(char *data);
int		table_size(char **table);
int		line_has_zero(char *line);
int		has_empty_line(char **map);
int		is_player_or_space(char elemnt);



#endif