/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvogee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/22 14:17:29 by mvogee            #+#    #+#             */
/*   Updated: 2017/02/22 19:42:47 by mvogee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	signer(char s)
{
	if (s == '-')
		return (-1);
	return (1);
}

long		ft_atol(const char *str)
{
	long	retval;
	int		count;
	int		sign;

	count = 0;
	sign = 1;
	retval = 0;
	if (ft_strlen((char*)str) == 0)
		return (0);
	while (!ft_isalnum(*str) && *str != '+' && *str != '-' && ft_isascii(*str))
		str++;
	if (*str == '-' || *str == '+')
	{
		sign = signer(*str);
		str++;
	}
	while (*str == '0')
		str++;
	while (ft_isdigit(str[count]) != 0)
	{
		retval = (retval * 10) + (int)str[count] - '0';
		count++;
	}
	return (retval * sign);
}
