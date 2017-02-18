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

void	do_actions(t_all **all, int **a, int **b)
{
	if (a == SA && b == SB)
	{
		ft_printf("ss\n");
		do_swap(&all->stacka);
		do_swap(&all->stackb);
		*a = 0;
		*b = 0;
	}
	else if (a == SA)
	{
		ft_printf("sa\n");
		do_swap(&all->stacka);
		*a = 0;
	}
	else if (b == SB)
	{
		ft_printf("sb\n");
		do_swap(&all->stackb);
		*b = 0;
	}
	else if (a == RRA)
	{
		ft_printf("rra\n");
		do_reverse_rotate(&all->stacka);
		*a = 0;
	}
}

void	sort_b(int **b, t_stack **stackb) // what does this need to do?
{
	if (*b)
	{
		do_baction(b, stackb)
		b = 0;
	}
	if (*b = check_swapb(stackb))
	{
		*b = 0;
		ft_printf("sb\n");
		do_swap(stackb);
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
		do_actions(&all, &a_action, &b_action);
		if (sorted = check_sorted(all->stacka))
			break ;
		if (all->stacka->value <= split)
		{
			do_baction(&b_action, &all->stackb);
			all->sizea -= 1;
			all->sizeb += 1;
			do_push(&all->stackb, &all->stacka);
			sort_b(&b_action, &all->stackb); // make this needs to find the best action to take for b
			continue ;
		}
		sort_b(&b_action, &all->stackb); // make this. needs to find the best action to take to sort b
	}
	// make sure all be is sorted and push it to a
}

// method brainbaby aka nieve
// 1 check the first two nodes for sort
// 2 if sorted sip to 5
// 3 else swap the two front cards
// 4 if the first card is below the half threshold push it to b
// do rra to bring last card to front
// repeat from 1