/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_stack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvogee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/24 12:15:50 by mvogee            #+#    #+#             */
/*   Updated: 2017/02/24 12:15:58 by mvogee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		get_size(char *str)
{
	int			count;

	count = 0;
	while (str && *str)
	{
		while (*str == ' ')
			str++;
		if (*str && !ft_isdigit(*str) && *str != '-')
			throw_error();
		else if (*str && (ft_isdigit(*str) || (*str == '-' &&
			ft_isdigit(*(str + 1)))))
		{
			count++;
			while (*str && (ft_isdigit(*str) || *str == '-'))
				str++;
		}
		else if (*str)
			throw_error();
	}
	if (count == 0)
		throw_error();
	return (count);
}

t_stack	*add_end_node(t_stack *stacka, long value)
{
	t_stack		*node;
	t_stack		*head;

	if (value > INT_MAX || value < INT_MIN)
		throw_error();
	node = (t_stack*)malloc(sizeof(t_stack));
	node->value = (int)value;
	node->next = NULL;
	node->prev = NULL;
	if (stacka == NULL)
	{
		head = NULL;
		stacka = node;
		return (stacka);
	}
	else
	{
		head = stacka;
		while (stacka->next)
			stacka = stacka->next;
		node->prev = stacka;
		stacka->next = node;
	}
	return (head);
}

void	get_string_stack(char *str, t_all *all)
{
	int			count;

	count = 0;
	all->size = get_size(str);
	all->stacka = NULL;
	while (count < all->size)
	{
		if (ft_isdigit(*str) || (*str == '-' && ft_isdigit(*(str + 1))))
		{
			all->stacka = add_end_node(all->stacka, ft_atol(str));
			count++;
			while (ft_isdigit(*str) || (*str == '-' && ft_isdigit(*(str + 1))))
				str++;
		}
		if (*str && !(ft_isdigit(*str) && *str != '-'))
			str++;
	}
}

int		get_size_list(int ac, char **av)
{
	int			count;
	int			count2;
	int			size;

	count = 1;
	size = 0;
	count2 = 0;
	while (count < ac)
	{
		if (ft_isdigit(*av[count]) || ft_isdigit(*(av[count] + 1)))
		{
			while (av[count][count2])
			{
				if (!ft_isdigit(av[count][count2]) && av[count][count2] != '-')
					throw_error();
				count2++;
			}
			count2 = 0;
			size++;
		}
		else
			throw_error();
		count++;
	}
	return (size);
}

void	get_list_stack(int ac, char **av, t_all *all)
{
	int			count;
	int			avpos;

	count = 0;
	avpos = 1;
	all->size = get_size_list(ac, av);
	all->stacka = NULL;
	while (count < all->size)
	{
		all->stacka = add_end_node(all->stacka, ft_atol(av[avpos]));
		avpos++;
		count++;
	}
}
