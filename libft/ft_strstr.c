/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvogee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/23 17:22:15 by mvogee            #+#    #+#             */
/*   Updated: 2016/09/23 17:25:31 by mvogee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *big, const char *little)
{
	int	countbig;
	int countsub;
	int	countlittle;

	countbig = 0;
	if (little[0] == '\0' || !(little))
		return ((char*)big);
	while (big[countbig])
	{
		if (big[countbig] == little[0])
		{
			countsub = countbig;
			countlittle = 0;
			while (big[countsub] == little[countlittle])
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
