/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2dMapRendering.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aerrajiy <aerrajiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 12:01:45 by aerrajiy          #+#    #+#             */
/*   Updated: 2023/05/03 22:27:02 by aerrajiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  "../include/header.h"
#define PI 3.14159 

void draw_line(long color, int x1, int y1, int x2, int y2, t_vars **home)
{
    int dx = abs(x2 - x1);
    int dy = abs(y2 - y1);
    int sx = x1 < x2 ? 1 : -1;
    int sy = y1 < y2 ? 1 : -1;
    int err = dx - dy;
    
    while (x1 != x2 || y1 != y2)
    {
        my_mlx_pixel_put((*home)->img, x1, y1, color);
        int e2 = 2 * err;
        if (e2 > -dy)
        {
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

    (*home)->player->view_a =  0;
    (*home)->player->v_x = sin((*home)->player->view_a) * 5 * -1;
    (*home)->player->v_y = cos((*home)->player->view_a) * 5;


    while ((*home)->parser->map->map[i])
    {
        j = 0;
        while ((*home)->parser->map->map[i][j])
        {
            if ((*home)->parser->map->map[i][j] == 'N')
            {
                (*home)->player->x = (i * 64) + 27 + (*home)->player->v_x;
                (*home)->player->y = ((j * 64) + 27 + (*home)->player->v_y);
                return ;
            }
            j++;
        }
        i++;
    }
}

void RaySBeLike(t_vars **home)
{
    int r, mx, my, mp, dof;
    float rx, ry, ra, xo, yo;

    ra = (*home)->player->view_a;
/*
    float atan = 1 / tan(ra);
    if (ra < M_PI){
        ry = ((((int) (*home)->player->x) >> 6) << 6) - 0.0001;
        rx = ((*home)->player->x - ry) * atan + (*home)->player->y;
        yo = -64; xo = (-1 * yo) * atan;}
    if (ra > M_PI){
        ry = ((((int) (*home)->player->x) >> 6) << 6) + 64;
        rx = ((*home)->player->x - ry) * atan + (*home)->player->y;
        yo = 64; xo = (-1 * yo) * atan;
    }
    while (1)
    {
        if ((*home)->parser->map->map[(int)(ry / 64)][(int)(rx / 64)] == '1')
            break;
        else {
            ry += yo;
            rx += xo;
        }
    }
*/
    float ntan = tan(ra);
    if (ra < M_PI / 2 && ra < (3 * M_PI) / 2){
        rx = ((((int) (*home)->player->y) >> 6) << 6) - 0.0001;
        ry = ((*home)->player->y - rx) * ntan + (*home)->player->x;
        xo = -64; yo = (-1 * xo) * ntan;
    }

    if (ra < M_PI / 2 || ra > (3 * M_PI) / 2){
        rx = ((((int) (*home)->player->y) >> 6) << 6) + 64;
        ry = ((*home)->player->y - rx) * ntan + (*home)->player->x;
        xo = 64; yo = (-1 * xo) * ntan;
    }

    // dprintf(2, "Rx : %f | Ry : %f  |===| ofX : %f | ofY : %f\n", rx, ry, xo, yo);

    // ry += yo;
    // rx += xo;
    
    while (1)
    {
        if ((*home)->parser->map->map[(int)(ry / 64)][(int)(rx / 64)] == '1')
            break;
        else {
            ry += yo;
            rx += xo;
        }
    }
    
    draw_line(0x009acd32,(*home)->player->y + 5,(*home)->player->x + 5,rx, ry,home);
}

void drawMap(t_vars **home)
{
    int i = 0;
    int j;

    initMapBackGro(home);
    while ((*home)->parser->map->map[i])
    {
        j = 0;
        while ((*home)->parser->map->map[i][j])
        {
            if ((*home)->parser->map->map[i][j] == '1')
                drawGrid(i * 64, j * 64, 63, 0x00FFFFFF, home);
            else
                drawGrid(i * 64, j * 64, 63, 0x003f0020, home);
            j++;
        }
        i++;
    }
    
    // Player :
    drawGrid((*home)->player->x, (*home)->player->y, 10, 0x00ff0000, home);
    // Player Victore :

    draw_line(0x00ff0000,
        (*home)->player->y + 5, (*home)->player->x + 5,
        (*home)->player->y + ((*home)->player->v_y * 5) + 5, (*home)->player->x + ((*home)->player->v_x * 5) + 5,
        home
    );
    
    RaySBeLike(home);
    mlx_put_image_to_window((*home)->mlx, (*home)->win, (*home)->img->img, 0, 0);
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
    if (key == KEY_LEFT) {
        (*home)->player->view_a +=  0.2;
        if ((*home)->player->view_a < 0){ (*home)->player->view_a = 2 * PI;}

        (*home)->player->v_x = sin((*home)->player->view_a) * 5 * -1;
        (*home)->player->v_y = cos((*home)->player->view_a) * 5;
    }
    
    if (key == KEY_RIGHT) {
        (*home)->player->view_a -=  0.2;
        if ((*home)->player->view_a > 2*PI){ (*home)->player->view_a = -(2 * PI);}
    
        (*home)->player->v_x = sin((*home)->player->view_a) * 5 * -1;
        (*home)->player->v_y = cos((*home)->player->view_a) * 5;
    }

    if (key == KEY_DOWN){
        (*home)->player->x -= (*home)->player->v_x;
        (*home)->player->y -= (*home)->player->v_y;
    }

    if (key == KEY_UP){
        (*home)->player->x += (*home)->player->v_x;
        (*home)->player->y += (*home)->player->v_y;
    }
    
    drawMap(home);
    return (0);
}

int main(void)
{
    t_vars *home;
    home = malloc(sizeof(t_vars));
    ParserReader("/Users/aerrajiy/Desktop/Github_42/Cub3d_parsing/map/map.cub", &home->parser);
    init_window_image(&home);
    drawMap(&home);
    mlx_hook(home->win, 2, 1L << 0, moveHandler, &home);
    mlx_loop(home->mlx);
    
    return (0);
}