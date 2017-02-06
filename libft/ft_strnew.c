/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvogee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/28 10:13:30 by mvogee            #+#    #+#             */
/*   Updated: 2016/09/28 11:51:10 by mvogee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*retstr;

	if (!(retstr = (char*)malloc(sizeof(char) * size + 1)))
		return (NULL);
	ft_bzero(retstr, size + 1);
	return (retstr);
}
