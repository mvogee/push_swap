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
		if (flag == 1 && *commands == '\n')
			flag = 0;
		commands++;
	}
	return (count);
}

int		find_command(char *comm)
{
	if (ft_strcmp(ft_toupperstr(comm), "SA") == 0)
		return (SA);
	else if (ft_strcmp(ft_toupperstr(comm), "SB") == 0)
		return (SB);
	else if (ft_strcmp(ft_toupperstr(comm), "SS") == 0)
		return (SS);
	else if (ft_strcmp(ft_toupperstr(comm), "PA") == 0)
		return (PA);
	else if (ft_strcmp(ft_toupperstr(comm), "PB") == 0)
		return (PB);
	else if (ft_strcmp(ft_toupperstr(comm), "RA") == 0)
		return (RA);
	else if (ft_strcmp(ft_toupperstr(comm), "RB") == 0)
		return (RB);
	else if (ft_strcmp(ft_toupperstr(comm), "RR") == 0)
		return (RR);
	else if (ft_strcmp(ft_toupperstr(comm), "RRA") == 0)
		return (RRA);
	else if (ft_strcmp(ft_toupperstr(comm), "RRB") == 0)
		return (RRB);
	else if (ft_strcmp(ft_toupperstr(comm), "RRR") == 0)
		return (RRR);
	else
		return (0);
}

int		translate_command(char *commands)
{
	char	*comm;
	int		len;
	int		ret;

	len = 0;
	while (ft_isalpha(*commands))
	{
		len++;
		commands++;
	}
	comm = ft_strsub(commands, 0, len);
	if (!comm)
		return (0);
	ret = find_command(comm);
	ft_memdel((void**)comm);
	return (ret);
}

int		*parse_commands(char *commands)
{
	int		size;
	int		count;
	int		*cmdarray;

	count = 0;
	size = get_numcommands(commands);
	cmdarray = (int*)ft_memalloc(sizeof(int) * size + 1);
	while (count < size)
	{
		while (commands && !ft_isalpha(*commands) && *commands)
			commands++;
		cmdarray[count] = translate_command(commands); // make this function
		while (*commands && *commands != '\n')
			commands++;
		count++;
	}
	cmdarray[count] = -1;
	ft_memdel((void**)commands);
	return (cmdarray);
}

int		*get_commands(void)
{
	char	*buff;
	char	*commands;
	char	*hold;
	int		r;

	buff = NULL;
	r = read(0, buff, 500);
	ft_printf("%s\n", buff);
	commands = ft_strdup(buff);
	if (!commands || r <= 0)
		exit(0);
	ft_printf("get_commands");
	while (r > 0)
	{
		r = read(0, buff, 500);
		if (r <= 0)
			break ;
		hold = ft_strdup(commands);
		ft_memdel((void**)commands);
		commands = ft_strjoin(hold, buff);
		ft_memdel((void**)hold);
		ft_printf("get_commands loop\n");
	}
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
		ft_printf("\n");
		return (0);
	}
	else
	{
		if (av[1])
			size = get_size(av[1]);
		ft_printf("size: %d\n", size);
		stack_a = (int*)ft_memalloc(sizeof(int) * size);
		stack_b = (int*)ft_memalloc(sizeof(int) * size);
		commands = get_commands(); // working on this
		for (int i = 0; i <= size; i++)
			ft_printf("%d\n", commands[i]);
//		fill_stacka(av, stack_a, size);// make this
//		execute_commands(commands, stack_a, stack_b, size) // make this
//		check_correctness(stack_a);
	}
	return (0);
}
