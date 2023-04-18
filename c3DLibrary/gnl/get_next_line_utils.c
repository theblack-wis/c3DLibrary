/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aerrajiy <aerrajiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 21:33:15 by aerrajiy          #+#    #+#             */
/*   Updated: 2023/04/18 00:02:16 by aerrajiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/gnl.h"

char	*ft_strjoin_gnl(char *s1, char *s2)
{
	int		len;
	int		i;
	int		s;
	char	*joined;

	s = 0;
	i = 0;
	if (!s1)
		s1 = ft_strdup("");
	len = ft_strlen((char *)s1) + ft_strlen((char *)s2);
	joined = malloc((len + 1) * sizeof(char));
	if (joined == NULL)
		return (NULL);
	while (((char *)s1)[i] != '\0')
		joined[s++] = ((char *)s1)[i++];
	i = 0;
	while (((char *)s2)[i] != '\0')
		joined[s++] = ((char *)s2)[i++];
	joined[s] = '\0';
	free(s1);
	return (joined);
}
