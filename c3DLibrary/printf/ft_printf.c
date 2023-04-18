/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aerrajiy <aerrajiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 18:26:53 by aerrajiy          #+#    #+#             */
/*   Updated: 2023/04/18 01:09:57 by aerrajiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../include/ft_printf.h"

int	ft_printf(int fd, const char *str, ...)
{
	va_list	ptr;
	int		i;
	int		count;

	i = 0;
	count = 0;
	va_start(ptr, str);
	if (safezone(str))
		return (0);
	while (str[i])
	{
		if (str[i] == '%')
		{
			count += show(fd, ptr, str[i + 1]);
			i++;
		}
		else
			count += ft_putchar(fd, str[i]);
		i++;
	}
	return (count);
}
