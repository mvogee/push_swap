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

void	get_string_stack(char *str, t_stack *stack)
{
	int		count;

	count = 0;
	stack->size = get_size(str);
	stack->stacka = (int*)ft_memalloc(sizeof(int) * stack->size);
	stack->stackb = (int*)ft_memalloc(sizeof(int) * stack->size);
	while (count < stack->size)
	{
		if (ft_isdigit(*str))
		{
			stack->stacka[count] = ft_atoi(str);
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
 // stacka[0] is the top of the stack
void	get_list_stack(int ac, char **av, t_stack *stack)
{
	int		count;
	int		avpos;

	count = 0;
	avpos = 1;
	stack->size = get_size_list(ac, av); // gets the size of the stack and error checks the input
	stack->stacka = (int*)ft_memalloc(sizeof(int) * stack->size);
	stack->stackb = (int*)ft_memalloc(sizeof(int) * stack->size);
	while (count < stack->size)
	{
		stack->stacka[count] = ft_atoi(av[avpos]);
		avpos++;
		count++;
	}
}


