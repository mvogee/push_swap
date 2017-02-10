// 42 header

#include "push_swap.h"

t_stack	*add_end_node(t_stack *stack, int value)
{
	t_stack *head;
	t_stack *node;

	node = (t_stack*)malloc(sizeof(t_stack));
	node->value = value;
	if (!stack)
	{
		head = NULL;
		node->next = NULL;
		return (node);
	}
	else
	{
		head = stack;
		while (stack->next)
			stack = stack->next;
		stack->next = node;
	}
	return (head);
}

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

void	get_string_stack(char *str, t_stacks *stacks)
{
	int		count;

	count = 0;
	stacks->sizea = get_size(str);
	stacks->stacka = NULL;
	while (count < stacks->sizea)
	{
		if (ft_isdigit(*str))
		{
			stacks->stacka = add_end_node(stacks->stacka, ft_atoi(str));
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

void	get_list_stack(int ac, char **av, t_stacks *stacks)
{
	int		count;
	int		avpos;

	count = 0;
	avpos = 1;
	stacks->sizea = get_size_list(ac, av);
	stacks->stacka = NULL;
	while (count < stacks->sizea)
	{
		stacks->stacka = add_end_node(stacks->stacka, ft_atoi(av[avpos]));
		avpos++;
		count++;
	}
}
