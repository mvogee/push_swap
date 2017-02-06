/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spec_up_d.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvogee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/14 16:32:51 by mvogee            #+#    #+#             */
/*   Updated: 2016/12/14 16:32:52 by mvogee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static char	*get_output(char *mods, va_list arglist, int precision)
{
	int		len;
	char	*ret;

	len = get_len(mods);
	if (len == L)
		ret = pf_lltoa(va_arg(arglist, long));
	else if (len == LL)
		ret = pf_lltoa(va_arg(arglist, long long));
	else if (len == J)
		ret = pf_lltoa(va_arg(arglist, intmax_t));
	else if (len == Z)
		ret = pf_lltoa(va_arg(arglist, size_t));
	else if (len == HH)
		ret = pf_lltoa(va_arg(arglist, int));
	else if (len == H)
		ret = pf_lltoa(va_arg(arglist, long));
	else
		ret = pf_lltoa(va_arg(arglist, long));
	if (!ret)
		return (NULL);
	if (ret[0] == '0' && ret[1] == '\0' && precision == 0)
		ret[0] = 0;
	return (ret);
}

int			spec_up_d(char *mods, va_list arglist)
{
	int		precision;
	int		minwidth;
	int		retlen;
	char	*output;

	minwidth = get_minwidth(mods, arglist);
	precision = get_precision(mods, arglist);
	output = get_output(mods, arglist, precision);
	if (!output)
		return (0);
	output = do_precision(output, precision);
	if (!output)
		return (0);
	output = do_minwidth(output, minwidth, mods, 'D');
	if (!output)
		return (0);
	retlen = printf_free(output);
	return (retlen);
}
