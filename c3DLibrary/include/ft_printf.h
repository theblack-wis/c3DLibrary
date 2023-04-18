/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aerrajiy <aerrajiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 18:11:06 by aerrajiy          #+#    #+#             */
/*   Updated: 2023/04/18 01:08:20 by aerrajiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "lib.h"
# include <fcntl.h>

int	ft_printf(int fd, const char *str, ...);
int	show(int fd, va_list ptr, char c);
int	safezone(const char *str);

int	ft_put_address(int fd, unsigned long int n);
int	ft_putchar(int fd, char c);
int	ft_put_hex(int fd, char base, unsigned long c);
int	ft_putnbr(int fd, int n);
int	ft_putstr(int fd, char *s);
int	ft_putunsigned(int fd, unsigned int n);
int	count_digits(long n);

#endif