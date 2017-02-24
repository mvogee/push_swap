/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvogee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/24 13:25:17 by mvogee            #+#    #+#             */
/*   Updated: 2017/02/24 13:25:23 by mvogee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stacks(t_all *all)
{
	t_stack *a;
	t_stack *b;

	a = all->stacka;
	b = all->stackb;
	ft_printf("B| ");
	while (b)
	{
		ft_printf("%d ", b->value);
		b = b->next;
	}
	ft_printf("\nA| ");
	while (a)
	{
		ft_printf("%d ", a->value);
		a = a->next;
	}
	ft_printf("\n");
}

void	check_duplicates(t_all *all)
{
	t_stack		*cur;
	t_stack		*forward;

	cur = all->stacka;
	if (all->sizea < 1)
		return ;
	while (cur->next)
	{
		forward = cur->next;
		if (forward->value == cur->value)
			throw_error_free(all->stacka);
		while (forward)
		{
			if (forward->value == cur->value)
				throw_error_free(all->stacka);
			forward = forward->next;
		}
		cur = cur->next;
	}
}

int		main(int ac, char **av)
{
	t_all	all;

	ft_bzero(&all, sizeof(t_all));
	if (ac < 2)
		return (0);
	if (ac == 2)
		get_string_stack(av[1], &all);
	else
		get_list_stack(ac, av, &all);
	all.sizea = all.size;
	all.commands = NULL;
	check_duplicates(&all);
	push_swap(&all);
	free_list(all.stacka);
	return (0);
}
