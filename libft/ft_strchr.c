/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvogee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/23 20:54:18 by mvogee            #+#    #+#             */
/*   Updated: 2016/09/23 20:58:17 by mvogee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int count;

	count = 0;
	if (c == '\0')
	{
		count = (int)ft_strlen((char*)s) + 1;
		while (count >= 0)
		{
			if (s[count] == (char)c)
				return ((char*)s + count);
			count--;
		}
	}
	while (s[count])
	{
		if (s[count] == (char)c)
			return ((char*)s + count);
		count++;
	}
	return (NULL);
}
