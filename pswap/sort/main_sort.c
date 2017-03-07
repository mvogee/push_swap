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
		(counts->arev > counts->brev ? counts->arev * -1 : counts->brev * -1));
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
		counts.arot = arot_to_top(tmpa);
		counts.arev = arev_to_top(tmpa);
		counts.brot = brot_to_sort(stackb, tmpa->value,
			all->b_curlow, all->b_curhigh);
		counts.brev = brev_to_sort(stackb, tmpa->value,
			all->b_curlow, all->b_curhigh);
		tmpa = tmpa->next;
		fastest_combo(all, &counts);
		if (all->moves.total == 0)
			break ;
	}
}

void	push_swap(t_all *all)
{
	if (!check_sorted(all->stacka))
	{
		while (all->sizea > 0)
		{
			all->moves.bmoves = INT_MAX;
			all->moves.amoves = INT_MAX;
			all->moves.total = INT_MAX;
			get_min_moves(all, all->stacka, all->stackb);
			execute_moves(all, all->moves.amoves, all->moves.bmoves);
			all->sizea--;
			all->sizeb++;
		}
		move_b_to_order(all);
		push_back(all);
	}
}
