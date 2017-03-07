/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newsort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvogee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/27 15:08:31 by mvogee            #+#    #+#             */
/*   Updated: 2017/02/27 15:08:32 by mvogee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		arot_to_top(t_stack *stacka) //done needs testing
{
	int			count;
	t_stack		*tmp;

	count = 0;
	tmp = stacka;
	while (tmp->prev)
	{
		count++;
		tmp = tmp->prev;
	}
	return (count);
}

int		arev_to_top(t_stack *stacka) //done needs testing
{
	int			count;
	t_stack		*tmp;

	count = 0;
	tmp = stacka;
	while (tmp->next)
	{
		count--;
		tmp = tmp->next;
	}
	return (count - 1); // minus one because it takes one more action to put it at the top
}

int		brot_to_sort(t_stack *stackb, int value, int curlow, int curhigh)
{
	int			count;
	t_stack		*tmp;

	count = 0;
	if (!stackb)
		return (0);
	tmp = duplicate_stack(stackb);
	if (value > curhigh || value < curlow)
	{
		while (tmp->value != curhigh)
		{
			do_rotate(&tmp);
			count++;
		}
	}
	else
	{
		while (!(value > tmp->value && value < get_lastval(tmp)))
		{
			do_rotate(&tmp);
			count++;
		}
	}
	free_list(tmp);
	return (count);
}

int		brev_to_sort(t_stack *stackb, int value, int curlow, int curhigh) //alwasy returning 0
{
	int			count;
	t_stack		*tmp;

	count = 0;
	if (!stackb)
		return (0);
	tmp = duplicate_stack(stackb);
	if (value > curhigh || value < curlow)
	{
		while(tmp->value != curhigh)
		{
			do_rev_rotate(&tmp);	
			count--;
		}
	}
	else
	{
		while (!(value > tmp->value && value < get_lastval(tmp))) // this will alwasy work as long as there is 2 or more values in the list
		{
			do_rev_rotate(&tmp);
			count--;
		}
	}
	free_list(tmp);
	return (count);
}

void	set_moves(t_all **all, int total, int amove, int bmove)
{
	if (total < (*all)->moves.total)
	{
		(*all)->moves.total = total;
		(*all)->moves.amoves = amove;
		(*all)->moves.bmoves = bmove;
	}
}

void	fastest_combo(t_all *all, t_counts *counts)
{
	int			rotrot;
	int			rotrev;
	int			revrot;
	int			revrev;

	rotrot = (ft_abs(counts->arot - counts->brot) +
		(counts->arot < counts->brot ? counts->arot : counts->brot));
	rotrev = counts->arot - counts->brev;
	revrot = (counts->arev * -1) + counts->brot;
	revrev = (ft_abs(counts->arev - counts->brev) + 
		(counts->arev > counts->brev ? counts->arev * -1 : counts->brev * -1));;
	if (rotrot <= rotrev && rotrot <= revrot && rotrot <= revrev)
		set_moves(&all, rotrot, counts->arot, counts->brot);
	else if (rotrev <= rotrot && rotrev <= revrot && rotrev <= revrev)
		set_moves(&all, rotrev, counts->arot, counts->brev);
	else if (revrot <= rotrot && revrot <= rotrev && revrot <= revrev)
		set_moves(&all, revrot, counts->arev, counts->brot);
	else
		set_moves(&all, revrev, counts->arev, counts->brev);
}

void	get_min_moves(t_all *all, t_stack *stacka, t_stack *stackb)
{
	t_stack		*tmpa;
	t_counts	counts;

	tmpa = stacka;
	while (tmpa)
	{
		counts.arot = arot_to_top(tmpa); // counts positive
		counts.arev = arev_to_top(tmpa); // counts negative
		counts.brot = brot_to_sort(stackb, tmpa->value, all->b_curlow, all->b_curhigh); // counts positive
		counts.brev = brev_to_sort(stackb, tmpa->value, all->b_curlow, all->b_curhigh); // counts negative
		tmpa = tmpa->next;
		fastest_combo(all, &counts);
		if (all->moves.total == 0)
			break ;
	}
}

void	execute_moves(t_all *all, int amoves, int bmoves)
{
	while (amoves > 0 || bmoves > 0 || amoves < 0 || bmoves < 0)
	{
		if (amoves < 0 && bmoves < 0)
		{
			amoves++;
			bmoves++;
			do_rev_rotate(&all->stacka);
			do_rev_rotate(&all->stackb);
			ft_printf("rrr\n");
		}
		else if (amoves > 0 && bmoves > 0)
		{
			amoves--;
			bmoves--;
			do_rotate(&all->stacka);
			do_rotate(&all->stackb);
			ft_printf("rr\n");
		}
		else // basically break this entire thing into two funcitons
		{
			// we have opposite opperations or one is at 0 and need to run them seperately
			if (amoves != 0)
			{
				if (amoves > 0)
				{
					amoves--;
					do_rotate(&all->stacka);
					ft_printf("ra\n");
				}
				else
				{
					amoves++;
					do_rev_rotate(&all->stacka);
					ft_printf("rra\n");
				}
			}
			if (bmoves != 0)
			{
				if (bmoves > 0)
				{
					bmoves--;
					do_rotate(&all->stackb);
					ft_printf("rb\n");
				}
				else
				{
					bmoves++;
					do_rev_rotate(&all->stackb);
					ft_printf("rrb\n");
				}
			}
		}
	}
	if (all->stacka->value > all->b_curhigh)
		all->b_curhigh = all->stacka->value;
	if (all->stacka->value < all->b_curlow)
		all->b_curlow = all->stacka->value;
	ft_printf("			pushing: %d\n", all->stacka->value);
	do_push(&all->stackb, &all->stacka);
	ft_printf("pb\n");
	ft_printf("curlow: %d\n", all->b_curlow);
	ft_printf("curhgih: %d\n", all->b_curhigh);
}

void	push_swap(t_all *all)
{
	while (!check_sorted(all->stacka))
	{
		print_stacks(all);
		all->moves.bmoves = INT_MAX;
		all->moves.amoves = INT_MAX;
		all->moves.total = INT_MAX;
		get_min_moves(all, all->stacka, all->stackb); //this will get the data about what the smallest number of moves is for a sorted B and add the info to all->moves.
		ft_printf("amoves: %d\n", all->moves.amoves); // these are always coming out as 0
		ft_printf("bmoves: %d\n", all->moves.bmoves);
		execute_moves(all, all->moves.amoves, all->moves.bmoves); // translates, executes, updates b_curhigh or b_curlow if needed
		print_stacks(all);
		ft_printf("\n");
	}
//	move_b_to_order(all->stackb); //make this. rotates b until the highest number is at the front. which is first value > last value
//	push_back(all); // make this. // until b is empty push numbers back to a making sure to keep it in order
//	if (!check_sorted(all->stacka))
}
