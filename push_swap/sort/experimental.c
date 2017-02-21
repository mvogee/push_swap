// 42 header

#include "push_swap.h"

void	three_sort(t_stack **stack, char c)
{
	int avalue;
	int aval_one;
	int avaln;

	while (!check_sorted(*stack))
	{
		avalue = *stack->value;
		aval_one = *stack->next->value;
		avaln = get_lastval(*stack);
		if (avalue > aval_one && avalue > avaln)
		{
			do_rotate(stack);
			ft_prinft("r%c\n", c);
		}
		else if (avalue > aval_one || (avalue < aval_one && avalue < avaln))
		{
			do_swap(stack);
			ft_printf("s%c\n", c);
		}
		else if (avalue > avaln)
		{
			do_rev_rotate(stack);
			ft_printf("rr%c\n", c);
		}
	}
}

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

int		get_lastval(t_stack *stack)
{
	t_stack		*tmp;

	tmp = stack;
	while (tmp->next)
		tmp = tmp->next;
	return (tmp->value);
}

void	push_swap(t_all **all)
{
	int			sorted;
	int 		avalue;
	int 		aval_one;
	int 		avaln;

	if (all->sizea <= 3)
		three_sort(&all->stacka, 'a');
	sorted = check_sorted(all->stacka);
	while (!sorted)
	{
		avalue = all->stacka->value;
		aval_one = all->stacka->next->value;
		avaln = get_lastval(all->stacka);
		if (all->sizea <= 3)
			three_sort(&all->stacka, 'a');
		if ((avalue > aval_one && aval_one > avaln) || avalue > avaln)
		{
			do_rev_rotate(all->stacka);
			ft_printf("rra\n");
			continue ;
		}
		else if (avalue > aval_one)
		{
			do_swap(all->stacka);
			ft_printf("sa\n");
			continue ;
		}
		else 
		{
			do_push(all->stackb, all->stacka);
			all->sizea -= 1;
			ft_printf("pb\n");
			sort_b(all->stackb); // make this function // sort elements as they are put into b
		}
		if (sorted = check_sorted(all->stacka))
			start_pushback(all); // make this function
		sorted = check_sorted(all->stacka)
			// start pushback will take from b one at a time making sure the sort is still correct as you go
	}
}