/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aerrajiy <aerrajiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 23:53:54 by mabahani          #+#    #+#             */
/*   Updated: 2023/04/17 23:59:39 by aerrajiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lib.h"

typedef struct s_norm_join
{
	int		len;
	int		i;
	int		s;
	char	*joined;
	int		check;
}	t_norm_join;

char	*ft_strjoin(char *s1, char *s2)
{
	t_norm_join	data;

	data.s = 0;
	data.i = 0;
	data.check = 0;
	if (!s1)
	{
		data.check = 1;
		s1 = malloc(1);
		s1[0] = '\0';
	}
	data.len = ft_strlen((char *)s1) + ft_strlen((char *)s2);
	data.joined = malloc((data.len + 1) * sizeof(char));
	if (data.joined == NULL)
		return (NULL);
	while (((char *)s1)[data.i] != '\0')
		data.joined[data.s++] = ((char *)s1)[data.i++];
	data.i = 0;
	while (((char *)s2)[data.i] != '\0')
		data.joined[data.s++] = ((char *)s2)[data.i++];
	data.joined[data.s] = '\0';
	if (data.check)
		free(s1);
	return (data.joined);
}

char	*ft_strjoin_with_space(char *s1, char *s2)
{
	t_norm_join	data;

	data.s = 0;
	data.i = 0;
	data.check = 0;
	if (!s1)
	{
		data.check = 1;
		s1 = malloc(1);
		s1[0] = '\0';
	}
	data.len = ft_strlen((char *)s1) + ft_strlen((char *)s2);
	data.joined = malloc((data.len + 2) * sizeof(char));
	if (data.joined == NULL)
		return (NULL);
	while (((char *)s1)[data.i] != '\0')
		data.joined[data.s++] = ((char *)s1)[data.i++];
	data.joined[data.s++] = ' ';
	data.i = 0;
	while (((char *)s2)[data.i] != '\0')
		data.joined[data.s++] = ((char *)s2)[data.i++];
	data.joined[data.s] = '\0';
	if (data.check)
		free(s1);
	return (data.joined);
}
