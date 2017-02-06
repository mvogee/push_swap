/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstaddlast.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvogee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/06 20:26:09 by mvogee            #+#    #+#             */
/*   Updated: 2016/10/06 20:52:38 by mvogee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstaddlast(t_list *alst, t_list *new)
{
	if (alst && new)
	{
		while (alst->next)
			alst = alst->next;
		alst->next = new;
	}
}
