/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvogee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/24 13:20:54 by mvogee            #+#    #+#             */
/*   Updated: 2017/02/24 13:20:58 by mvogee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	do_swap(t_stack **stack)
{
	t_stack	*new_head;
	t_stack *old_head;

	new_head = (*stack)->next;
	old_head = *stack;
	old_head->next = new_head->next;
	old_head->prev = new_head;
	new_head->next = *stack;
	new_head->prev = NULL;
	*stack = new_head;
}
