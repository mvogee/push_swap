// 42 header here

#include "push_swap.h"
// first attempt at sorting algorithm. my own brain baby version
void	push_swap(t_all *all)
{
	int split;
	int sorted;
	int	b_action; // these tell what action needs to be taken for a and b
	int	a_action;
	// 0 = do nothing
	// we have enums for the rest of the actions
	//if a or b needs to be rotated can we wait on that command until we know we cant do it alongside the other stack
	sorted = check_sorted(stacks); // make this. return 1 if sorted else 0
	split = find_push_cutoff(all->stacka); // manually sort and get the middle number
	
	while (!sorted)
	{
		a_action = check_top_stacka_for_swap;
		b_action = check_top_stackb_for_swap;
		if (actions)
			do the actions
		if (sorted = check_sorted(all))
			break ;
		if (stacks->stacka->value < split)
		{
			push_b
			b_action = get_action()
		}
	}
}

// method brainbaby aka nieve
// 1 check the first two nodes for sort
// 2 if sorted sip to 5
// 3 else swap the two front cards
// 4 if the first card is below the half threshold push it to b
// do rra to bring last card to front
// repeat from 1