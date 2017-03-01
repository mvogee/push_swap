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

void	get_min_moves(t_all *all, t_stack *stacka, t_stack *stackb)
{
	t_stack	*tmpa;
	int		arot;
	int		arev;
	int		brot; // potential to make array or struct out of these intead of using all these 
	int		brev;

	tmpa = stacka; //may need to make duplicate of stacka so we arent changing the original stack when we itterate
	while (tmpa)
	{
		arot = arot_to_top(tmpa); // make this function
		arev = arev_to_top(tmpa); // make this funciton
		brot = brot_to_sort(stackb, tmpa->value); //make this function
		brev = brev_to_sort(stackb, tmpa->value); // make this function
		tmpa = tmpa->next;
		fastest_combo(all, arot, arev, brot, brev); // make this. will find the fastest combo of opperations and determine if it beats the current fastest op
	}
	tmpa = stacka;
}

void	push_swap(t_all *all)
{
	while (!check_sorted(all->stacka))
	{ // get_min_moves is where the most work i done.
		get_min_moves(all, all->stacka, all->stackb); //make this. this will get the data about what the smallest number of moves is for a sorted b and add the info to all->moves.
		execute_move(all); //make this. translates, executes, and resets the data in all->moves
	}
	move_b_to_order(all->stackb); // rotates b until the highest number is at the front. which is first value > last value
	push_back(all); // make this. // until b is empty push numbers back to a making sure to keep it in order
	if (!check_sorted(all->stacka))
}
