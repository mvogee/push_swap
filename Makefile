NAME1 = checker

NAME2 = push_swap

SRC1 = -I./checker/ \
		main.c \
		get_stack.c \
		get_commands.c \
		execute_commands.c \

SRC2 = -I./push_swap/ \
		main.c \
		get_stack.c \


INCLUDE = -I./libft \
			-I./ft_printf \
			-I./commands \
			
LINK = ../ft_printf/libftprintf.a \
		../libft/libft.a \
 #need to make these