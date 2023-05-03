/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel_tools.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aerrajiy <aerrajiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 12:13:17 by aerrajiy          #+#    #+#             */
/*   Updated: 2023/05/03 19:56:02 by aerrajiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  "../../include/header.h"

void	my_mlx_pixel_put(t_img_draw *data, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || y < 0)
		return ;
	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void drawGrid(int x, int y, int lenght,long color, t_vars **home)
{
	int i = 0;
	int j;

	while (i < lenght)
	{
		j = 0;
		
		while (j < lenght)
		{
			my_mlx_pixel_put((*home)->img, (y) + j, (x) + i, color);
			j++;
		}
		i++;
	}
}

void initMapBackGro(t_vars **home)
{
	int i = 0;
	int j;

	while (i < (*home)->win_width)
	{
		j = 0;
		while (j < (*home)->win_height)
			my_mlx_pixel_put((*home)->img, j++, i, 0x000000ff);
		i++;
	}
}