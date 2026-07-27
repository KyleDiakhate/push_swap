NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

SRCS = srcs/main.c \
       srcs/utils.c \
       srcs/parsing.c \
       srcs/parsing_utils.c \
       operations/push.c \
       operations/rotate.c \
       operations/swap.c \
       operations/reverse_rotate.c \
       operations/list.c \
       ft_printf/ft_printf.c \
       ft_printf/ft_putchar.c \
       ft_printf/ft_puthex.c \
       ft_printf/ft_putnbr.c \
       ft_printf/ft_putptr.c \
       ft_printf/ft_putstr.c \
       ft_printf/ft_putun.c \
       algorithms/disorder.c \
       algorithms/medium.c \
       algorithms/sort.c \
       algorithms/complex.c \
       algorithms/simple.c \
       algorithms/adaptive.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(LIBFT):
	make -C $(LIBFT_DIR)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

clean:
	$(RM) $(OBJS)
	make -C $(LIBFT_DIR) clean

fclean: clean
	$(RM) $(NAME)
	make -C $(LIBFT_DIR) fclean

re: fclean all
