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

void	get_commands(t_all *all)
{
	char	*line;

	line = NULL;
	while (get_next_line(STDIN_FILENO, &line) > 0)
	{
		ft_printf("line gotten\n%s\n", line);
		if (!line || ft_strequ(line, ""))
			break ;
		else
			execute_commands(all, translate_command(line));
	}
}
