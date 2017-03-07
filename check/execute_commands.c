/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_commands.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvogee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/24 13:13:59 by mvogee            #+#    #+#             */
/*   Updated: 2017/02/24 13:14:06 by mvogee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	extend_execute3(t_all *all, int command)
{
	if (command== RRB)
	{
		if (all->sizeb > 1)
			do_rev_rotate(&all->stackb);
	}
	else if (command == RRR)
	{
		if (all->sizea > 1)
			do_rev_rotate(&all->stacka);
		if (all->sizeb > 1)
			do_rev_rotate(&all->stackb);
	}
	else
		throw_error_free(all->stacka);
}

void	extend_execute2(t_all *all, int command)
{
	if (command == RA)
	{
		if (all->sizea > 1)
			do_rotate(&all->stacka);
	}
	else if (command == RB)
	{
		if (all->sizeb > 1)
			do_rotate(&all->stackb);
	}
	else if (command == RR)
	{
		if (all->sizea > 1)
			do_rotate(&all->stacka);
		if (all->sizeb > 1)
			do_rotate(&all->stackb);
	}
	else if (command == RRA)
	{
		if (all->sizea > 1)
			do_rev_rotate(&all->stacka);
	}
	else
		extend_execute3(all, command);
}

void	extend_execute(t_all *all, int command)
{
	if (command == SS)
	{
		if (all->sizea > 1)
			do_swap(&all->stacka);
		if (all->sizeb > 1)
			do_swap(&all->stackb);
	}
	else if (command == PA)
	{
		if (all->sizeb < 1)
			return ;
		do_push(&(all->stacka), &(all->stackb));
		all->sizeb -= 1;
		all->sizea += 1;
	}
	else if (command == PB)
	{
		if (all->sizea < 1)
			return ;
		do_push(&all->stackb, &all->stacka);
		all->sizea -= 1;
		all->sizeb += 1;
	}
	else
		extend_execute2(all, command);
}

void	execute_commands(t_all *all, int command)
{

	if (command == SA)
	{
		if (all->sizea > 1)
			do_swap(&all->stacka);
	}
	else if (command == SB)
	{
		if (all->sizeb > 1)
			do_swap(&all->stackb);
	}
	else
		extend_execute(all, command);
}
