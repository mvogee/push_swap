/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvogee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/23 15:51:48 by mvogee            #+#    #+#             */
/*   Updated: 2016/09/25 22:36:35 by mvogee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	len;

	len = ft_strlen((char*)s1);
	if (ft_strlen((char*)s2) > len)
		len = ft_strlen((char*)s2);
	return (ft_memcmp(s1, s2, len));
}
