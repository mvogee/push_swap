/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printbits.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvogee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/06 15:13:44 by mvogee            #+#    #+#             */
/*   Updated: 2016/10/06 16:03:57 by mvogee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_printbits(unsigned char octet)
{
	int bit;

	bit = 7;
	while (bit >= 0)
	{
		if (octet & 1 << bit)
			ft_putchar('1');
		else
			ft_putchar('0');
		ft_putchar(' ');
		bit--;
	}
	ft_putchar('\n');
}
