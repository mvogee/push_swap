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
