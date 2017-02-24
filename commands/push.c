/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvogee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/24 13:20:16 by mvogee            #+#    #+#             */
/*   Updated: 2017/02/24 13:20:21 by mvogee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	do_push(t_stack **pushto, t_stack **pushfrom)
{
	t_stack	*newhead_to;
	t_stack	*newhead_from;

	newhead_to = (*pushfrom);
	if (*pushto)
		(*pushto)->prev = newhead_to;
	newhead_from = (*pushfrom)->next;
	if (newhead_from)
		(*pushfrom)->next->prev = NULL;
	newhead_to->next = *pushto;
	*pushto = newhead_to;
	*pushfrom = newhead_from;
}
