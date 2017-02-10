// 42 header goes here

#include "checker.h"

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
		ft_printf("a: %d, ", tmp->value);
		ft_printf("%d\n", tmp->next->value);
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
		get_string_stack(av[1], &all); // this will get the args as fromated from a string
	else
		get_list_stack(ac, av, &all); // this will get the original stack as seperate args
	all.numcommands = 0;
	all.sizea = all.size;
	all.sizeb = 0;
	get_commands(&all); // read the commands from the standard input
	execute_commands(&all); // this will execute the commands
	check_sort(&all); // check if the stack is sorted and dispaly propper output
	return (0);
}


	// for (int i = 0; all.stacka; i++)
	// {
	// 	ft_printf("%d\n", all.stacka->value);
	// 	all.stacka = all.stacka->next;
	// }
	// for (int i = 0; i < all.numcommands; i++)
	// 	ft_printf("%d\n", all.commands[i]);