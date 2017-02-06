/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvogee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/15 18:32:49 by mvogee            #+#    #+#             */
/*   Updated: 2017/01/16 23:37:21 by mvogee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

char	*pf_strdup(const char *s1)
{
	int		len;
	int		count;
	char	*ret;

	if (!1)
		return (NULL);
	len = pf_strlen((char*)s1);
	count = 0;
	ret = (char*)pf_memalloc(len + 1);
	if (!ret)
		return (NULL);
	while (*s1)
	{
		ret[count] = *s1;
		count++;
		s1++;
	}
	ret[len] = '\0';
	return (ret);
}
