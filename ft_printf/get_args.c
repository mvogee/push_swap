/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_args.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvogee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/15 13:53:05 by mvogee            #+#    #+#             */
/*   Updated: 2016/12/15 13:53:06 by mvogee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** get_len
** determines if there is a length modifier
** returns an Enum corresponding to the modifer
*/

int		get_len(char *mods)
{
	if (!mods)
		return (NONE);
	while (*mods)
	{
		if (*mods == 'h' && mods[1] == 'h')
			return (HH);
		if (*mods == 'h')
			return (H);
		if (*mods == 'l' && mods[1] == 'l')
			return (LL);
		if (*mods == 'l')
			return (L);
		if (*mods == 'j')
			return (J);
		if (*mods == 'z')
			return (Z);
		mods++;
	}
	return (NONE);
}
