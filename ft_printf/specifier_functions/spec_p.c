/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spec_p.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvogee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/14 16:32:27 by mvogee            #+#    #+#             */
/*   Updated: 2016/12/14 16:32:29 by mvogee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static char	*get_output(va_list arglist, int precision)
{
	char	*ret;

	ret = pf_itoa_base((uintmax_t)va_arg(arglist, uintmax_t), 16);
	if (!ret)
		return (NULL);
	if (ret[0] == '0' && ret[1] == '\0' && precision == 0)
		ret[0] = 0;
	return (ret);
}

int			spec_p(char *mods, va_list arglist)
{
	int		precision;
	int		minwidth;
	int		retlen;
	char	*output;

	minwidth = get_minwidth(mods, arglist);
	precision = get_precision(mods, arglist);
	output = get_output(arglist, precision);
	if (!output)
		return (0);
	output = do_precision(output, precision);
	if (!output)
		return (0);
	output = do_minwidth(output, minwidth, mods, 'p');
	if (!output)
		return (0);
	retlen = printf_free(output);
	return (retlen);
}
