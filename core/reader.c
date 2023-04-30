/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aerrajiy <aerrajiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 01:38:55 by aerrajiy          #+#    #+#             */
/*   Updated: 2023/04/30 11:21:36 by aerrajiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void    printParser(t_parser *parser){
	ft_printf(1, "Textures: \n");
	ft_printf(1, "%s \n%s \n%s \n%s\n\n", parser->texture[0], parser->texture[1], parser->texture[2], parser->texture[3]);
	ft_printf(1, "Colors: \n");
	ft_printf(1, "%s \n%s\n\n", parser->colors[0], parser->colors[1]);
}

void    printMap(t_parser *parser)
{
	int j, i = 0;
	ft_printf(1, "Map :\n");
	while (parser->map->map[i])
	{
		j = 0;
		while (parser->map->map[i][j])
			ft_printf(1, "%c", parser->map->map[i][j++]);
		ft_printf(1, "\n");
		i++;
	}
}

void ParserReader(char *file, t_parser **parser)
{
	(*parser) = malloc(sizeof(t_parser));
	read_texture_color(file, parser);
	texture_color_Filter(*parser);
	read_map(file, parser);
	map_Filter((*parser)->map);
	printParser(*parser);
	printMap(*parser);
}

int main(void)
{
	t_parser *parser;
	ParserReader("map/map.cub", &parser);
}