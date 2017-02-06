//42 header

#include "checker.h"

// working correctly
int get_size(char *str)
{
	int		count;

	count = 0;
	while (str && *str)
	{
		while (*str == ' ')
			str++;
		if (*str && !ft_isdigit(*str))
		{
			ft_printf("error\n");
			exit(0);
		}
		else if (*str && ft_isdigit(*str))
		{
			count++;
			while (*str && ft_isdigit(*str))
				str++;
		}
	}
	return (count);
}

int		get_numcommands(char *commands)
{
	int		count;
	int		flag;

	count = 0;
	flag = 0;
	while (commands && *commands)
	{
		if (flag == 0 && ft_isalpha(*commands))
		{
			count++;
			flag = 1;
		}
		if (flag = 1 && *commands == '\n')
			flag = 0;
		commands++;
	}
	return (count);
}

int		translate_command(char *commands)
{
	char	*comm;
	int		len;

	len = 0;
	while (ft_isalpha(*commands))
	{
		len++;
		commands++;
	}
	comm = ft_strsub(commands, len);
	
}

int		*parse_commands(char *commands)
{
	int		size;
	int		count;
	int		*cmdarray;

	count = 0;
	size = get_numcommands(commands);
	cmdarray = (int*)malloc(sizeof(int) * size + 1);
	while (count < size)
	{
		while (commands && !ft_isalpha(*commands) && *commands)
			commands++;
		cmdarray[count] = translate_command(commands); // make this function
		while (*commands && *commands != '\n')
			commands++;
		count++;
	}
	return (cmdarray);
}

int		*get_commands(void)
{
	char	*buff;
	char	*commands;
	char	*hold;
	int		r;

	r = read(1, buff, 500);
	commands = ft_strdup(buff);
	if (!commands || r <= 0)
		exit(0);
	while (r > 0)
	{
		r = read(1, buff, 500)
		if (r <= 0)
			break ;
		hold = ft_strdup(commands);
		ft_memdel(commands);
		commands = ft_strjoin(hold, buff);
		ft_memdel(hold);
	}
//	ft_memdel(commands); this needs to happen to avoid mem leak
	return (parse_commands(commands)); // make this
}

int		main(int ac, char **av)
{
	int		size;
	int		*stack_a;
	int		*stack_b;
	int		*commands;

	size = 0;
	if (ac != 2)
	{
		ft_printf("wrong number of arguments\n");
		return (0);
	}
	else
	{
		if (av[1])
			size = get_size(av[1]);
		ft_printf("size: %d\n", size);
		stack_a = (int*)malloc(sizeof(int) * size);
		stack_b = (int*)malloc(sizeof(int) * size);
		commands = get_commans() // working on this
//		fill_stacka(av, stack_a, size);// make this
//		execute_commands(commands, stack_a, stack_b, size) // make this
//		check_correctness(stack_a);
	}
	return (0);
}
