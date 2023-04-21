/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aerrajiy <aerrajiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 02:25:46 by aerrajiy          #+#    #+#             */
/*   Updated: 2023/04/21 00:55:26 by aerrajiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

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

int line_has_zero(char *line)
{
    int i;

    i = 0;
    while (line[i])
    {
        if (line[i] == '0')
            return (1);
        i++;
    }
    return (0);
}

int has_empty_line(char **map)
{
    int i;

    i = 0;
    while(map[i])
        if (!map[i++][0])
            return (1);
    return (0);
}

int is_player_or_space(char elemnt)
{
    return (elemnt == 'N' || elemnt == 'S' || elemnt == 'W' || elemnt == 'W' || elemnt == '0');
}