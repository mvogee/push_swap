/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvogee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/25 21:33:30 by mvogee            #+#    #+#             */
/*   Updated: 2016/09/25 22:04:12 by mvogee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*tmpstr;
	size_t			count;

	tmpstr = (unsigned char*)s;
	count = 0;
	while (n > 0)
	{
		if (*tmpstr == (unsigned char)c)
			return ((void*)tmpstr);
		tmpstr++;
		count++;
		n--;
	}
	return (NULL);
}
