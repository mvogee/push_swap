// 42 header

#include "push_swap.h"

void	three_sort(t_stack **stack, char c)
{
	int avalue;
	int aval_one;
	int avaln;

	while (!check_sorted(*stack))
	{
		avalue = (*stack)->value;
		aval_one = (*stack)->next->value;
		avaln = get_lastval(*stack);
		if (avalue > aval_one && avalue > avaln)
		{
			do_rotate(stack);
			ft_printf("r%c\n", c);
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

void	sort_b(t_stack **stack)
{
	int			sorted;
	int			count;

	count = 0;
	sorted = check_sorted(*stack);
	if (!sorted)
	{
		while (count < 1)
		{
			if ((*stack)->value < (*stack)->next->value)
			{
				do_swap(stack);
				ft_printf("sb\n");
			}
			else if ((*stack)->value < get_lastval(*stack))
			{
				do_rev_rotate(stack);
				ft_printf("rrb\n");
			}
			count++;
		}
	}
}

void	start_pushback(t_all **all)
{
	int			count;

	count = 0;
	while ((*all)->sizeb || count)
	{
		if ((*all)->stackb && (*all)->stackb->value > (*all)->stacka->next->value)
		{
			do_rotate(&(*all)->stacka);
			ft_printf("ra\n");
			count++;
		}
		else if ((*all)->stackb && (*all)->stackb->value < (*all)->stacka->next->value && (*all)->stackb->value > (*all)->stacka->value)
		{
			do_push(&(*all)->stacka, &(*all)->stackb);
			do_swap(&(*all)->stacka);
			ft_printf("pa\n");
			ft_printf("sa\n");
			(*all)->sizeb -= 1;
			(*all)->sizea += 1;
		}
		else if (count && (*all)->stackb && (*all)->stackb->value < get_lastval((*all)->stacka))
		{
			do_rev_rotate(&(*all)->stacka);
			ft_printf("rra\n");
			count--;
		}
		else if ((*all)->stackb)
		{
			do_push(&(*all)->stacka, &(*all)->stackb);
			ft_printf("pa\n");
			(*all)->sizea += 1;
			(*all)->sizeb -= 1;
		}
		else if (count)
		{
			do_rev_rotate(&(*all)->stacka);
			ft_printf("rra\n");
			count--;
		}
	}
}

void	push_swap(t_all *all)
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
		else if ((avalue > aval_one && aval_one > avaln) || avalue > avaln)
		{
			do_rev_rotate(&all->stacka);
			ft_printf("rra\n");
		}
		else if (avalue > aval_one)
		{
			do_swap(&all->stacka);
			ft_printf("sa\n");
		}
		else 
		{
			do_push(&all->stackb, &all->stacka);
			all->sizea -= 1;
			all->sizeb += 1;
			ft_printf("pb\n");
			sort_b(&all->stackb);
		}
		if (check_sorted(all->stacka))
			start_pushback(&all);
		sorted = check_sorted(all->stacka);
	}
}