/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvogee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/22 19:58:21 by mvogee            #+#    #+#             */
/*   Updated: 2016/09/22 20:00:23 by mvogee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	int count;
	int srclen;

	count = 0;
	srclen = (int)ft_strlen((char*)src);
	while (count < (int)len)
	{
		if (count > srclen)
			dst[count] = '\0';
		else
		{
			dst[count] = src[count];
		}
		count++;
	}
	return (dst);
}
