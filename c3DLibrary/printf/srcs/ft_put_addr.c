/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_addr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aerrajiy <aerrajiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 17:51:36 by aerrajiy          #+#    #+#             */
/*   Updated: 2023/04/18 01:09:26 by aerrajiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../include/ft_printf.h"

int	ft_put_address(int fd, unsigned long int n)
{
	int	count;

	count = 0;
	write(fd, "0x", 2);
	count = ft_put_hex(1, 'x', n);
	return (count + 2);
}
