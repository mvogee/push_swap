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
	t_stack		*duplicate;
	t_stack		*prev;
	t_stack		*duphead;

	if (!stack)
		return (NULL);
	duplicate = NULL;
	duplicate = (t_stack*)ft_memalloc(sizeof(t_stack));
	duplicate = (t_stack*)ft_memcpy(duplicate, stack, sizeof(t_stack));
	duphead = duplicate;
	prev = duplicate;
	stack = stack->next;
	while (stack)
	{
		duplicate->next = (t_stack*)ft_memalloc(sizeof(t_stack));
		duplicate->next = (t_stack*)ft_memcpy(duplicate, stack, sizeof(t_stack));
		duplicate->prev = prev;
		prev = duplicate;
		stack = stack->next;
		duplicate = duplicate->next;
	}
	duplicate = duphead;
	return (duplicate);
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
