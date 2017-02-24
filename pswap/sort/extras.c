/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extras.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvogee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/24 14:17:42 by mvogee            #+#    #+#             */
/*   Updated: 2017/02/24 14:17:43 by mvogee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		check_sorted(t_stack *stack)
{
	t_stack		*cpy;

	cpy = stack;
	while (cpy->next)
	{
		if (cpy->value > cpy->next->value)
			return (0);
		cpy = cpy->next;
	}
	return (1);
}

int		get_lastval(t_stack *stack)
{
	t_stack		*tmp;

	tmp = stack;
	while (tmp->next)
		tmp = tmp->next;
	return (tmp->value);
}

void	sort_b(t_stack **stack)
{
	int			sorted;
	int			count;

	count = 0;
	sorted = check_sorted(*stack);
	if (!sorted)
	{
		while (count < 1)
		{
			if ((*stack)->value < (*stack)->next->value)
			{
				do_swap(stack);
				ft_printf("sb\n");
			}
			else if ((*stack)->value < get_lastval(*stack))
			{
				do_rev_rotate(stack);
				ft_printf("rrb\n");
			}
			count++;
		}
	}
}
