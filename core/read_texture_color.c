/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_color.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aerrajiy <aerrajiy@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 06:55:17 by aerrajiy          #+#    #+#             */
/*   Updated: 2023/04/18 06:55:17 by aerrajiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int check_structur(char *data)
{
    char all[9][3] = {"NO", "SO", "WE", "EA", "F", "C"};
    int i = 0;
    while (i < 6)
    {
        if (!ft_strcmp(data, all[i]))
            return (1);
        i++;
    }
    return (0);
}

int table_size(char **table)
{
    int i = 0;
    while (table[i])
        i++;
    return (i);
}



void    read_texture_color(char *file, t_parser **parser)
{
    t_reading data;

    data.texture_count = 0;
    data.color_count = 0;
    (*parser)->texture = ft_calloc(1, sizeof(char *) * 5);
    (*parser)->colors = ft_calloc(1, sizeof(char *) * 3);
    data.fd = open(file, O_RDONLY);
    while ((data.line = get_next_line(data.fd)) != NULL)
    {
        data.data = ft_split(data.line, ' ');
        if (!ft_strcmp(data.data[0], "NO") || !ft_strcmp(data.data[0], "SO") || !ft_strcmp(data.data[0], "WE") || !ft_strcmp(data.data[0], "EA"))
        {
            (*parser)->texture[data.texture_count] = ft_strdup(remove_new_line(data.line));
            data.texture_count++;
        }
        else if (!ft_strcmp(data.data[0], "F") || !ft_strcmp(data.data[0], "C"))
        {
            (*parser)->colors[data.color_count] = ft_strdup(remove_new_line(data.line));
            data.color_count++;
        }
        free(data.line);
        if (data.data[0][0] != '\n' &&  ((data.texture_count == 4 && data.color_count == 2 ) || !check_structur(data.data[0]))){
            free_me(data.data);
            break;
        }
        free_me(data.data);
    }
    close(data.fd);
    check_texture_color(*parser);
}

void    check_texture_color(t_parser *parser)
{
    if (table_size(parser->texture) != 4){
        ft_printf(2, "Error in texture\n");
        exit(1);
    }

    if (table_size(parser->colors) != 2){
        ft_printf(2, "Error in color\n");
        exit(1);
    }
}