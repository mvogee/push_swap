// 42 header goes here

#include "checker.h"

void	throw_error(void)
{
	write(2, "Error\n", 6);
	exit(0);
}

int		main(int ac, char **av)
{
	t_stack stack;

	if (ac < 2)
		return (0);
	if (ac == 2)
		get_string_stack(av[1], &stack); // this will get the args as fromated from a string
	else
		get_list_stack(ac, av, &stack); // this will get the original stack as seperate args
	// the stacks are initialized with the correct size for both of them.
	stack.numcommands = 0;
	get_commands(&stack); // read the commands from the standard input
	for (int i = 0; i < stack.numcommands; i++)
		ft_printf("%d\n",stack.commands[i]);
	// execute_commands(&stack); // this will execute the commands
	// check_sort(stack); // check if the stack is sorted and dispaly propper output
	return (0);
}
