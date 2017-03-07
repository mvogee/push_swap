/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_calculation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvogee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/07 13:10:03 by mvogee            #+#    #+#             */
/*   Updated: 2017/03/07 13:10:05 by mvogee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		arot_to_top(t_stack *stacka)
{
	int			count;
	t_stack		*tmp;

	count = 0;
	tmp = stacka;
	while (tmp->prev)
	{
		count++;
		tmp = tmp->prev;
	}
	return (count);
}

int		arev_to_top(t_stack *stacka)
{
	int			count;
	t_stack		*tmp;

	count = 0;
	tmp = stacka;
	while (tmp->next)
	{
		count--;
		tmp = tmp->next;
	}
	return (count - 1);
}

int		brot_to_sort(t_stack *stackb, int value, int curlow, int curhigh)
{
	int			count;
	t_stack		*tmp;

	count = 0;
	if (!stackb)
		return (0);
	tmp = duplicate_stack(stackb);
	if (value > curhigh || value < curlow)
	{
		while (tmp->value != curhigh)
		{
			do_rotate(&tmp);
			count++;
		}
	}
	else
	{
		while (!(value > tmp->value && value < get_lastval(tmp)))
		{
			do_rotate(&tmp);
			count++;
		}
	}
	free_list(tmp);
	return (count);
}

int		brev_to_sort(t_stack *stackb, int value, int curlow, int curhigh)
{
	int			count;
	t_stack		*tmp;

	count = 0;
	if (!stackb)
		return (0);
	tmp = duplicate_stack(stackb);
	if (value > curhigh || value < curlow)
	{
		while (tmp->value != curhigh)
		{
			do_rev_rotate(&tmp);
			count--;
		}
	}
	else
	{
		while (!(value > tmp->value && value < get_lastval(tmp)))
		{
			do_rev_rotate(&tmp);
			count--;
		}
	}
	free_list(tmp);
	return (count);
}
