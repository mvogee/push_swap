/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_findchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvogee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/30 18:54:13 by mvogee            #+#    #+#             */
/*   Updated: 2016/10/30 19:47:18 by mvogee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_findchr(const char *str, char c)
{
	int		count;

	count = 0;
	if (!str)
		return (0);
	while (str[count])
	{
		if (str[count] == c)
			return (count);
		count++;
	}
	if (c == '\0')
		return (count);
	else
		return (-1);
}
