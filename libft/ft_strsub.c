/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvogee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/28 15:54:24 by mvogee            #+#    #+#             */
/*   Updated: 2016/09/28 16:12:46 by mvogee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	count;

	count = 0;
	if (!(substr = (char*)malloc(sizeof(char) * len + 1)))
		return (NULL);
	while (count < len)
	{
		substr[count] = s[count + start];
		count++;
	}
	substr[count] = '\0';
	return (substr);
}
