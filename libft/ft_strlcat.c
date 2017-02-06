/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvogee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/23 14:05:10 by mvogee            #+#    #+#             */
/*   Updated: 2016/09/26 20:11:12 by mvogee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	count;
	size_t	dst_len;

	count = 0;
	while (dst[count] && count < size)
		count++;
	dst_len = count;
	while (src[count - dst_len] && count < size - 1)
	{
		dst[count] = src[count - dst_len];
		count++;
	}
	if (dst_len < size)
		dst[count] = '\0';
	return (dst_len + ft_strlen((char*)src));
}
