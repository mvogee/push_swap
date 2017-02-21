#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include "ft_printf.h"
# include "libft.h"

typedef enum		e_command
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
}					t_commands;

typedef struct		s_stack
{
	int				value;
	struct s_stack	*next;
	struct s_stack	*prev;

}					t_stack;

typedef struct		s_all
{
	t_stack			*stacka;
	t_stack			*stackb;
	int				size;
	int				sizea;
	int				sizeb;
	int				*commands;
	int				numcommands;
}					t_all;

/*
** main.c
*/
void				throw_error(void);
void				check_sort(t_all *all);
int					main(int ac, char **av); // this covers both progams
void				check_duplicates(t_all *all);
void				print_stacks(t_all *all);
/*
** get_stack.c
*/
int					get_size(char *str);
t_stack				*add_end_node(t_stack *stacka, int value);
void				get_string_stack(char *str, t_all *all);
int					get_size_list(int ac, char **av);
void				get_list_stack(int ac, char **av, t_all *all);

/*
** get_commands
*/
int					translate_command(char *command);
void				add_command(char *line, t_all *all);
void				get_commands(t_all *all);

/*
** execute_commands.c
*/
void				extend_execute3(t_all *all, int count);
void				extend_execute2(t_all *all, int count);
void				extend_execute(t_all *all, int count);
void				execute_commands(t_all *all);
/*
** command execution functions
*/
void				do_swap(t_stack **stack);
void				do_push(t_stack **pushto, t_stack **pushfrom);
void				do_rotate(t_stack **stack);
void				do_rev_rotate(t_stack **stack);


/*
** experimental.c
*/
void				three_sort(t_stack **stack, char c);
int					check_sorted(t_stack *stack);
int					get_lastval(t_stack *stack);
void				sort_b(t_stack **stack);
void				start_pushback(t_all **all);
void				push_swap(t_all *all);

#endif