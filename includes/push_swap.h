/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvogee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/24 13:23:19 by mvogee            #+#    #+#             */
/*   Updated: 2017/02/24 13:23:21 by mvogee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
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

typedef struct		s_moves
{
	int				total;
	int				amoves;
	int				bmoves;
}					t_moves;

typedef struct		s_counts
{
	int		arot;
	int		arev;
	int		brot;
	int		brev;
}					t_counts;

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
	t_moves			moves;
	int				size;
	int				sizea;
	int				sizeb;
	int				numcommands;
	int				b_curhigh;
	int				b_curlow;
}					t_all;

/*
** main.c
*/

void				check_sort(t_all *all);
int					main(int ac, char **av);
void				check_duplicates(t_all *all);
void				print_stacks(t_all *all);

/*
** get_stack.c
*/

int					get_size(char *str);
t_stack				*add_end_node(t_stack *stacka, long value);
void				get_string_stack(char *str, t_all *all);
int					get_size_list(int ac, char **av);
void				get_list_stack(int ac, char **av, t_all *all);

/*
** get_commands
*/

int					translate_command(char *command);
void				get_commands(t_all *all);

/*
** execute_commands.c
*/

void				extend_execute3(t_all *all, int command);
void				extend_execute2(t_all *all, int command);
void				extend_execute(t_all *all, int command);
void				execute_commands(t_all *all, int command);

/*
** command execution functions
*/

void				do_swap(t_stack **stack);
void				do_push(t_stack **pushto, t_stack **pushfrom);
void				do_rotate(t_stack **stack);
void				do_rev_rotate(t_stack **stack);

/*
** alternative_sort.c
*/

void				three_sort(t_stack **stack, char c);
int					pushback_extention(t_all **all, int count);
void				start_pushback(t_all **all);
void				push_swap_extended(t_all *all, int avalue,
										int aval_one, int avaln);
void				alternative_sort(t_all *all);

/*
** main_sort.c
*/

void				set_moves(t_all **all, int total, int amove, int bmove);
void				fastest_combo(t_all *all, t_counts *counts);
void				get_min_moves(t_all *all, t_stack *stacka, t_stack *stackb);
void				push_swap(t_all *all);

/*
** execute_moves.c
*/

void				tandom_run(t_all *all, int *amoves, int *bmoves);
void				a_moves(t_all *all, int *amoves);
void				b_moves(t_all *all, int *bmoves);
void				execute_moves(t_all *all, int amoves, int bmoves);

/*
** move_calculaton.c
*/

int					arot_to_top(t_stack *stacka);
int					arev_to_top(t_stack *stacka);
int					brot_to_sort(t_stack *stackb, int value,
									int curlow, int curhigh);
int					brev_to_sort(t_stack *stackb, int value,
									int curlow, int curhigh);

/*
** newsort_extras.c
*/

t_stack				*duplicate_stack(t_stack *stack);
int					get_lastval(t_stack *stack);
int					check_sorted(t_stack *stack);
void				move_b_to_order(t_all *all);
void				push_back(t_all *all);

/*
** extras.c
*/

void				sort_b(t_stack **stack);

/*
** error.c
*/

void				free_list(t_stack *stack);
void				throw_error_free(t_stack *stack);
void				throw_error(void);

#endif
