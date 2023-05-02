/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2dMapRendering.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aerrajiy <aerrajiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 12:01:45 by aerrajiy          #+#    #+#             */
/*   Updated: 2023/05/02 21:41:39 by aerrajiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  "../include/header.h"

#define PI 3.14159 

void draw_line(long color, int x1, int y1, int x2, int y2, t_vars **home) {
  int dx = abs(x2 - x1);
  int dy = abs(y2 - y1);
  int sx = x1 < x2 ? 1 : -1;
  int sy = y1 < y2 ? 1 : -1;
  int err = dx - dy;

  while (x1 != x2 || y1 != y2) {
    my_mlx_pixel_put((*home)->img, x1, y1, color);
    int e2 = 2 * err;
    if (e2 > -dy) {
      err -= dy;
      x1 += sx;
    }
    if (e2 < dx) {
      err += dx;
      y1 += sy;
    }
  }
}

void getPlayerPosition(t_vars **home)
{
    int i = 0;
    int j;

    (*home)->player->pa = 0;
    (*home)->player->pdy = cos((*home)->player->pa) * 5;
    (*home)->player->pdx = sin((*home)->player->pa) * 5;
    
    while ((*home)->parser->map->map[i])
    {
        j = 0;
        while ((*home)->parser->map->map[i][j])
        {
            if ((*home)->parser->map->map[i][j] == 'N')
            {
                (*home)->player->x = (i * 64) + 27;
                (*home)->player->y = (j * 64) + 27;
                return ;
            }
            j++;
        }
        i++;
    }
}

void drawRay2D(t_vars **home)
{
    int i, Map_X, Map_Y, Map_P, j;
    float Ray_X, Ray_Y, Ray_A, off_X, off_Y;

    Ray_A = (*home)->player->pa;
    i = 0;
    while (i < 1)
    {
        j = 0;

        float A_tan = -1 / tan(Ray_A);
        if (Ray_A > PI)
        {
            Ray_Y = (((int) (*home)->player->y >> 6) << 6) - 0.0001;
            Ray_X = ((*home)->player->y - Ray_Y) * A_tan + (*home)->player->x;
            
            off_Y = -64;
            off_X = - off_Y * A_tan;
        }
        
        if (Ray_A < PI)
        {
            Ray_Y = (((int) (*home)->player->y >> 6) << 6) + 64;
            Ray_X = ((*home)->player->y - Ray_Y) * A_tan + (*home)->player->x;
            
            off_Y = 64;
            off_X = - off_Y * A_tan;
        }

        if (Ray_A == 0 || Ray_A == PI)
        {
            Ray_X = (*home)->player->x;
            Ray_Y = (*home)->player->y;
            j = 8;
        }
        
        while (j < 8)
        {
            Map_X = (int) Ray_X >> 6;
            Map_Y = (int) Ray_Y >> 6;
            Map_P = Map_Y * 8 + Map_X;

            if ((*home)->parser->map->map[Map_X][Map_Y] == '1'){j = 8;}
            else {Ray_X += off_X; Ray_Y += off_Y; j++;}
        }      
        i++;
    }

    draw_line(
        0X00ff0000,
        (*home)->player->y,
        (*home)->player->x,
        
        Ray_X,
        Ray_Y,
        home
    );
}

void drawMap(t_vars **home)
{
    int i = 0;
    int j;

    while ((*home)->parser->map->map[i])
    {
        j = 0;
        while ((*home)->parser->map->map[i][j])
        {
            if ((*home)->parser->map->map[i][j] == '1')
                drawGrid(i * 64, j * 64, 64, 0x00FFFFFF, home);
            else
                drawGrid(i * 64, j * 64, 64, 0x003f0020, home);
            j++;
        }
        i++;
    }
    
    drawGrid((*home)->player->x,(*home)->player->y, 10, 0x00ff0000, home);
    draw_line(0X00ff0000, (*home)->player->y + 5 - 1,(*home)->player->x + 5 - 1,(*home)->player->y + ((*home)->player->pdy * 10),(*home)->player->x + ((*home)->player->pdx * 15),home);
    drawRay2D(home);
}

void    init_window_image(t_vars **home)
{    
    (*home)->img = malloc(sizeof(t_img_draw));
    (*home)->player = malloc(sizeof(t_player));
    
    (*home)->win_height = ((*home)->parser->map->col - 1) * 64;
    (*home)->win_width = ((*home)->parser->map->row) * 64;
    
    getPlayerPosition(home);

    (*home)->mlx = mlx_init();
    (*home)->win = mlx_new_window((*home)->mlx, (*home)->win_height,  (*home)->win_width, "Cub2D");
    (*home)->img->img = mlx_new_image((*home)->mlx, (*home)->win_height, (*home)->win_width);
    (*home)->img->addr = mlx_get_data_addr((*home)->img->img, &(*home)->img->bits_per_pixel, &(*home)->img->line_length, &(*home)->img->endian);
}

int moveHandler(int key, t_vars **home)
{
    if (key == KEY_LEFT){
        (*home)->player->pa -= 0.1;
        if ((*home)->player->pa < 0)
            (*home)->player->pa += 2 * PI;
        (*home)->player->pdy = cos((*home)->player->pa) * 5;
        (*home)->player->pdx = sin((*home)->player->pa) * 5;
    };

    if (key == KEY_RIGHT){
        (*home)->player->pa += 0.1;
        if ((*home)->player->pa > 2 * PI)
            (*home)->player->pa -= 2 * PI;
        (*home)->player->pdy = cos((*home)->player->pa) * 5;
        (*home)->player->pdx = sin((*home)->player->pa) * 5;
    };

    if (key == KEY_UP){
        (*home)->player->x += (*home)->player->pdx;
        (*home)->player->y += (*home)->player->pdy;
    }
    
    if (key == KEY_DOWN){
        (*home)->player->x -= (*home)->player->pdx;
        (*home)->player->y -= (*home)->player->pdy;
    }

    drawMap(home);
    mlx_put_image_to_window((*home)->mlx, (*home)->win, (*home)->img->img, 0, 0);
    return (0);
}

int main(void)
{
    t_vars *home;
    home = malloc(sizeof(t_vars));
    ParserReader("/Users/aerrajiy/Desktop/Github_42/Cub3d_parsing/map/map.cub", &home->parser);
    init_window_image(&home);
    drawMap(&home);
    mlx_put_image_to_window(home->mlx, home->win, home->img->img, 0, 0);
    mlx_hook(home->win, 2, 1L << 0, moveHandler, &home);
    mlx_loop(home->mlx);
    
    return (0);
}