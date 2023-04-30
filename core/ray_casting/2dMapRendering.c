/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2dMapRendering.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aerrajiy <aerrajiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 12:01:45 by aerrajiy          #+#    #+#             */
/*   Updated: 2023/04/30 15:27:07 by aerrajiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  "../include/header.h"

void getPlayerPosition(t_vars **home)
{
    int i = 0;
    int j;

    (*home)->player->move_x = 32;
    (*home)->player->move_y = 32;
    
    while ((*home)->parser->map->map[i])
    {
        j = 0;
        while ((*home)->parser->map->map[i][j])
        {
            if ((*home)->parser->map->map[i][j] == 'N')
            {
                (*home)->player->x = j;
                (*home)->player->y = i;
                return ;
            }
            j++;
        }
        i++;
    }
}

void    init_window_image(t_vars **home)
{
    int col;
    int row;

    col = ((*home)->parser->map->col - 1) * 64;
    row = ((*home)->parser->map->row) * 64;
    
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

void draw_walls(t_vars **home)
{
    int i;
    int j;
    int x;
    int y;

    i = 0;
    x = 0;
    y = 0;
    while (i < (*home)->parser->map->row)
    {
        j = 0;
        while (j < (*home)->parser->map->col)
        {
            if ((*home)->parser->map->map[i][j] == '1')
            {
                while (x < 63)
                {
                    y = 0;
                    while (y < 63)
                        my_mlx_pixel_put((*home)->img, x + (j * 64), y++ + (i * 64), 0x00FF0000);
                    x++;
                }
                x = 0;
            }

            if ((*home)->parser->map->map[i][j] == '0' || (*home)->parser->map->map[i][j] == 'N')
            {
                while (x < 63)
                {
                    y = 0;
                    while (y < 63)
                        my_mlx_pixel_put((*home)->img, x + (j * 64), y++ + (i * 64), 0x00736762);
                    x++;
                }
                x = 0;
            }
            j++;
        }
        i++;
    }
    my_mlx_pixel_put((*home)->img, ((*home)->player->x * 64) + (*home)->player->move_x, ((*home)->player->y * 64) + (*home)->player->move_y, 0x00000000);
}

int MoveHandler(int key, t_vars **home)
{
    (void)home;
    if (key == 53)
        exit(0);
    if (key == KEY_UP){
        if (((*home)->player->y * 64) + ((*home)->player->move_y - 10) <= 64)
            return (0);
        (*home)->player->move_y -= 10;
    }
    if (key == KEY_DOWN){
        if (((*home)->player->y * 64) + ((*home)->player->move_y + 10) >= (*home)->win_width - 64)
            return (0);
        (*home)->player->move_y += 10;
    }
    if (key == KEY_LEFT){
        if (((*home)->player->x * 64) + ((*home)->player->move_x - 10) <= 64)
            return (0);
        (*home)->player->move_x -= 10;
    }
    if (key == KEY_RIGHT){
        if (((*home)->player->x * 64) + ((*home)->player->move_x + 10) >= (*home)->win_height - 64)
            return (0);
        (*home)->player->move_x += 10;
    }
    draw_walls(home);
    mlx_put_image_to_window((*home)->mlx, (*home)->win, (*home)->img->img, 0, 0);
    return (0);
}

int main(void)
{
    t_vars *home;
    home = malloc(sizeof(t_vars));
    ParserReader("/Users/aerrajiy/Desktop/Github_42/Cub3d_parsing/map/map.cub", &home->parser);
    init_window_image(&home);
    draw_walls(&home);
    mlx_put_image_to_window(home->mlx, home->win, home->img->img, 0, 0);
    mlx_key_hook(home->win, MoveHandler, &home);
    mlx_loop(home->mlx);
    return (0);
}