/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvogee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/24 11:40:49 by mvogee            #+#    #+#             */
/*   Updated: 2016/09/24 11:43:57 by mvogee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t count;

	count = 0;
	while (count < n)
	{
		if (((unsigned char*)s1)[count] != ((unsigned char*)s2)[count])
			return (((unsigned char*)s1)[count] - ((unsigned char*)s2)[count]);
		count++;
	}
	return (0);
}
