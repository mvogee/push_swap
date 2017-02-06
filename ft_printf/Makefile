NAME = libftprintf.a

SRCS = ft_printf.c \
		moveto.c	\
		get_formats.c \
		checkfor.c	\
		get_args.c \
		do_precision.c \
		do_minwidth.c \
		do_signs.c \
		ft_uni_to_utf8.c \
		\
		specifier_functions/dispatcher.c \
		specifier_functions/spec_c.c \
		specifier_functions/spec_d.c \
		specifier_functions/spec_i.c \
		specifier_functions/spec_o.c \
		specifier_functions/spec_p.c \
		specifier_functions/spec_pc.c \
		specifier_functions/spec_s.c \
		specifier_functions/spec_u.c \
		specifier_functions/spec_up_c.c \
		specifier_functions/spec_up_d.c \
		specifier_functions/spec_up_o.c \
		specifier_functions/spec_up_s.c \
		specifier_functions/spec_up_u.c \
		specifier_functions/spec_up_x.c \
		specifier_functions/spec_x.c \
		specifier_functions/spec_invalid.c \
		\
		libft_functions/pf_strsub.c \
		libft_functions/pf_itoa.c \
		libft_functions/pf_atoi.c \
		libft_functions/pf_strlen.c \
		libft_functions/pf_isascii.c \
		libft_functions/pf_isalnum.c \
		libft_functions/pf_isdigit.c \
		libft_functions/pf_lltoa.c \
		libft_functions/pf_strdup.c \
		libft_functions/pf_strjoin.c \
		libft_functions/pf_utoa.c \
		libft_functions/pf_itoa_base.c \
		libft_functions/pf_bzero.c \
		libft_functions/pf_memalloc.c \
		libft_functions/pf_memdel.c \


OBJS = ft_printf.o \
		moveto.o	\
		get_formats.o \
		checkfor.o	\
		get_args.o \
		do_precision.o \
		do_minwidth.o \
		do_signs.o \
		ft_uni_to_utf8.o \
		\
		dispatcher.o \
		spec_c.o \
		spec_d.o \
		spec_i.o \
		spec_o.o \
		spec_p.o \
		spec_pc.o \
		spec_s.o \
		spec_u.o \
		spec_up_c.o \
		spec_up_d.o \
		spec_up_o.o \
		spec_up_s.o \
		spec_up_u.o \
		spec_up_x.o \
		spec_x.o \
		spec_invalid.o \
		\
		pf_strsub.o \
		pf_itoa.o \
		pf_atoi.o \
		pf_strlen.o \
		pf_isascii.o \
		pf_isalnum.o \
		pf_isdigit.o \
		pf_lltoa.o \
		pf_strdup.o \
		pf_strjoin.o \
		pf_utoa.o \
		pf_itoa_base.o \
		pf_bzero.o \
		pf_memalloc.o \
		pf_memdel.o \

CC = gcc

CFLAGS = -Wall -Wextra -Werror -c

all: $(NAME)

$(NAME):
		$(CC) $(CFLAGS) $(SRCS)
		ar -rc $(NAME) $(OBJS)
		ranlib $(NAME)

.PHONY : clean

clean:
	/bin/rm -f $(OBJS)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
