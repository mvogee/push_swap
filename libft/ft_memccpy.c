/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvogee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/26 23:10:56 by mvogee            #+#    #+#             */
/*   Updated: 2016/09/27 10:19:08 by mvogee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned int	count;
	unsigned char	*tmpdst;
	unsigned char	*tmpsrc;
	unsigned char	chr;

	count = 0;
	tmpdst = (unsigned char*)dst;
	tmpsrc = (unsigned char*)src;
	chr = (unsigned char)c;
	while (count < n)
	{
		if ((*tmpdst++ = *tmpsrc++) == chr)
			return (tmpdst);
		count++;
	}
	return (NULL);
}
