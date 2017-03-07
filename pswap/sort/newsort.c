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
	ft_printf("arot_to_top: %d\n", count);
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
	ft_printf("arev_to_top: %d\n", count - 1);
	return (count - 1); // minus one because it takes one more action to put it at the top
}

int		brot_to_sort(t_stack *stackb, int value, int curlow, int curhigh)
{
	int			count;
	t_stack		*tmp;

	count = 0;
	if (!stackb)
		return (0);
	ft_printf("a\n");
	tmp = duplicate_stack(stackb);
	ft_printf("b\n");
	if (value > curhigh || value < curlow)
	{
		ft_printf("c\n");
		while (tmp->value != curhigh)
		{
			do_rotate(&tmp);
			count++;
		}
	}
	else
	{
		ft_printf("d\n");
		while (!(value > tmp->value && value < get_lastval(tmp)))
		{
			do_rotate(&tmp);
			ft_printf("12\n");
			count++;
		}
	}
	ft_printf("f\n");
	//free_list(tmp);
	ft_printf("brot_to_sort: %d\n", count);
	return (count);
}

int		brev_to_sort(t_stack *stackb, int value, int curlow, int curhigh) //alwasy returning 0
{
	int			count;
	t_stack		*tmp;

	count = 0;
	if (!stackb) // if b is empty or does not exist
		return (0);
	tmp = duplicate_stack(stackb);
	if (value > curhigh || value < curlow) // if there is only 1 node this will alwasy be triggered
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
//	free_list(tmp);
	ft_printf("brev_to_sort: %d\n", count);
	return (count);
}

void	set_moves(t_all **all, int total, int amove, int bmove)
{
	ft_printf("current total: %d\n", (*all)->moves.total);
	if (total < (*all)->moves.total)
	{
//		ft_printf("total = %d\n", total);
//		ft_printf("amoves = %d\n", amove);
//		ft_printf("bmoves = %d\n", bmove);
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
//	ft_printf("rotrot: %d\n", rotrot);
	rotrev = counts->arot - counts->brev;
//	ft_printf("rotrev: %d\n", rotrev);
	revrot = (counts->arev * -1) + counts->brot;
//	ft_printf("revrot: %d\n", revrot);
	revrev = (ft_abs(counts->arev - counts->brev) + 
		(counts->arev > counts->brev ? counts->arev * -1 : counts->brev * -1));
//	ft_printf("revrev: %d\n", revrev);
	if (rotrot <= rotrev && rotrot <= revrot && rotrot <= revrev) // theree is flawd logic in this if else block
		set_moves(&all, rotrot, counts->arot, counts->brot);
	else if (rotrev <= rotrot && rotrev <= revrot && rotrev <= revrev)
		set_moves(&all, rotrev, counts->arot, counts->brev);
	else if (revrot <= rotrot && revrot <= rotrev && revrot <= revrev)
		set_moves(&all, revrot, counts->arev, counts->brot);
	else
		set_moves(&all, revrev, counts->arev, counts->brev);
}

void	get_min_moves(t_all *all, t_stack *stacka, t_stack *stackb)
{ // segfaulting in here
	t_stack		*tmpa;
	t_counts	counts;

	tmpa = stacka;
	while (tmpa)
	{
//		ft_printf("A\n");
		counts.arot = arot_to_top(tmpa); // counts positive
//		ft_printf("AA\n");
		counts.arev = arev_to_top(tmpa); // counts negative
		ft_printf("AB\n");
		print_stacks(all);
		counts.brot = brot_to_sort(stackb, tmpa->value, all->b_curlow, all->b_curhigh); // counts positive // segfault
		print_stacks(all);
		ft_printf("AC\n");
		counts.brev = brev_to_sort(stackb, tmpa->value, all->b_curlow, all->b_curhigh); // counts negative
		ft_printf("B\n");
		print_stacks(all);
		tmpa = tmpa->next;
		fastest_combo(all, &counts); //will find the fastest combo of opperations and determine if it beats the current fastest op
//		ft_printf("C\n");
//		if (all->moves.total == 0) // if there is a 0 that means we can just push the first item no need to check other options
//			break ;
//		ft_printf("D\n");
	}
	tmpa = stacka;
}

void	execute_moves(t_all *all, int amoves, int bmoves)
{
//	ft_printf("amoves: %d\n", amoves); // amoves and bmoves is not getting calculated correctly
//	ft_printf("bmoves: %d\n", bmoves);
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
//		ft_printf("1\n");
		all->moves.bmoves = INT_MAX;
		all->moves.amoves = INT_MAX;
		all->moves.total = INT_MAX;
//		ft_printf("2\n");
		get_min_moves(all, all->stacka, all->stackb); //this will get the data about what the smallest number of moves is for a sorted B and add the info to all->moves.
//		ft_printf("3\n");
		ft_printf("amoves: %d\n", all->moves.amoves); // these are always coming out as 0
		ft_printf("bmoves: %d\n", all->moves.bmoves);
		execute_moves(all, all->moves.amoves, all->moves.bmoves); // translates, executes, updates b_curhigh or b_curlow if needed
//		ft_printf("4\n");
		print_stacks(all);
		ft_printf("\n");
	}
	// TEST NOW STUPID!
//	move_b_to_order(all->stackb); //make this. rotates b until the highest number is at the front. which is first value > last value
//	push_back(all); // make this. // until b is empty push numbers back to a making sure to keep it in order
//	if (!check_sorted(all->stacka))
}
