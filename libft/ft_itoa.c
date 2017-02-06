/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvogee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/29 17:25:59 by mvogee            #+#    #+#             */
/*   Updated: 2016/09/29 23:29:24 by mvogee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		add_chars(char *retstr, long n, int len)
{
	if (n < 0)
	{
		retstr[0] = '-';
		n *= -1;
		len--;
		while (len > 0 && retstr[len] != '-')
		{
			retstr[len] = n % 10 + '0';
			n = n / 10;
			len--;
		}
	}
	else
	{
		while (len > 0)
		{
			len--;
			retstr[len] = n % 10 + '0';
			n = n / 10;
		}
	}
}

char			*ft_itoa(int n)
{
	int		len;
	char	*retstr;
	int		ntmp;

	len = 1;
	ntmp = n;
	if (ntmp < 0)
		len++;
	while (ntmp / 10)
	{
		len++;
		ntmp /= 10;
	}
	if (!(retstr = (char*)malloc(sizeof(char) * len + 1)))
		return (NULL);
	else
		add_chars(retstr, (long)n, len);
	retstr[len] = '\0';
	return (retstr);
}
