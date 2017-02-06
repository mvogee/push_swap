/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_minwidth.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvogee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/16 21:18:22 by mvogee            #+#    #+#             */
/*   Updated: 2016/12/16 21:18:24 by mvogee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** finish_pad
** the first if conditions are taking into account signs that have been placed
** add the padding to the original string
** returns the modified string with pre padding done
*/

static char	*finish_pad(char *original, char *output, char pad, int minwidth)
{
	int		len;
	int		count;

	if ((output[0] == '-' || output[0] == '+' || output[0] == ' ' ||
		output[0] == '0') && output[1] != 'x' && output[1] != 'X')
		count = 1;
	else if (output[0] == '0' && (output[1] == 'x' || output[1] == 'X'))
		count = 2;
	else
		count = 0;
	len = minwidth - pf_strlen(original);
	while (count < minwidth)
	{
		if (count < len)
			output[count] = pad;
		else if (count >= len && original)
		{
			output[count] = *original;
			original++;
		}
		count++;
	}
	return (output);
}

/*
** do_justify_pad
** add the padding char to the original string
** returns the padded string
*/

static char	*do_justify_pad(char *original, int minwidth)
{
	char	*output;
	int		count;

	count = 0;
	output = (char*)pf_memalloc(minwidth + 1);
	if (!output)
		return (NULL);
	output[minwidth] = '\0';
	while (original && *original)
	{
		output[count] = *original;
		count++;
		original++;
	}
	while (count < minwidth)
	{
		output[count] = ' ';
		count++;
	}
	return (output);
}

/*
** pad_zero
** if else conditions deal with keeping the sign in the right place
** returns the padded original string gotten from finish_pad
*/

static char	*pad_zero(char *original, int minwidth, char spec)
{
	char	*output;
	int		count;
	int		len;

	count = 0;
	if (!(output = (char*)pf_memalloc(minwidth + 1)))
		return (NULL);
	output[minwidth] = '\0';
	if (original && (spec == 'x' || spec == 'X' || spec == 'p'))
	{
		output[0] = original[0];
		output[1] = original[1];
		count += 2;
		original += 2;
	}
	else if (original && !(spec == 'x' || spec == 'X' || spec == 'p'))
	{
		output[count] = original[0];
		original++;
		count++;
	}
	len = minwidth - pf_strlen(original);
	output = finish_pad(original, output, '0', minwidth);
	return (output);
}

/*
** do_pad
** if condition deals with a zero pad that also deals with a sign
** returns a pre-padded string
*/

static char	*do_pad(char *original, int minwidth, char *mods, char spec)
{
	char	*output;
	char	pad;
	int		count;
	int		len;

	pad = get_pad(mods);
	count = 0;
	len = minwidth - pf_strlen(original);
	if (pad == '0' && original && (original[0] == '-' || original[0] == '+' ||
		original[0] == ' ' || checkthrough_for(mods, '#') || spec == 'p'))
		return (pad_zero(original, minwidth, spec));
	if (!(output = (char*)pf_memalloc(minwidth + 1)))
		return (NULL);
	output[minwidth] = '\0';
	output = finish_pad(original, output, pad, minwidth);
	return (output);
}

/*
** do_minwidth
** any singing is done right away dealt with in the first if else statement
** if any minwidth needs to be done it is sent to the correct padding function
** finished output string is returned
*/

char		*do_minwidth(char *original, int minwidth, char *mods, char spec)
{
	int		len;
	char	*output;
	char	*tmp;

	if (((spec == 'x' || spec == 'X' || spec == 'o' || spec == 'O')
		&& checkthrough_for(mods, '#')) || spec == 'p')
		tmp = hexoct_sign(spec, original);
	else if (spec == 'd' || spec == 'D' || spec == 'i')
		tmp = do_sign(original, mods);
	else
		tmp = pf_strdup(original);
	len = pf_strlen(tmp);
	if (len < minwidth)
	{
		if (checkthrough_for(mods, '-'))
			output = do_justify_pad(tmp, minwidth);
		else
			output = do_pad(tmp, minwidth, mods, spec);
	}
	else
		output = pf_strdup(tmp);
	pf_memdel((void**)&tmp);
	pf_memdel((void**)&original);
	return (output);
}
