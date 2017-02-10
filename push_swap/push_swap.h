#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include "ft_printf.h"
# include "libft.h"

typedef struct		s_stack
{
	int				value;
	struct s_stack	*next;
}					t_stack;

typedef struct		s_stacks
{
	t_stack			stacka;
	t_stack			stackb;
	int				sizea;
	int				sizeb;
}					t_stacks;

#endif