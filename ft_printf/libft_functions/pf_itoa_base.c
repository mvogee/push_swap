/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvogee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/05 17:52:42 by mvogee            #+#    #+#             */
/*   Updated: 2017/01/16 23:35:11 by mvogee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

char	*pf_itoa_base(uintmax_t n, int b)
{
	int			len;
	uintmax_t	ntmp;
	char		*ret;
	char		*nums;

	nums = "0123456789abcdef";
	ntmp = n;
	len = 0;
	while (ntmp / b)
	{
		len++;
		ntmp /= b;
	}
	len++;
	ret = (char*)pf_memalloc(len + 1);
	if (!ret)
		return (0);
	ret[len] = '\0';
	while (--len >= 0)
	{
		ret[len] = nums[n % b];
		n /= b;
	}
	return (ret);
}
