/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aerrajiy <aerrajiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 02:31:37 by mabahani          #+#    #+#             */
/*   Updated: 2023/04/17 23:59:39 by aerrajiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lib.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dstlen;
	size_t	srclen;
	size_t	i;

	if (!dst || !src)
		return (0);
	dstlen = 0;
	srclen = 0;
	i = 0;
	while (src[srclen] != '\0')
		srclen++;
	if (dstsize == 0 && !dst)
		return (srclen);
	while (dst[dstlen] != '\0')
		dstlen++;
	if (dstsize <= dstlen || dstsize == 0)
		return (srclen + dstsize);
	while (i < dstsize - dstlen - 1 && src[i] != '\0')
	{
		dst[dstlen + i] = src[i];
		i++;
	}
	dst[dstlen + i] = '\0';
	return (dstlen + srclen);
}
