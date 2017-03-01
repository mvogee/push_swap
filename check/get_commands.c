/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_commands.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvogee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/24 13:16:18 by mvogee            #+#    #+#             */
/*   Updated: 2017/02/27 14:58:23 by mvogee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		translate_command(char *command)
{
	if (ft_strequ(command, "sa"))
		return (SA);
	else if (ft_strequ(command, "sb"))
		return (SB);
	else if (ft_strequ(command, "ss"))
		return (SS);
	else if (ft_strequ(command, "pa"))
		return (PA);
	else if (ft_strequ(command, "pb"))
		return (PB);
	else if (ft_strequ(command, "ra"))
		return (RA);
	else if (ft_strequ(command, "rb"))
		return (RB);
	else if (ft_strequ(command, "rr"))
		return (RR);
	else if (ft_strequ(command, "rra"))
		return (RRA);
	else if (ft_strequ(command, "rrb"))
		return (RRB);
	else if (ft_strequ(command, "rrr"))
		return (RRR);
	else
		throw_error();
	return (0);
}

void	add_command(char *line, t_all *all)
{
	int		*tmp;
	int		count;

	count = 0;
	all->numcommands += 1;
	tmp = (int*)ft_memalloc(sizeof(int) * all->numcommands);
	while (count < all->numcommands - 1)
	{
		tmp[count] = all->commands[count];
		count++;
	}
	tmp[count] = translate_command(line);
	if (!tmp[count]) // this is testing to see if this will terminate our program for us when an invalid is given.
		throw_error();
	count = 0;
	free(all->commands);
	all->commands = (int*)ft_memalloc(sizeof(int) * all->numcommands);
	while (count < all->numcommands)
	{
		all->commands[count] = tmp[count];
		count++;
	}
	free(tmp);
}

void	get_commands(t_all *all)
{
	char	*line;

	line = NULL;
	while (get_next_line(STDIN_FILENO, &line) > 0)
	{
		if (!line || ft_strequ(line, ""))
			break ;
		else
			add_command(line, all);
	}
}
