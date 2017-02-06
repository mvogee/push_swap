/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvogee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/07 10:51:53 by mvogee            #+#    #+#             */
/*   Updated: 2017/01/16 23:37:54 by mvogee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

char	*pf_strjoin(const char *s1, const char *s2)
{
	int		len;
	char	*ret;

	if (!s1 && !s2)
		return (NULL);
	len = pf_strlen((char*)s1) + pf_strlen((char*)s2);
	if (!(ret = (char*)pf_memalloc(len + 1)))
		return (NULL);
	ret[len] = '\0';
	len = 0;
	while (s1 && *s1)
	{
		ret[len] = *s1;
		len++;
		s1++;
	}
	while (s2 && *s2)
	{
		ret[len] = *s2;
		len++;
		s2++;
	}
	return (ret);
}
