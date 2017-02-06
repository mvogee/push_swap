/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvogee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/23 20:17:20 by mvogee            #+#    #+#             */
/*   Updated: 2016/09/23 20:18:21 by mvogee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	int	countbig;
	int countsub;
	int	countlittle;

	countbig = 0;
	if (little[0] == '\0' || !(little))
		return ((char*)big);
	while (big[countbig] && (size_t)countbig < len)
	{
		if (big[countbig] == little[0])
		{
			countsub = countbig;
			countlittle = 0;
			while (big[countsub] == little[countlittle] &&
				(size_t)countsub < len)
			{
				if (little[countlittle + 1] == '\0')
					return ((char*)big + countbig);
				countlittle++;
				countsub++;
			}
		}
		countbig++;
	}
	return (NULL);
}
