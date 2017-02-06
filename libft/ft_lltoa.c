/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lltoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvogee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/04 19:38:45 by mvogee            #+#    #+#             */
/*   Updated: 2016/12/04 19:38:46 by mvogee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		add_chars(char *retstr, intmax_t n, int len)
{
	uintmax_t n2;

	if (n < 0)
	{
		retstr[0] = '-';
		n2 = (uintmax_t)(n * -1);
		len--;
		while (len > 0 && retstr[len] != '-')
		{
			retstr[len] = n2 % 10 + '0';
			n2 = n2 / 10;
			len--;
		}
	}
	else
	{
		n2 = (uintmax_t)n;
		while (len > 0)
		{
			len--;
			retstr[len] = n % 10 + '0';
			n = n / 10;
		}
	}
}

char			*ft_lltoa(intmax_t n)
{
	int					len;
	char				*retstr;
	long long int		ntmp;

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
		add_chars(retstr, n, len);
	retstr[len] = '\0';
	return (retstr);
}
