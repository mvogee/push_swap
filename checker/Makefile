NAME = checker

SRC = main.c \
		get_stack.c \
		get_commands.c \
		
OBJ = $(SRC:.c=.o)

INCLUDE = -I../libft \
			-I../ft_printf \

LINK = ../ft_printf/libftprintf.a \
		../libft/libft.a \
		

CC = gcc

CFLAGS = -Wall -Wextra -Werror -o

all: $(NAME)

$(NAME):
		$(CC) $(CFLAGS) $(NAME) $(SRC) $(INCLUDE) $(LINK)

clean:
	/bin/rm -f $(OBJ)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all