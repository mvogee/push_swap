// 42 header here

#include "checker.h"

// void	extend_execute3(t_all *all, int count)
// {
// 	if (all->commands[count] == RRR)
// 	{
// 		if (all->stacka > 1)
// 			do_rra(&(all->stacka));
// 		if (all->stackb > 1)
// 			do_rrb(&(all->stackb));
// 	}
// 	else
// 		throw_error();
// }

void	extend_execute2(t_all *all, int count)
{
	if (all->commands[count] == RB)
	{
		if (all->sizeb > 1)
			do_rotate(&all->stackb);
	}
	else if (all->commands[count] == RR)
	{
		if (all->sizea > 1)
			do_rotate(&all->stacka);
		if (all->sizeb > 1)
			do_rotate(&all->stackb);
	}
	// else if (all->commands[count] == RRA)
	// {
	// 	if (all->stacka > 1)
	// 		do_rra(&(all->stacka));
	// }
	// else if (all->commands[count] == RRB)
	// {
	// 	if (all->stackb > 1)
	// 		do_rrb(&(all->stackb));
	// }
	// else
	// 	extend_execute3(all, count);
}

void	extend_execute(t_all *all, int count)
{
	if (all->commands[count] == PA)
	{
		if (all->sizeb < 1)
			return ;
		do_push(&(all->stacka), &(all->stackb));
		all->sizeb -= 1;
		all->sizea += 1;
	}
	else if (all->commands[count] == PB)
	{
		if (all->sizea < 1)
			return ;
		do_push(&all->stackb, &all->stacka);
		all->sizea -= 1;
		all->sizeb += 1;
	}
	else if (all->commands[count] == RA)
	{
		if (all->sizea > 1)
			do_rotate(&all->stacka);
	}
	else
		extend_execute2(all, count);
}

void	execute_commands(t_all *all)
{
	int		count;

	count = 0;
	while (count <= all->numcommands)
	{
		if (all->commands[count] == SA)
		{
			if (all->sizea > 1)
				do_swap(&all->stacka);
		}
		else if (all->commands[count] == SB)
		{
			if (all->sizeb > 1)
				do_swap(&all->stackb);
		}
		else if (all->commands[count] == SS)
		{
			if (all->sizea > 1)
				do_swap(&all->stacka);
			if (all->sizeb > 1)
				do_swap(&all->stackb);
		}
		else
			extend_execute(all, count);
		count++;
	}
}