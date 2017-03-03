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

int		brot_to_sort(t_stack *stackb, int value, int curlow, int curhigh) //done needs testing
{
	int			count;
	t_stack		*tmp;

	count = 0;
	if (!stackb)
		return (0);
	tmp = dublicate_stack(stackb);
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

int		brev_to_sort(t_stack *stackb, int value, int curlow, int curhigh) //done needs testing
{
	int			count;
	t_stack		*tmp;

	count = 0;
	if (!stackb) // if b is empty or does not exist
		return (0);
	tmp = dublicate_stack(stackb);
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
	free_list(tmp);
	return (count);
}

void	set_moves(t_all *all, int total, int amove, int bmove)
{
	if (total < all->moves->total)
	{
		all->moves->total = total;
		all->moves->amoves = amoves;
		all->moves->bmoves = bmoves;
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
		(counts->arev > counts->brev ? counts->arev * -1 : counts->brev * -1));
	if (rotrot < rotrev && rotrot < revrot && rotrot < revrev)
		set_moves(all, rotrot, counts->arot, counts->brot); //make this funciton
	else if (rotrev < rotrot && rotrev < revrot && rotrev < revrev)
		set_moves(all, rotrev, counts->arot, counts->brev);
	else if (revrot < rotrot && revrot < rotrev && revrot < revrev)
		set_moves(all, revrot, counts->arev, counts->brot);
	else
		set_moves(all, revrev, counts->arev, counts->brev);
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
		counts.brot = brot_to_sort(stackb, tmpa->value, all->b_culow, all->b_curhigh); // counts positive
		counts.brev = brev_to_sort(stackb, tmpa->value, all->b_curlow, all->b_curhigh); // counts negative
		tmpa = tmpa->next;
		fastest_combo(all, &counts); //will find the fastest combo of opperations and determine if it beats the current fastest op
		if (all->moves->total == 0) // if there is a 0 that means we can just push the first item no need to check other options
			break ;
	}
	tmpa = stacka;
}

void	push_swap(t_all *all)
{
	while (!check_sorted(all->stacka))
	{
		all->moves->bmoves = MAX_INT;
		all->moves->amoves = MAX_INT;
		all->moves->total = MAX_INT;
		get_min_moves(all, all->stacka, all->stackb); //make this. this will get the data about what the smallest number of moves is for a sorted b and add the info to all->moves.
		execute_move(all); //make this. translates, executes, and resets the data in all->moves updates b_curhigh or b_curlow if needed
	}
	move_b_to_order(all->stackb); // rotates b until the highest number is at the front. which is first value > last value
	push_back(all); // make this. // until b is empty push numbers back to a making sure to keep it in order
	if (!check_sorted(all->stacka))
}
