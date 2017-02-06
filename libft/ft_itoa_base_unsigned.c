/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base_unsigned.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvogee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 22:27:34 by mvogee            #+#    #+#             */
/*   Updated: 2016/12/12 22:27:38 by mvogee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_len(uintmax_t value, int base)
{
	int	len;

	len = 0;
	while (value / base)
	{
		value = value / base;
		len++;
	}
	return (len + 1);
}

char		*ft_itoa_base_unsigned(uintmax_t value, int base)
{
	int		len;
	char	*ret;
	char	*nums;

	nums = "0123456789abcdef";
	len = get_len(value, base);
	if (!(ret = (char*)malloc(sizeof(char) * len + 1)))
		return (NULL);
	if (value == 0)
		ret[0] = '0';
	while (len-- >= 0 && value != 0)
	{
		ret[len] = *(nums + (value % base));
		value /= base;
	}
	ret[len] = '\0';
	return (ret);
}
