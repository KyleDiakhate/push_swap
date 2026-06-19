NAME = push_swap
CC = cc  
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

SRCS_DIR = srcs
OPERATIONS_DIR = operations
PRINTF_DIR = ft_printf
ALGO_DIR = algorithms


SRCS_FILES = $(SRCS_DIR)/main.c \
		     $(SRCS_DIR)/list.c \
			 $(SRCS_DIR)/utils.c		

OPERATIONS_FILES = $(OPERATIONS_DIR)/push.c \
				   $(OPERATIONS_DIR)/rotate.c \
				   $(OPERATIONS_DIR)/swap.c 

PRINTF_FILES =  $(PRINTF_DIR)/ft_printf.c \
				$(PRINTF_DIR)/ft_putchar.c \
				$(PRINTF_DIR)/ft_puthex.c \
				$(PRINTF_DIR)/ft_putnbr.c \
				$(PRINTF_DIR)/ft_putptr.c \
				$(PRINTF_DIR)/ft_putstr.c \
				$(PRINTF_DIR)/ft_putun.c 
ALGO_FILE = $(ALGO_DIR)/disorder.c \
			$(ALGO_DIR)/simple.c 

SRCS = $(SRCS_FILES) $(OPERATIONS_FILES) $(PRINTF_FILES) $(ALGO_FILE)

OBJS = $(SRCS:.c=.o)

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all