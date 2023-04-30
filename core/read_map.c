/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aerrajiy <aerrajiy@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 07:29:44 by aerrajiy          #+#    #+#             */
/*   Updated: 2023/04/18 07:29:44 by aerrajiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void ft_error(const char *pointer, char *str)
{
    ft_printf(2, pointer, str);
    exit(1);
}

int count_line_number(char *file)
{
    int fd;
    int count;
    char *line;
    char **data;
    int flag;

    flag = 0;
    count = 0;
    fd = open(file, O_RDONLY);
    while ((line = get_next_line(fd)))
    {
        data = ft_split(line, ' ');
        if (data[0][0] != '\n' && !check_structur(data[0]))
            flag = 1;
        if (flag == 1)
            count++;
        free(line);
        free_me(data);
    }
    close(fd);
    return (count);
}

int who_is_the_big_line(char *file)
{
    int fd;
    unsigned long max_len;
    char *line;
    char **data;

    max_len = 0;
    fd = open(file, O_RDONLY);
    while ((line = get_next_line(fd)))
    {
        data = ft_split(line, ' ');
        if (check_structur(data[0]) == 0)
            if (ft_strlen(line) > max_len)
                max_len = ft_strlen(line);
        free(line);
        free_me(data);
    }
    close(fd);
    return (max_len);
}

char    *allocat_saver(char *line, int size)
{
    char *saver;

    saver = ft_calloc(1, size + 1);
    ft_strlcpy(saver, line, size + 1);
    return (saver);
}

void    map_Filter(t_map *map)
{
    int i;
    int j;

    i = 0;
    j = 0;
    
    if (has_empty_line(map->map) || line_has_zero(map->map[0]) || line_has_zero(map->map[map->row - 1]))
        ft_error("map error 1 \n", NULL);
    while (map->map[i])
    {
        j = 0;
        while (map->map[i][j]){
            if (!is_player_or_space(map->map[i][j]) && map->map[i][j] != '1' && map->map[i][j] != ' ' && map->map[i][j] != '\t')
                ft_error("map error 2 \n", NULL);
            if (is_player_or_space(map->map[i][j]))
            
                if (j == 0 || !map->map[i - 1][j] || !map->map[i + 1][j] || !map->map[i][j + 1] || map->map[i - 1][j] == ' ' || map->map[i + 1][j] == ' ' || map->map[i][j + 1] == ' ')
                {
                    ft_printf(2, "map error 3 : [%d] | [%d] \n", i, j);
                    exit(1);
                }
            j++;
        }
        i++;
    }
}

void    read_map(char *file, t_parser **parser)
{
    t_reading   data;
    int         map_count;
    int         flag;

    (*parser)->map = ft_calloc(1, sizeof(t_map));   
    map_count = 0;
    (*parser)->map->row = count_line_number(file);
    (*parser)->map->col = who_is_the_big_line(file);
    flag = 0;

    (*parser)->map->map = ft_calloc(1, sizeof(char *) * ((*parser)->map->row + 1));
    (*parser)->map->map[(*parser)->map->row] = NULL;
    data.fd = open(file, O_RDONLY);
    while ((data.line = get_next_line(data.fd)))
    {
        data.data = ft_split(data.line, ' ');
        if (data.data[0][0] != '\n' && !check_structur(data.data[0]))
            flag = 1;

        if (flag == 1)
            (*parser)->map->map[map_count++] = allocat_saver(remove_new_line(data.line), (*parser)->map->col);
        free(data.line);
        free_me(data.data);
    }
}