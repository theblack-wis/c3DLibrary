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

int count_line_number(char *file)
{
    int fd;
    int count;
    char *line;
    char **data;

    count = 0;
    fd = open(file, O_RDONLY);
    while ((line = get_next_line(fd)))
    {
        data = ft_split(line, ' ');
        if (check_structur(data[0]) == 0)
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
void put_char(char *line, int size)
{
    int i;

    i = 0;
    while (i < size)
    {
        if (line[i] == '\n')
            line[i] = 'x';
        i++;
    }
}

char    *allocat_saver(char *line, int size)
{
    char *saver;

    saver = ft_calloc(1, size + 1);
    ft_bchar(saver, 'x', size);
    ft_strlcpy(saver, line, size + 1);
    return (saver);
}

void    read_map(char *file, t_parser **parser)
{
    t_reading   data;
    int         max_len;
    int         line_number;
    int         map_count;

    map_count = 0;
    line_number = count_line_number(file);
    max_len = who_is_the_big_line(file);

    (*parser)->map = ft_calloc(1, sizeof(char *) * (line_number + 1));
    (*parser)->map[line_number] = NULL;
    data.fd = open(file, O_RDONLY);
    while ((data.line = get_next_line(data.fd)))
    {
        data.data = ft_split(data.line, ' ');
        if (data.data[0][0] != '\n' && !check_structur(data.data[0]))
            (*parser)->map[map_count++] = allocat_saver(remove_new_line(data.line), max_len);
        free(data.line);
        free_me(data.data);
    }
}