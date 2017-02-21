// 42 header

#include "push_swap.h"
// we can use the same header for both checker and this just dont use all the struct vars
// void	throw_error(void) // this function is in checker.c
// {
// 	write(2, "Error\n", 6);
// 	exit(0);
// }
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
			throw_error();
		while (forward)
		{
			if (forward->value == cur->value)
				throw_error();
			forward = forward->next;
		}
		cur = cur->next;
	}
}

int		main(int ac, char **av)
{
	t_all	all;

	ft_bzero(&all, sizeof(t_all));
//	all = NULL;
	if (ac < 2)
		return (0);
	if (ac == 2)
		get_string_stack(av[1], &all);
	else
		get_list_stack(ac, av, &all);
	all.sizea = all.size;
	all.commands = NULL;
	check_duplicates(&all); // steps through stack and checsk for dups
	push_swap(&all); // main algorithms // there are seg fault in here
	print_stacks(&all);

}