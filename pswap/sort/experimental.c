/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   experimental.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvogee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/24 13:28:08 by mvogee            #+#    #+#             */
/*   Updated: 2017/02/27 15:01:57 by mvogee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	three_sort(t_stack **stack, char c)
{
	int avalue;
	int aval_one;
	int avaln;

	while (!check_sorted(*stack))
	{
		avalue = (*stack)->value;
		aval_one = (*stack)->next->value;
		avaln = get_lastval(*stack);
		if (avalue > aval_one && avalue > avaln)
		{
			do_rotate(stack);
			ft_printf("r%c\n", c);
		}
		else if (avalue > aval_one || (avalue < aval_one && avalue < avaln))
		{
			do_swap(stack);
			ft_printf("s%c\n", c);
		}
		else if (avalue > avaln)
		{
			do_rev_rotate(stack);
			ft_printf("rr%c\n", c);
		}
	}
}

int		pushback_extention(t_all **all, int count)
{
	if (count && (*all)->stackb &&
		(*all)->stackb->value < get_lastval((*all)->stacka))
	{
		do_rev_rotate(&(*all)->stacka);
		ft_printf("rra\n");
		count--;
	}
	else if ((*all)->stackb)
	{
		do_push(&(*all)->stacka, &(*all)->stackb);
		ft_printf("pa\n");
		(*all)->sizea += 1;
		(*all)->sizeb -= 1;
	}
	else if (count)
	{
		do_rev_rotate(&(*all)->stacka);
		ft_printf("rra\n");
		count--;
	}
	return (count);
}

void	start_pushback(t_all **all)
{
	int			count;

	count = 0;
	while ((*all)->sizeb || count)
	{
		if ((*all)->stackb &&
			(*all)->stackb->value > (*all)->stacka->next->value)
		{
			do_rotate(&(*all)->stacka);
			ft_printf("ra\n");
			count++;
		}
		else if ((*all)->stackb &&
			(*all)->stackb->value < (*all)->stacka->next->value &&
			(*all)->stackb->value > (*all)->stacka->value)
		{
			do_push(&(*all)->stacka, &(*all)->stackb);
			do_swap(&(*all)->stacka);
			ft_printf("pa\nsa\n");
			(*all)->sizeb -= 1;
			(*all)->sizea += 1;
		}
		else
			count = pushback_extention(all, count);
	}
}

void	push_swap_extended(t_all *all, int avalue, int aval_one, int avaln)
{
	if ((avalue > aval_one && aval_one > avaln) || avalue > avaln)
	{
		do_rev_rotate(&all->stacka);
		ft_printf("rra\n");
	}
	else if (avalue > aval_one)
	{
		do_swap(&all->stacka);
		ft_printf("sa\n");
	}
	else
	{
		do_push(&all->stackb, &all->stacka);
		all->sizea -= 1;
		all->sizeb += 1;
		ft_printf("pb\n");
		sort_b(&all->stackb);
	}
}

void	push_swap(t_all *all)
{
	int			sorted;
	int			avalue;
	int			aval_one;
	int			avaln;

	if (all->sizea <= 3)
		three_sort(&all->stacka, 'a');
	sorted = check_sorted(all->stacka);
	while (!sorted)
	{
		avalue = all->stacka->value;
		aval_one = all->stacka->next->value;
		avaln = get_lastval(all->stacka);
		if (all->sizea <= 3)
			three_sort(&all->stacka, 'a');
		else
			push_swap_extended(all, avalue, aval_one, avaln);
//		if (check_sorted(all->stacka))
//			start_pushback(&all); // checking to see if this is where most of the inneficiency comes from
		sorted = check_sorted(all->stacka);
	}
}
