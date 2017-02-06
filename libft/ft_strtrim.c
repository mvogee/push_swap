/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvogee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/28 17:16:05 by mvogee            #+#    #+#             */
/*   Updated: 2016/09/28 22:21:22 by mvogee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	int		i;
	int		len;
	char	*str;
	int		count;

	count = 0;
	i = 0;
	len = (int)ft_strlen((char*)s) - 1;
	while ((s[i] == ' ' || s[i] == '\t' || s[i] == '\n' || s[i] == ',') && s[i])
		i++;
	if (s[i] == '\0')
		return ("");
	while (s[len] == ' ' || s[len] == '\t' || s[len] == '\n' || s[len] == ',')
		len--;
	len = len - i + 1;
	if (!(str = (char*)malloc(sizeof(char) * len + 1)))
		return (NULL);
	while (count < len)
	{
		str[count] = s[i];
		count++;
		i++;
	}
	str[count] = '\0';
	return (str);
}
