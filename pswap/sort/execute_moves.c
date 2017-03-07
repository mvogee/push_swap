/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_moves.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvogee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/07 13:27:50 by mvogee            #+#    #+#             */
/*   Updated: 2017/03/07 13:27:51 by mvogee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	tandom_run(t_all *all, int *amoves, int *bmoves)
{
	if (*amoves < 0 && *bmoves < 0)
	{
		*amoves += 1;
		*bmoves += 1;
		do_rev_rotate(&all->stacka);
		do_rev_rotate(&all->stackb);
		ft_printf("rrr\n");
	}
	else if (*amoves > 0 && *bmoves > 0)
	{
		*amoves -= 1;
		*bmoves -= 1;
		do_rotate(&all->stacka);
		do_rotate(&all->stackb);
		ft_printf("rr\n");
	}
}

void	a_moves(t_all *all, int *amoves)
{
	if (*amoves > 0)
	{
		*amoves -= 1;
		do_rotate(&all->stacka);
		ft_printf("ra\n");
	}
	else if (*amoves < 0)
	{
		*amoves += 1;
		do_rev_rotate(&all->stacka);
		ft_printf("rra\n");
	}
}

void	b_moves(t_all *all, int *bmoves)
{
	if (*bmoves > 0)
	{
		*bmoves -= 1;
		do_rotate(&all->stackb);
		ft_printf("rb\n");
	}
	else
	{
		*bmoves += 1;
		do_rev_rotate(&all->stackb);
		ft_printf("rrb\n");
	}
}

void	execute_moves(t_all *all, int amoves, int bmoves)
{
	while (amoves > 0 || bmoves > 0 || amoves < 0 || bmoves < 0)
	{
		if ((amoves < 0 && bmoves < 0) || (amoves > 0 && bmoves > 0))
			tandom_run(all, &amoves, &bmoves);
		else
		{
			if (amoves != 0)
				a_moves(all, &amoves);
			if (bmoves != 0)
				b_moves(all, &bmoves);
		}
	}
	if (all->stacka->value > all->b_curhigh)
		all->b_curhigh = all->stacka->value;
	if (all->stacka->value < all->b_curlow)
		all->b_curlow = all->stacka->value;
	do_push(&all->stackb, &all->stacka);
	ft_printf("pb\n");
}
