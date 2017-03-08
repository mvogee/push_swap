# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mvogee <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/03/07 12:44:50 by mvogee            #+#    #+#              #
#    Updated: 2017/03/07 12:44:54 by mvogee           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CHECKER = checker

PSWAP = push_swap

#checker
SRC1 =	./check/main.c \
		./check/get_commands.c \
		./check/execute_commands.c \

#push_swap
SRC2 =	./pswap/main.c \
		./pswap/sort/newsort_extras.c \
		./pswap/sort/main_sort.c \
		./pswap/sort/alternative_sort.c \
		./pswap/sort/move_calculation.c \
		./pswap/sort/execute_moves.c \
		./pswap/sort/extras.c \

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

CC = gcc

CFLAGS = -Wall -Wextra -Werror

.PHONY: all clean fclean re checker pswap makelibft makeprintf clean_ftprintf \
	clean_libft fclean_checker fclean_pswap fclean_libft fclean_ftprintf \
	re_pswap re_checker

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

re: fclean all

re_pswap: fclean_pswap $(PSWAP)

re_checker: fclean_checker $(CHECKER)

