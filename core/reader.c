/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aerrajiy <aerrajiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 01:38:55 by aerrajiy          #+#    #+#             */
/*   Updated: 2023/04/18 23:20:00 by aerrajiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

char *remove_new_line(char *str)
{
    int i = 0;
    while (str[i])
    {
        if (str[i] == '\n')
            str[i] = '\0';
        i++;
    }
    return (str);
}

void    printParser(t_parser *parser)
{
    ft_printf(1, "Textures: \n");
    ft_printf(1, "%s \n%s \n%s \n%s\n\n", parser->texture[0], parser->texture[1], parser->texture[2], parser->texture[3]);
    ft_printf(1, "Colors: \n");
    ft_printf(1, "%s \n%s\n\n", parser->colors[0], parser->colors[1]);
}

void    printMap(t_parser *parser)
{
    int i = 0;
    int j = 0;
    
    ft_printf(1, "Map: \n");

    while (parser->map[i])
    {
        j = 0;
        while (parser->map[i][j])
        {
            ft_printf(1, "%c", parser->map[i][j]);
            j++;
        }
        ft_printf(1, "\n");
        i++;
    }
}

int main(){
    t_parser *parser;
    
    parser = malloc(sizeof(t_parser));
    read_texture_color("map/map.cub", &parser);
    printParser(parser);
    read_map("map/map.cub", &parser);
    printMap(parser);
    free_me(parser->texture);
    free_me(parser->colors);
    free_me(parser->map);
    free(parser);
}