/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvogee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/14 15:05:50 by mvogee            #+#    #+#             */
/*   Updated: 2017/01/16 23:38:31 by mvogee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

char	*pf_strsub(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	count;

	count = 0;
	if (len == 0 || !s)
		return (NULL);
	if (!(substr = (char*)pf_memalloc(len + 1)))
		return (NULL);
	while (count < len)
	{
		substr[count] = s[count + start];
		count++;
	}
	substr[count] = '\0';
	return (substr);
}
