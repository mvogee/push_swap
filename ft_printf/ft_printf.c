/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvogee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 21:18:22 by mvogee            #+#    #+#             */
/*   Updated: 2016/12/13 21:18:24 by mvogee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** print_free
** prints a given allocated string then frees the string
** returns the length of the string printed
*/

int		printf_free(char *output)
{
	int	len;

	len = pf_strlen(output);
	write(1, output, len);
	pf_memdel((void**)&output);
	return (len);
}

/*
** parse_format
** extracts the mods from the format string
** sends the mods to the correct function to deal with the format type
** returns a length gotten from the specifier function
*/

int		parse_format(char *format, va_list arglist)
{
	int		ret;
	int		specpos;
	char	*mods;
	int		(*specifier_funciton)(char *, va_list);

	ret = 0;
	specpos = find_specifier_pos(format);
	if ((specpos <= -1 || !checkfor_all(format[specpos])))
	{
		specpos *= (specpos < 0 ? -1 : 1);
		if ((checkfor_all(format[specpos]) == 0 && format[specpos] != '\0'))
		{
			mods = (!format[specpos] ? NULL : pf_strsub(format, 0, specpos));
			return (spec_invalid(mods, get_minwidth(mods, arglist),
				format[specpos]));
		}
	}
	if (!format[specpos])
		return (0);
	mods = (specpos == 0 ? NULL : pf_strsub(format, 0, specpos));
	specifier_funciton = g_dispatcher(format, specpos);
	ret += specifier_funciton(mods, arglist);
	if (mods)
		pf_memdel((void**)&mods);
	return (ret);
}

/*
** read_format
** counts and prints up till the first %
** sends format starting at the % to parse_format
** moves format pointer to the end of the format specifer
** returns the total number of characters written
*/

int		read_format(char *format, va_list arglist)
{
	int		totallen;
	int		count;

	count = 0;
	totallen = 0;
	while (format[count])
	{
		if (format[count] == '%')
		{
			format = print_moveto(format, count);
			format++;
			totallen += count;
			count = 0;
			totallen += parse_format(format, arglist);
			format = moveto_specifier(format);
		}
		if (*format && *format != '%')
			count++;
	}
	totallen += count;
	format = print_moveto(format, count);
	return (totallen);
}

/*
** chec_char_nulls
** catches for return length being wrong when a null character is
** given as an argument
** simply goes through all the args checking to see if they are a null char
** returns number of null characters given as arguments
*/

int		check_char_nulls(char *format, va_list copy)
{
	int			ret;
	char		c;

	ret = 0;
	c = 'x';
	while (*format)
	{
		while (*format && *format != '%')
			format++;
		(*format ? format++ : format);
		while (checkfor_specifier(*format) != 1 && checkfor_all(*format) == 1)
			format++;
		if (*format && (*format == 'c' || *format == 'C'))
		{
			c = va_arg(copy, int);
			if (c == 0 || !c)
				ret++;
		}
		else if (checkfor_specifier(*format) == 1 && *format != '%')
			(void)va_arg(copy, long long int);
	}
	return (ret);
}

/*
** ft_printf
** main kickoff function
** initializes variadic variables and starts the function
** returns number of characters written
*/

int		ft_printf(char *format, ...)
{
	va_list		arglist;
	va_list		copy;
	int			len;

	va_start(arglist, format);
	va_copy(copy, arglist);
	len = 0;
	if (format)
	{
		len = read_format(format, arglist);
		len += check_char_nulls(format, copy);
	}
	va_end(arglist);
	va_end(copy);
	return (len);
}
