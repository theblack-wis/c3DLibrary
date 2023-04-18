/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bchar.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aerrajiy <aerrajiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 23:07:32 by aerrajiy          #+#    #+#             */
/*   Updated: 2023/04/18 23:15:13 by aerrajiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lib.h"

void	ft_bchar(void *s, char set,size_t n)
{
	size_t	i;

	if (!s)
		return ;
	i = 0;
	while (i < n)
		((unsigned char *) s)[i++] = set;
}
