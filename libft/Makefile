NAME = libft.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

SRCS = ft_split.c \
	   ft_strlen.c \
	   ft_strncmp.c \
	   ft_bzero.c \
	   ft_substr.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all
