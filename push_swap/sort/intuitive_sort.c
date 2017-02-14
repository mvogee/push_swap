// 42 header here

#include "push_swap.h"
// first attempt at sorting algorithm. my own brain baby intuitive sorting method

int		check_sorted(t_stack *stack)
{
	t_stack		*cpy;

	cpy = stack;
	while (cpy->next)
	{
		if (cpy->value > cpy->next->value)
			return (0);
		cpy = cpy->next;
	}
	return (1);
}

int		find_push_cutoff(t_all *all)
{
	int		end;
	int		mid;
	int		count;
	t_stack	*tmp;

	tmp = all->stacka;
	count = 0;
	while (tmp->next)
	{
		count++;
		if (count = (all->sizea / 2))
			mid = tmp->value;
		tmp = tmp->next;
	}
	end = tmp->value;
	if (all->stacka->value < mid && mid < end)
		return (mid);
	else if (mid < all->stacka->value && all->stacka->value < end)
		return (all->stacka->value);
	else
		return (end);
}

int		check_swapa(t_stack *stacka)
{
	if (stacka->next)
	{
		if (stacka->value > stacka->next->value)
			return (SA);
	}
	return (0);
}

int		check_swapb(t_stack *stackb)
{
	if (stackb->next)
	{
		if (stackb->value < stackb->next->value)
			return (SB);
	}
	return (0);
}

void	do_actions(t_all **all, int a, int b)
{
	if (a == SA && b == SB)
	{
		ft_printf("ss\n");
		do_swap(&all->stacka);
		do_swap(&all->stackb);
	}
	else if (a == SA)
	{
		ft_printf("sa\n");
		do_swap(&all->stacka);
	}
	else if (b == SB)
	{
		ft_printf("sb\n");
		do_swap(&all->stackb);
	}
	else if (a == RRA)
	{
		ft_printf("rra\n");
		do_reverse_rotate(&all->stacka);
	}
}

void	push_swap(t_all *all)
{
	int		split;
	int		sorted;
	int		b_action; // these tell what action needs to be taken for a and b
	int		a_action;
		//action  0 = do nothing
	sorted = check_sorted(all->stacka); // make this. return 1 if sorted else 0
	split = find_push_cutoff(all); // takes the median of 3 numbers from the stack
	while (!sorted) // could add a check_special_cases function in here
	{
		a_action = check_swapa(all->stacka);
		b_action = check_swapb(all->stackb);
		if (a_action || b_aciton)
			do_actions(&all, a_aciton, b_action); and print action if only b_action is active dont execute yet
		sorted = check_sorted(all);
		if (all->stacka->value <= split && !sorted)
		{
			do_push(&all->stackb, &all->stacka); // these will need to be modded for case where one o
			//b_action = get_b_action() // make this
		}
		if (!sorted)
			do_actions(&all, RRA, 0);
		else
			finish_b(&all); // make this. make sure b is sorted and push all elems to a
	}
}

// method brainbaby aka nieve
// 1 check the first two nodes for sort
// 2 if sorted sip to 5
// 3 else swap the two front cards
// 4 if the first card is below the half threshold push it to b
// do rra to bring last card to front
// repeat from 1