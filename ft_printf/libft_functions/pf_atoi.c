/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvogee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/14 21:55:36 by mvogee            #+#    #+#             */
/*   Updated: 2017/01/16 23:31:26 by mvogee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static	int	signer(char s)
{
	if (s == '-')
		return (-1);
	return (1);
}

static	int	too_big_check(int retval, int count, int sign)
{
	if (count > 19)
	{
		if (sign == -1)
			return (0);
		return (-1);
	}
	return (retval * sign);
}

int			pf_atoi(const char *str)
{
	int		retval;
	int		count;
	int		sign;

	count = 0;
	sign = 1;
	retval = 0;
	if (!str || pf_strlen((char*)str) == 0)
		return (0);
	while (!pf_isalnum(*str) && *str != '+' && *str != '-' && pf_isascii(*str))
		str++;
	if (*str == '-' || *str == '+')
	{
		sign = signer(*str);
		str++;
	}
	while (*str == '0')
		str++;
	while (pf_isdigit(str[count]) != 0)
	{
		retval = (retval * 10) + (int)str[count] - '0';
		count++;
	}
	retval = too_big_check(retval, count, sign);
	return (retval);
}
