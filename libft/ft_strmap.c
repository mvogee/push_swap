/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvogee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/28 14:24:19 by mvogee            #+#    #+#             */
/*   Updated: 2016/09/28 14:53:55 by mvogee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	int		strlen;
	int		count;
	char	*retstr;

	strlen = (int)ft_strlen((char*)s);
	count = 0;
	if (!(retstr = (char*)malloc(sizeof(char) * strlen + 1)))
		return (NULL);
	while (s[count])
	{
		retstr[count] = f(s[count]);
		count++;
	}
	retstr[count] = '\0';
	return (retstr);
}
