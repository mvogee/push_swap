#this makefile will not exist in the final. we will just compile this from the root.

NAME = checker

SRC = main.c \
		get_stack.c \
		get_commands.c \
		execute_commands.c \
		\
		../commands/swap.c \
		../commands/push.c \
		../commands/rotate.c \
		../commands/rev_rotate.c \
		# can we find a better way of including the command functions?
		# need to figure out the "good way" of making and cleaning from other directories
OBJ = $(SRC:.c=.o)

INCLUDE = -I../libft \
			-I../ft_printf \
			-I../commands \

LINK = ../ft_printf/libftprintf.a \
		../libft/libft.a \
		

CC = gcc

CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME):
		$(CC) $(CFLAGS) -o $(NAME) $(INCLUDE) $(LINK) $(SRC)

clean:
	/bin/rm -f $(OBJ)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all