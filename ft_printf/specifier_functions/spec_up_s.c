/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spec_up_s.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvogee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/14 16:32:14 by mvogee            #+#    #+#             */
/*   Updated: 2016/12/14 16:32:16 by mvogee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static char	*do_string_precision(char *output, int precision)
{
	int		len;
	char	*ret;

	len = pf_strlen(output);
	if (!output)
		return (NULL);
	if (precision < len)
		ret = pf_strsub(output, 0, precision);
	else
		ret = pf_strdup(output);
	pf_memdel((void**)&output);
	return (ret);
}

int			spec_up_s(char *mods, va_list arglist)
{
	int		precision;
	int		minwidth;
	int		retlen;
	char	*output;

	minwidth = get_minwidth(mods, arglist);
	precision = get_precision(mods, arglist);
	output = ft_uni_utf8_str(va_arg(arglist, wchar_t *));
	if (!output)
		output = pf_strdup("(null)");
	if (precision != -1)
		output = do_string_precision(output, precision);
	if (checkthrough_for(mods, '.'))
		mods[get_indexof(mods, '.')] = '_';
	output = do_minwidth(output, minwidth, mods, 'S');
	if (!output)
		return (0);
	retlen = printf_free(output);
	return (retlen);
}
