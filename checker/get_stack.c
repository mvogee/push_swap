// 42 header here

#include "checker.h"

int		get_size(char *str)
{
	int		count;

	count = 0;
	while (str && *str)
	{
		while (*str == ' ')
			str++;
		if (*str && !ft_isdigit(*str))
			throw_error();
		else if (*str && ft_isdigit(*str))
		{
			count++;
			while (*str && ft_isdigit(*str))
				str++;
		}
	}
	if (count == 0)
		throw_error();
	return (count);
}

t_stack	*add_end_node(t_stack *stacka, int value)
{
	t_stack		*node;
	t_stack		*head;

	node = (t_stack*)malloc(sizeof(t_stack));
	node->value = value;
	node->next = NULL;
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
		stacka->next = node;
	}
	return (head);
}

void	get_string_stack(char *str, t_all *all)
{
	int		count;

	count = 0;
	all->size = get_size(str);
	all->stacka = NULL;
	while (count < all->size)
	{
		if (ft_isdigit(*str))
		{
			all->stacka = add_end_node(all->stacka, ft_atoi(str));
			count++;
			while (ft_isdigit(*str))
				str++;
		}
		if (*str && !(ft_isdigit(*str)))
			str++;
	}
}

int		get_size_list(int ac, char **av)
{
	int		count;
	int		count2;
	int		size;

	count = 1;
	size = 0;
	count2 = 0;
	while (count < ac)
	{
		if (ft_isdigit(*av[count]))
		{
			while (av[count][count2])
			{
				if (!ft_isdigit(av[count][count2]))
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
	int		count;
	int		avpos;

	count = 0;
	avpos = 1;
	all->size = get_size_list(ac, av);
	all->stacka = NULL;
	while (count < all->size)
	{
		all->stacka = add_end_node(all->stacka, ft_atoi(av[avpos]));
		avpos++;
		count++;
	}
}
