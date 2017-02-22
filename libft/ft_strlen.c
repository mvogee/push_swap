/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvogee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/21 22:32:58 by mvogee            #+#    #+#             */
/*   Updated: 2016/09/21 22:32:59 by mvogee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned long	ft_strlen(char *str)
{
	unsigned long	count;

	count = 0;
	if (!str)
		return (0);
	while (str[count])
		count++;
	return (count);
}
