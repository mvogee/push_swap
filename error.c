/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvogee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/24 12:16:09 by mvogee            #+#    #+#             */
/*   Updated: 2017/02/24 12:16:19 by mvogee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_list(t_stack *stack)
{
	t_stack		*tmp;

	while (stack)
	{
		tmp = stack->next;
		free(stack);
		stack = tmp;
	}
}

void	throw_error_free(t_stack *stack)
{
	free_list(stack);
	write(2, "Error\n", 6);
	exit(EXIT_FAILURE);
}

void	throw_error(void)
{
	write(2, "Error\n", 6);
	exit(EXIT_FAILURE);
}
