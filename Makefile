CHECKER = checker

PSWAP = push_swap

#checker
SRC1 =	./checker/main.c \
		./checker/get_commands.c \
		./checker/execute_commands.c \

#push_swap
SRC2 =	./push_swap/main_.c \
		./push_swap/sort/intuitive_sort.c \

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
			-I./checker \
			-I./push_swap \
			-I./push_swap/sort \
			
LINK = -L./ft_printf/ ./ft_printf/libftprintf.a \
		-L./libft/ ./libft/libft.a \
 #need to make these

CC = gcc

CFLAGS = -Wall -Wextra -Werror



all: makeprintf makelibft $(CHECKER) $(PSWAP)

checker: makeprintf makelibft $(CHECKER)

push_swap: makeprintf makelibft $(PSWAP)

makelibft:
	@make -C libft all

makeprintf:
	@make -C ft_printf all

$(CHECKER):
	$(CC) $(CFLAGS) -o $(CHECKER) $(SRC1) $(SHAREDSRC) $(INCLUDE) $(LINK)

$(PSWAP):
	$(CC) $(CFLAGS) -o $(PSWAP) $(SRC2) $(SHAREDSRC) $(INCLUDE) $(LINK)

clean_all: clean clean_libft clean_ftprintf

clean:
	/bin/ rm -f $(OBJ1) $(OBJ2)
clean_libft:
	@make -C libft clean
clean_ftprintf:
	@make -C ft_printf clean

fclean_all: fclean fclean_libft fclean_ftprintf

fclean: clean fclean_checker fclean_pswap

fclean_checker:
	/bin/ rm -f $(CHECKER)
fclean_pswap:
	/bin/ rm -f $(PSWAP)
fclean_libft:
	@make -C libft fclean
fclean_ftprintf:
	@make -C ft_printf fclean

re_all: fclean_all all

re: fclean $(CHECKER) $(PSWAP)

re_pswap: fclean_pswap $(PSWAP)

re_checker: fclean_checker $(CHECKER)

