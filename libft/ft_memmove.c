/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvogee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/25 21:01:09 by mvogee            #+#    #+#             */
/*   Updated: 2016/09/29 15:30:05 by mvogee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	void *tmp;

	tmp = dst;
	if (dst < src)
	{
		while ((size_t)(dst - tmp) < len)
			*(unsigned char*)dst++ = *(unsigned char*)src++;
	}
	else
	{
		while (len-- > 0)
			((unsigned char*)dst)[len] = ((unsigned char*)src)[len];
	}
	return (tmp);
}
