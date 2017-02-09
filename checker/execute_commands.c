// 42 header here

#include "checker.h"

void	extend_execute(t_all *all, int count)
{
	if (all->commands[count] == RRA)
		do_rra(all->stacka);
	else if (all->commands[count] == RRB)
		do_rrb(all->stackb);
	else if (all->commands[count] == RRR)
		do_rrr(all->stacka, all->stackb);
	else
		throw_error();
}	

void	execute_commands(t_all *all)
{
	int		count;

	count = 0;
	while (count < all->numcommands)
	{
		if (all->commands[count] == SA)
			do_sa(all->stacka);
		else if (all->commands[count] == SB)
			do_sb(all->stackb);
		else if (all->commands[count] == SS)
			do_ss(all->stacka, all->stackb);
		else if (all->commands[count] == PA)
			do_pa(all->stacka, all->stackb);
		else if (all->commands[count] == PB)
			do_pb(all->stacka, all->stackb);
		else if (all->commands[count] == RA)
			do_ra(all->stacka);
		else if (all->commands[count] == RB)
			do_rb(all->stackb);
		else if (all->commands[count] == RR)
			do_rr(all->stacka, all->stackb);
		else
			extend_execute(all, count);
		count++;
	}
}