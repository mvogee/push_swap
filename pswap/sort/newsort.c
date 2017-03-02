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

int		arot_to_top(t_stack *stacka)
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

int		arev_to_top(t_stack *stacka)
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
	return (count - 1);
}

int		brot_to_sort(t_stack *stackb, int value, int curlow, int curhigh) // unfinished
{
	int			count;
	t_stack		*tmp;

	count = 0;
	tmp = stackb;
	if (!stackb)
		return (0);
	if (!stackb->next)
	{

	}
	while(tmp->next)
}

int		brev_to_sort(t_stack *stackb, int value, int curlow, int curhigh)
{
	int			count;
	t_stack		*tmp;

	count = 0;
	if (!stackb)
		return (0);
	tmp = dublicate_stack(stackb); // make duplicate function
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
		while (!(value > tmp->value && value < get_lastval(tmp)))
		{
			do_rev_rotate(&tmp);
			count--;
		}
	}
	free_list(tmp);
	return (count);
}

void	get_min_moves(t_all *all, t_stack *stacka, t_stack *stackb) // have curlow and curhigh in all
{
	t_stack		*tmpa;
	t_counts	counts;

	tmpa = stacka; //may need to make duplicate of stacka so we arent changing the original stack when we itterate
	while (tmpa)
	{
		counts.arot = arot_to_top(tmpa); // counts positive
		counts.arev = arev_to_top(tmpa); // counts negative
		counts.brot = brot_to_sort(stackb, tmpa->value, all->b_culow, all->b_curhigh); //make this function. counts positive
		counts.brev = brev_to_sort(stackb, tmpa->value, all->b_curlow, all->b_curhigh); // make this function. counts negative
		tmpa = tmpa->next;
		fastest_combo(all, &counts); // make this. will find the fastest combo of opperations and determine if it beats the current fastest op
	}
	tmpa = stacka;
}

void	push_swap(t_all *all)
{
	while (!check_sorted(all->stacka))
	{ // get_min_moves is where the most work i done.
		get_min_moves(all, all->stacka, all->stackb); //make this. this will get the data about what the smallest number of moves is for a sorted b and add the info to all->moves.
		execute_move(all); //make this. translates, executes, and resets the data in all->moves updates b_curhigh or b_curlow if needed
	}
	move_b_to_order(all->stackb); // rotates b until the highest number is at the front. which is first value > last value
	push_back(all); // make this. // until b is empty push numbers back to a making sure to keep it in order
	if (!check_sorted(all->stacka))
}
