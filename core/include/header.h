/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aerrajiy <aerrajiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 01:40:53 by aerrajiy          #+#    #+#             */
/*   Updated: 2023/04/30 11:57:44 by aerrajiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include "../../c3DLibrary/include/lib.h"
# include "../../c3DLibrary/include/ft_printf.h"
# include "../../c3DLibrary/include/gnl.h"
# include <mlx.h>
# include <math.h>

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

typedef struct	s_img_draw {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}   t_img_draw;

typedef struct s_player
{
	float x;
	float y;
	float pdx, pdy, pa;
}   t_player;

typedef struct s_vars
{
	t_img_draw *img;
	t_parser *parser;
	t_player *player;
	int win_width;
	int win_height;
	void *mlx;
	void *win;
}   t_vars;

typedef struct s_point
{
    float x;
    float y;
}   t_point;

// arrow buttons :
# define KEY_UP 126
# define KEY_DOWN 125
# define KEY_LEFT 123
# define KEY_RIGHT 124

// parsing_functions :
void	ParserReader(char *file, t_parser **parser);
void    texture_color_Filter(t_parser *parser);
void    read_texture_color(char *file, t_parser **parser);
void 	ft_error(const char *pointer, char *str);
int 	count_line_number(char *file);
int 	who_is_the_big_line(char *file);
char    *allocat_saver(char *line, int size);
void    map_Filter(t_map *map);
void    read_map(char *file, t_parser **parser);
char 	*remove_new_line(char *str);
int 	check_structur(char *data);
int 	table_size(char **table);
int 	line_has_zero(char *line);
int 	has_empty_line(char **map);
int 	is_player_or_space(char elemnt);

// ray_casting_functions :
void	my_mlx_pixel_put(t_img_draw *data, int x, int y, int color);
void    init_window_image(t_vars **home);
void 	drawGrid(int x, int y, int lenght,long color, t_vars **home);


#endif