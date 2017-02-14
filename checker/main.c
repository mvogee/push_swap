// 42 header goes here

#include "push_swap.h"

void	throw_error(void)
{
	write(2, "Error\n", 6);
	exit(0);
}

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

int		main(int ac, char **av)
{
	t_all all;

	if (ac < 2)
		return (0);
	if (ac == 2)
		get_string_stack(av[1], &all);
	else
		get_list_stack(ac, av, &all);
	all.numcommands = 0;
	all.sizea = all.size;
	all.sizeb = 0;
	get_commands(&all);
	execute_commands(&all);
	check_sort(&all);
	return (0);
}
