// 42 header

#include "push_swap.h"

void	throw_error(void)
{
	write(2, "Error\n", 6);
	exit(0);
}

void	check_duplicates(t_stacks *stacks)
{
	t_stack		*cur;
	t_stack		*forward;

	cur = stacks->stacka;
	if (stacks->sizea < 1)
		return ;
	while (cur->next)
	{
		forward = cur->next;
		if (forawd->value == cur->value)
			throw_error();
		while (forward)
		{
			if (forawd->value == cur->value)
				throw_error();
			forward = forward->next;
		}
		cur = cur->next;
	}
}

int		main(int ac, char **av)
{
	t_stacks	*stacks;

	if (ac < 2)
		return (0);
	if (ac == 2)
		get_string_stack(av[1], &stacks);
	else
		get_list_stack(ac, av, &stacks);
	check_duplicates(&stacks); // steps through stack and checsk for dups
//	push_swap(&stacks); // main algorithms

}