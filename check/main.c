/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvogee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/24 12:52:49 by mvogee            #+#    #+#             */
/*   Updated: 2017/02/27 14:57:42 by mvogee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_sort(t_all *all)
{
	t_stack *tmp;

	tmp = all->stacka;
	if (all->sizeb != 0 || !tmp)
	{
		ft_printf("KO\n");
		return ;
	}
	while (tmp->next)
	{
		if (tmp->value > tmp->next->value)
		{
			ft_printf("KO\n");
			return ;
		}
		tmp = tmp->next;
	}
	ft_printf("OK\n");
}

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

/*
** add these lines to bottom of main to easily see stack at the end
** of run and how many commands ran
** 	print_stacks(&all);
**	ft_printf("commands run: %d\n", all.numcommands);
*/

int		main(int ac, char **av)
{
	t_all	all;

	if (ac < 2)
		return (0);
	if (ac == 2)
		get_string_stack(av[1], &all);
	else
		get_list_stack(ac, av, &all);
	all.numcommands = 0;
	all.sizea = all.size;
	all.sizeb = 0;
	check_duplicates(&all);
	get_commands(&all);
	execute_commands(&all);
	check_sort(&all);
	print_stacks(&all);
	ft_printf("\300commands run: %d\n", all.numcommands);
	free_list(all.stacka);
	if (all.commands)
		free(all.commands);
	return (0);
}
