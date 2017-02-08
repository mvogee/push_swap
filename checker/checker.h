#ifndef CHECKER_H
# define CHECKER_H

# include <unistd.h>
# include <stdlib.h>
# include "ft_printf.h"
# include "libft.h"

typedef enum	e_command
{
	SA = 1,
	SB = 2,
	SS = 3,
	PA = 4,
	PB = 5,
	RA = 6,
	RB = 7,
	RR = 8,
	RRA = 9,
	RRB = 10,
	RRR = 11
}				t_commands;

typedef struct	s_stack
{
	int		*stacka;
	int		*stackb;
	int		size;
	int		*commands;
	int		numcommands;
}				t_stack;

/*
** main.c
*/
void	throw_error(void);
void	get_commands(t_stack *stack);
int		main(int ac, char **av);

/*
** get_stack.c
*/
int		get_size(char *str);
void	get_string_stack(char *str, t_stack *stack);
int		get_size_list(int ac, char **av);
void	get_list_stack(int ac, char **av, t_stack *stack);

/*
** get_commands
*/
int		translate_command(char *command);
void	add_command(char *line, t_stack *stack);
void	get_commands(t_stack *stack);

#endif