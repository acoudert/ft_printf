NAME = libftprintf.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror
SRC =	ft_args.c \
		ft_cast.c \
		ft_char.c \
		ft_flags.c \
		ft_hex.c \
		ft_init.c \
		ft_len.c \
		ft_parser.c \
		ft_perc.c \
		ft_printf.c \
		ft_ptr.c \
		ft_put_chars.c \
		ft_put_nb.c \
		ft_s_nb.c \
		ft_str.c \
		ft_u_nb.c \
		ft_e_bonus.c \
		ft_f_bonus.c \
		ft_g_bonus.c \
		ft_n_bonus.c
OBJ = $(SRC:.c=.o)
BONUS = ft_e_bonus.c \
		ft_f_bonus.c \
		ft_g_bonus.c \
		ft_n_bonus.c
BONUS_OBJ = $(BONUS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

bonus : all $(BONUS_OBJ)
	ar rc $(NAME) $(BONUS_OBJ)
	ranlib $(NAME)

%.o : %.c
	$(CC) $(CFLAGS) -I. -c $^ -o $@

clean :
	rm -rf $(wildcard *.o)

fclean : clean
	rm -rf $(NAME)

re : fclean
	@$(MAKE) all --no-print-directory
