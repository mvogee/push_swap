/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvogee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/23 16:31:21 by mvogee            #+#    #+#             */
/*   Updated: 2016/09/23 16:33:15 by mvogee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t s1len;
	size_t s2len;

	s1len = (size_t)ft_strlen((char*)s1) + 1;
	s2len = (size_t)ft_strlen((char*)s2) + 1;
	if (n <= 0)
		return (0);
	if (s1len == s2len && s1len < n)
		return (ft_memcmp(s1, s2, s1len));
	return (ft_memcmp(s1, s2, n));
}
