/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_signs.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvogee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/05 16:03:09 by mvogee            #+#    #+#             */
/*   Updated: 2017/01/05 16:03:31 by mvogee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** get_sign
** gets the sign to be written if any
** returns the sign character or null character if no sign is to  be written
*/

char	get_sign(char *original, char *mods)
{
	if (original[0] == '-')
		return ('-');
	else
	{
		if (checkthrough_for(mods, '+'))
			return ('+');
		else if (checkthrough_for(mods, ' '))
			return (' ');
	}
	return ('\0');
}

/*
** hexoct_sign
** given a hex or oct specifier add the correct prefix to the string
** returns prefixed string
*/

char	*hexoct_sign(char spec, char *original)
{
	char *ret;

	if (spec == 'X')
		ret = pf_strjoin("0X", original);
	else if (spec == 'x' || spec == 'p')
		ret = pf_strjoin("0x", original);
	else if ((spec == 'o' || spec == 'O') &&
		!(original[0] == '0' && original[1] == '\0'))
		ret = pf_strjoin("0", original);
	else
		ret = pf_strdup(original);
	return (ret);
}

/*
** so_sign
** finds and adds the correct sign to the string
** returns signed string or copy of original if no sign is written
*/

char	*do_sign(char *original, char *mods)
{
	char	sign;
	char	*ret;
	char	*s;

	sign = get_sign(original, mods);
	if (sign != '-')
		s = (sign == '+' ? "+" : " ");
	else
		s = "-";
	if (sign && sign != '-')
		ret = pf_strjoin(s, original);
	else
		ret = pf_strdup(original);
	return (ret);
}
