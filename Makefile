CHECKER = checker

PSWAP = push_swap

#checker
SRC1 =	./check/main.c \
		./check/get_commands.c \
		./check/execute_commands.c \

#push_swap
SRC2 =	./pswap/main.c \
		./pswap/sort/extras.c \
		./pswap/sort/newsort.c \
		#./pswap/sort/experimental.c

#commands
SHAREDSRC =	get_stack.c \
			./commands/push.c \
			./commands/rev_rotate.c \
			./commands/rotate.c \
			./commands/swap.c \
			./error.c \


OBJ1 = $(SRC1:.c=.o) $(SHAREDSRC:.c=.o)
OBJ2 = $(SRC2:.c=.o) $(SHAREDSRC:.c=.o)

INCLUDE = -I./libft \
			-I./ft_printf \
			-I./commands \
			-I./includes \
			-I./pswap/sort \
			
LINK = ./ft_printf/libftprintf.a \
		./libft/libft.a \
 #need to make these

CC = gcc

CFLAGS = -Wall -Wextra -Werror

all: makeprintf makelibft $(CHECKER) $(PSWAP)

checker: makeprintf makelibft $(CHECKER)

pswap: makeprintf makelibft $(PSWAP)

makelibft:
	@make -C libft all

makeprintf:
	@make -C ft_printf all

$(CHECKER):
	$(CC) $(CFLAGS) -o $(CHECKER) $(SRC1) $(SHAREDSRC) $(INCLUDE) $(LINK)

$(PSWAP):
	$(CC) $(CFLAGS) -o $(PSWAP) $(SRC2) $(SHAREDSRC) $(INCLUDE) $(LINK)
	
clean_libft:
	@make -C libft clean

clean_ftprintf:
	@make -C ft_printf clean

clean: clean_libft clean_ftprintf
	/bin/rm -f $(OBJ1) $(OBJ2)

fclean: clean fclean_checker fclean_pswap fclean_libft fclean_ftprintf

fclean_checker: clean
	/bin/rm -f $(CHECKER)

fclean_pswap: clean
	/bin/rm -f $(PSWAP)

fclean_libft:
	@make -C libft fclean

fclean_ftprintf:
	@make -C ft_printf fclean

re: fclean $(CHECKER) $(PSWAP)

re_pswap: fclean_pswap $(PSWAP)

re_checker: fclean_checker $(CHECKER)

