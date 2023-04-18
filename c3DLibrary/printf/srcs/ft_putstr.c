/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aerrajiy <aerrajiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 17:50:31 by aerrajiy          #+#    #+#             */
/*   Updated: 2023/04/18 01:09:45 by aerrajiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../include/ft_printf.h"

int	ft_putstr(int fd, char *s)
{
	int	i;

	if (!s)
		return (ft_putstr(fd, "(null)"));
	i = 0;
	while (s[i])
		write(fd, &s[i++], 1);
	return (ft_strlen(s));
}
