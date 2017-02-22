NAME = libft.a

SRC = ft_isalpha.c \
		ft_strlen.c \
		ft_toupper.c \
		ft_isalnum.c \
		ft_isdigit.c \
		ft_tolower.c \
		ft_isascii.c \
		ft_isprint.c \
		ft_strdup.c \
		ft_strcpy.c \
		ft_strncpy.c \
		ft_strcat.c \
		ft_strncat.c \
		ft_strcmp.c \
		ft_strncmp.c \
		ft_strstr.c \
		ft_strnstr.c \
		ft_strchr.c \
		ft_strrchr.c \
		ft_memcmp.c \
		ft_memset.c \
		ft_bzero.c \
		ft_memcpy.c \
		ft_memmove.c \
		ft_memchr.c \
		ft_strlcat.c \
		ft_atoi.c \
		ft_memccpy.c \
		ft_putchar.c \
		ft_putstr.c \
		ft_putendl.c \
		ft_putnbr.c \
		ft_putchar_fd.c \
		ft_putstr_fd.c \
		ft_putendl_fd.c \
		ft_putnbr_fd.c \
		ft_memalloc.c \
		ft_memdel.c \
		ft_strnew.c \
		ft_strdel.c \
		ft_strclr.c \
		ft_striter.c \
		ft_striteri.c \
		ft_strmap.c \
		ft_strmapi.c \
		ft_strequ.c \
		ft_strnequ.c \
		ft_strsub.c \
		ft_strjoin.c \
		ft_strtrim.c \
		ft_strsplit.c \
		ft_itoa.c \
		ft_lstnew.c \
		ft_lstdelone.c \
		ft_lstdel.c \
		ft_lstadd.c \
		ft_lstiter.c \
		ft_lstmap.c \
		ft_isupper.c \
		ft_islower.c \
		ft_printbits.c \
		ft_lstaddlast.c \
		ft_findchr.c \
		get_next_line.c \
		ft_itoa_base.c \
		ft_toupperstr.c \
		ft_lltoa.c \
		ft_itoa_base_unsigned.c \
		ft_abs.c \
		ft_atol.c \

OBJS = $(SRC:.c=.o)

CC = gcc

CFLAGS = -Wall -Wextra -Werror -c

all: $(NAME)

$(NAME):
	$(CC) $(CFLAGS) $(SRC)
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)

clean: 
	/bin/rm -f $(OBJS)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
