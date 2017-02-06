/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_precision.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvogee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/15 16:25:31 by mvogee            #+#    #+#             */
/*   Updated: 2016/12/15 16:25:32 by mvogee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** pad_copy
** pads a copy of original with 0s
** returns padded copy of original
*/

static char	*pad_copy(char *original, int sign, int pad, int totallen)
{
	char	*ret;
	int		count;

	count = 0;
	ret = (char*)pf_memalloc(totallen);
	if (!ret)
		return (NULL);
	if (sign)
	{
		ret[0] = '-';
		count++;
	}
	while (count - sign < pad)
	{
		ret[count] = '0';
		count++;
	}
	while (*original)
	{
		ret[count] = *original;
		count++;
		original++;
	}
	ret[totallen] = '\0';
	return (ret);
}

/*
** do_precision
** takes output and determines whether or not precision needs to be done
** variables:
** len = how many zeros will be added
** precision = total length to allocate
** minussign = flag for if there it is a negative number
** returns new string with precision done if needed
*/

char		*do_precision(char *output, int precision)
{
	int		len;
	int		count;
	int		minussign;
	char	*retoutp;

	len = 0;
	count = 0;
	minussign = (output[0] == '-' ? 1 : 0);
	if (minussign)
		output++;
	len = pf_strlen(output);
	if (len < precision)
	{
		len = precision - len;
		precision += minussign;
		retoutp = pad_copy(output, minussign, len, precision);
	}
	if (minussign)
		output--;
	if (len >= precision)
		retoutp = pf_strdup(output);
	pf_memdel((void**)&output);
	return (retoutp);
}
