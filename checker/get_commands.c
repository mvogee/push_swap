// 42 header here

#include "checker.h"

int		translate_command(char *command)
{
	if (ft_strequ(command, "sa"))
		return (SA);
	else if (ft_strequ(command, "sb"))
		return (SB);
	else if (ft_strequ(command, "ss"))
		return (SS);
	else if (ft_strequ(command, "pa"))
		return (PA);
	else if (ft_strequ(command, "pb"))
		return (PB);
	else if (ft_strequ(command, "ra"))
		return (RA);
	else if (ft_strequ(command, "rb"))
		return (RB);
	else if (ft_strequ(command, "rr"))
		return (RR);
	else if (ft_strequ(command, "rra"))
		return (RRA);
	else if (ft_strequ(command, "rrb"))
		return (RRB);
	else if (ft_strequ(command, "rrr"))
		return (RRR);
	else
		throw_error();
	return (0);
}

void	add_command(char *line, t_stack *stack)
{
	int		*tmp;
	int		count;

	count = 0;
	stack->numcommands += 1;
	tmp = (int*)ft_memalloc(sizeof(int) * stack->numcommands);
	while (count < stack->numcommands - 1)
	{
		tmp[count] = stack->commands[count];
		count++;
	}
	tmp[count] = translate_command(line);
	count = 0;
	free(stack->commands);
	stack->commands = (int*)ft_memalloc(sizeof(int) * stack->numcommands);
	while (count < stack->numcommands)
	{
		stack->commands[count] = tmp[count];
		count++;
	}
	free(tmp);
}

void	get_commands(t_stack *stack) // this needs to read form the standard input to get the arguments
{
	// read will not null term the input
	char	*line;

	line = NULL;
	while (get_next_line(0, &line) > 0)
	{
		if (!line || ft_strequ(line, ""))
			break ;
		else
			add_command(line, stack);
	}
}