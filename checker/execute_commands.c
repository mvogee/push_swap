// 42 header here

#include "checker.h"

void	extend_execute(t_stack *stack, int count)
{
	if (stack->commands[count] == RRA)
		do_rra(stack);
	else if (stack->commands[count] == RRB)
		do_rrb(stack);
	else if (stack->command[count] == RRR)
		do_rrr(stack);
	else
		throw_error();
}	

void	execute_commands(t_stack *stack)
{
	int		count;

	count = 0;
	while (count < stack->numcommands)
	{
		if (stack->commands[count] == SA)
			do_sa(stack);
		else if (stack->commands[count] == SB)
			do_sb(stack);
		else if (stack->commands[count] == SS)
			do_ss(stack);
		else if (stack->commands[count] == PA)
			do_pa(stack);
		else if (stack->commands[count] == PB)
			do_pb(stack);
		else if (stack->commands[count] == RA)
			do_ra(stack);
		else if (stack->commands[count] == RB)
			do_rb(stack);
		else if (stack->commands[count] == RR)
			do_rr(stack);
		else
			extend_execute(stack, count);
		count++;
	}
}