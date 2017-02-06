/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvogee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/28 14:37:42 by mvogee            #+#    #+#             */
/*   Updated: 2016/09/28 14:54:32 by mvogee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int				strlen;
	unsigned int	count;
	char			*retstr;

	strlen = (int)ft_strlen((char*)s);
	count = 0;
	if (!(retstr = (char*)malloc(sizeof(char) * strlen + 1)))
		return (NULL);
	while (s[count])
	{
		retstr[count] = f(count, s[count]);
		count++;
	}
	retstr[count] = '\0';
	return (retstr);
}
