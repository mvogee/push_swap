NAME = checker

SRC = main.c \
		get_stack.c \
		get_commands.c \
		# execute_commands.c \
		\
		../commands/sa.c \
		../commands/sb.c \
		../commands/ss.c \
		
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