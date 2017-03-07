/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newsort_extras.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvogee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 16:34:31 by mvogee            #+#    #+#             */
/*   Updated: 2017/03/01 16:34:32 by mvogee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*duplicate_stack(t_stack *stack)
{
	t_stack			*tmp;
	t_stack			*dup;
	t_stack			*duphead;
	t_stack			*prev;

	tmp = stack;
	prev = NULL;
	dup = NULL;
	duphead = NULL;
	while (tmp)
	{
		dup = (t_stack*)ft_memalloc(sizeof(t_stack));
		dup->prev = prev;
		dup->next = NULL;
		dup->value = tmp->value;
		if (dup->prev)
			dup->prev->next = dup;
		prev = dup;
		if (!duphead)
			duphead = dup;
		tmp = tmp->next;
	}
	dup = duphead;
	return (dup);
}

int		get_lastval(t_stack *stack)
{
	t_stack		*tmp;

	tmp = stack;
	while (tmp->next)
		tmp = tmp->next;
	return (tmp->value);
}

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

void	move_b_to_order(t_all *all)
{
	int			count;
	int			flag;
	t_stack		*tmp;

	tmp = all->stackb;
	flag = 0;
	count = 0;
	while (tmp->value != all->b_curhigh)
	{
		tmp = tmp->next;
		count++;
	}
	if (count <= (all->sizeb / 2))
		flag = 1;
	while (all->stackb->value != all->b_curhigh)
	{
		if (flag)
			do_rotate(&all->stackb);
		else
			do_rev_rotate(&all->stackb);
	}
}
