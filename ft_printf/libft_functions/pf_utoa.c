/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvogee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/05 16:02:48 by mvogee            #+#    #+#             */
/*   Updated: 2017/01/16 23:39:10 by mvogee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

char		*pf_utoa(uintmax_t num)
{
	int			len;
	uintmax_t	ntmp;
	char		*retstr;

	ntmp = num;
	len = 0;
	while (ntmp / 10)
	{
		len++;
		ntmp /= 10;
	}
	len++;
	retstr = (char*)pf_memalloc(len + 1);
	if (!retstr)
		return (NULL);
	retstr[len] = '\0';
	while (--len >= 0)
	{
		retstr[len] = num % 10 + '0';
		num /= 10;
	}
	return (retstr);
}
