/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvogee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/24 13:20:30 by mvogee            #+#    #+#             */
/*   Updated: 2017/02/24 13:20:35 by mvogee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	do_rev_rotate(t_stack **stack)
{
	t_stack	*old_head;
	t_stack	*last_node;
	t_stack	*previous;
	int		count;

	old_head = *stack;
	previous = *stack;
	last_node = (*stack)->next;
	count = 0;
	while (last_node->next)
	{
		previous = previous->next;
		last_node = last_node->next;
		count++;
	}
	if (count > 0)
		last_node->next = old_head->next;
	else
		old_head->next = NULL;
	last_node->next = old_head;
	last_node->prev = NULL;
	previous->next = NULL;
	old_head->prev = last_node;
	*stack = last_node;
}
