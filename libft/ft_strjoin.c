/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvogee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/28 16:17:10 by mvogee            #+#    #+#             */
/*   Updated: 2016/09/28 16:47:14 by mvogee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		len;
	int		count;
	int		index;
	char	*retstr;

	count = 0;
	index = 0;
	len = (int)(ft_strlen((char*)s1) + ft_strlen((char*)s2));
	if (!(retstr = (char*)malloc(sizeof(char) * len + 1)))
		return (NULL);
	while (s1[index])
	{
		retstr[count] = s1[index];
		count++;
		index++;
	}
	index = 0;
	while (s2[index])
	{
		retstr[count] = s2[index];
		count++;
		index++;
	}
	retstr[count] = '\0';
	return (retstr);
}
