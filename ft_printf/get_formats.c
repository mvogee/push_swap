/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_formats.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvogee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/14 20:38:15 by mvogee            #+#    #+#             */
/*   Updated: 2016/12/14 20:38:16 by mvogee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** get_precision
** extracts the precision from the mods
** returns -1 if no precision
** returns precision
*/

int		get_precision(char *mods, va_list arglist)
{
	int		precision;
	int		count;
	char	*precis;

	count = 0;
	precis = NULL;
	while (mods && *mods != '.' && *mods)
		mods++;
	if (!mods || !*mods)
		return (-1);
	mods++;
	if (*mods == '*')
		precision = va_arg(arglist, int);
	else
	{
		while (pf_isdigit(mods[count]) == 1 && mods[count])
			count++;
		precis = pf_strsub(mods, 0, count);
		precision = pf_atoi(precis);
		if (precis)
			free(precis);
	}
	return (precision);
}

/*
** get_minwidth
** finds the min width in mods if any
** returns the min width
*/

int		get_minwidth(char *mods, va_list arglist)
{
	int		minwidth;
	int		count;
	char	*minw;

	count = 0;
	if (!mods)
		return (0);
	while ((pf_isdigit(*mods) != 1 && *mods != '.' && *mods != '*' && *mods) ||
		*mods == '0')
		mods++;
	if (!*mods || *mods == '.')
		minwidth = 0;
	else if (*mods == '*')
		minwidth = va_arg(arglist, int);
	else
	{
		while (pf_isdigit(mods[count]) == 1 && mods[count])
			count++;
		minw = pf_strsub(mods, 0, count);
		minwidth = pf_atoi(minw);
		if (minw)
			free(minw);
	}
	return (minwidth);
}

/*
** get_justify
** 1 MEANS LEFT JUSTIFY AND 0 MEANS RIGHT JUSTIFY
*/

int		get_justify(char *mods)
{
	while (*mods)
	{
		if (*mods == '-')
			return (1);
		mods++;
	}
	return (0);
}

/*
** get_pad
** returns the correct padding character
*/

char	get_pad(char *mods)
{
	char	pad;

	pad = ' ';
	if (checkthrough_for(mods, '.'))
		return (pad);
	while (*mods && (pf_isdigit(*mods) != 1 || *mods == '0'))
	{
		if (*mods == '0')
			pad = '0';
		mods++;
	}
	if (checkthrough_for(mods, '-'))
		pad = ' ';
	return (pad);
}

/*
** get_indexof
** finds the index of c in str
** returns index or -1 if c does not exist in str
*/

int		get_indexof(char *str, char c)
{
	int		index;

	index = 0;
	while (*str)
	{
		if (*str == c)
			return (index);
		str++;
		index++;
	}
	return (-1);
}
