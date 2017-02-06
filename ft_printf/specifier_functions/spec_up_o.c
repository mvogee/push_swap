/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spec_up_o.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvogee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/14 16:35:22 by mvogee            #+#    #+#             */
/*   Updated: 2016/12/14 16:35:23 by mvogee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static char	*get_output(char *mods, va_list arglist, int precision)
{
	int		len;
	char	*ret;

	len = get_len(mods);
	if (len == L)
		ret = pf_itoa_base((unsigned long)va_arg(arglist, unsigned long), 8);
	else if (len == LL)
		ret = pf_itoa_base((unsigned long long)
			va_arg(arglist, unsigned long long), 8);
	else if (len == J)
		ret = pf_itoa_base((uintmax_t)va_arg(arglist, uintmax_t), 8);
	else if (len == Z)
		ret = pf_itoa_base((unsigned long long)va_arg(arglist, size_t), 8);
	else if (len == HH)
		ret = pf_itoa_base((unsigned short)va_arg(arglist, unsigned long), 8);
	else if (len == H)
		ret = pf_itoa_base((unsigned short)va_arg(arglist, unsigned long), 8);
	else
		ret = pf_itoa_base((unsigned long)va_arg(arglist, unsigned long), 8);
	if (!ret)
		return (NULL);
	if (ret[0] == '0' && ret[1] == '\0' && precision == 0)
		ret[0] = 0;
	return (ret);
}

int			spec_up_o(char *mods, va_list arglist)
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
	if (checkthrough_for(mods, '#') && precision > 0)
		precision--;
	output = do_precision(output, precision);
	if (!output)
		return (0);
	output = do_minwidth(output, minwidth, mods, 'O');
	if (!output)
		return (0);
	retlen = printf_free(output);
	return (retlen);
}
