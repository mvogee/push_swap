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
		ft_printf("\e[31mKO\n");
		return ;
	}
	while (tmp->next)
	{
		if (tmp->value > tmp->next->value)
		{
			ft_printf("\e[31mKO\n");
			return ;
		}
		tmp = tmp->next;
	}
	ft_printf("\e[32mOK\n");
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
** add these lines main to easily see stack at the end
** of run and how many commands ran
** 	print_stacks(&all);
**	ft_printf("\e[32mcommands run: %d\n", all.numcommands);
*/

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
	all.numcommands = 0;
	all.sizea = all.size;
	all.sizeb = 0;
	check_duplicates(&all);
	get_commands(&all);
	check_sort(&all);
	free_list(all.stacka);
	if (all.stackb)
		free_list(all.stackb);
	return (0);
}
