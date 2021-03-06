/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvogee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/24 13:20:42 by mvogee            #+#    #+#             */
/*   Updated: 2017/02/24 13:20:44 by mvogee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	do_rotate(t_stack **stack)
{
	t_stack	*old_head;
	t_stack	*new_head;
	t_stack	*old_end;

	old_head = *stack;
	new_head = (*stack)->next;
	new_head->prev = NULL;
	old_end = (*stack)->next;
	while (old_end->next)
		old_end = old_end->next;
	old_end->next = old_head;
	old_head->prev = old_end;
	old_head->next = NULL;
	*stack = new_head;
}
