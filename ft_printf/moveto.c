/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moveto.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvogee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/14 13:47:01 by mvogee            #+#    #+#             */
/*   Updated: 2016/12/14 13:47:02 by mvogee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** find_specifier_pos
** finds the index of a specifer character
** if an invalid specifer character occurs the negative index is returned
** returns index of the specifer
*/

int		find_specifier_pos(char *format)
{
	int pos;

	pos = 0;
	while (checkfor_specifier(format[pos]) != 1)
	{
		if (checkfor_all(format[pos]) == 0 || !format[pos])
		{
			return (pos * -1);
		}
		pos++;
	}
	return (pos);
}

/*
** moveto_specifer
** moves format to the character after the specifer
** or end of the string, whichever comes first
** returns modified format
*/

char	*moveto_specifier(char *format)
{
	while (checkfor_specifier(*format) != 1 && *format)
	{
		if (checkfor_all(*format) == 0 && *format)
			return (format + 1);
		else if (checkfor_all(*format) == 0)
			return (format);
		format++;
	}
	if (!*format)
		return (format);
	else
		return (format + 1);
}

char	*print_moveto(char *format, int len)
{
	write(1, format, len);
	return (format + len);
}
