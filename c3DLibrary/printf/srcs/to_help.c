/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_help.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aerrajiy <aerrajiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 22:35:21 by aerrajiy          #+#    #+#             */
/*   Updated: 2023/04/18 01:13:25 by aerrajiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../include/ft_printf.h"

int	show(int fd, va_list ptr, char c)
{
	int	count;

	count = 0;
	if (c == 'c')
		count += ft_putchar(fd, va_arg(ptr, int));
	if (c == 's')
		count += ft_putstr(fd, va_arg(ptr, char *));
	if (c == 'd' || c == 'i')
		count += ft_putnbr(fd, va_arg(ptr, int));
	if (c == 'u')
		count += ft_putunsigned(fd, va_arg(ptr, unsigned));
	if (c == 'x' || c == 'X')
		count += ft_put_hex(fd, c, va_arg(ptr, unsigned));
	if (c == 'p')
		count += ft_put_address(fd, (long) va_arg(ptr, long));
	if (c == '%')
		count += ft_putchar(fd, '%');
	return (count);
}

int	safezone(const char *str)
{
	if (ft_strlen(str) == 1 && str[0] == '%')
		return (1);
	return (0);
}
