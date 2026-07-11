/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltomas-d <ltomas-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/18 17:26:20 by ltomas-d          #+#    #+#             */
/*   Updated: 2026/07/09 16:31:05 by ltomas-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include "libft/libft.h"

typedef struct s_config
{
	int		strategy;
	int		bench;
	int		start;
	int		ops[11];
	float	dis;
}	t_config;

typedef struct s_node
{
	int				data;
	int				index;
	struct s_node	*next;
	struct s_node	*prev;
}	t_node;

typedef struct s_stack
{
	t_node	*head;
	int		size;
}	t_stack;

/* ft_printf */

int		ft_dprintf(int fd, const char *str, ...);
int		ft_putchar(int fd, char c);
int		ft_puthex(int fd, unsigned int n, char type);
int		ft_putnbr(int fd, int n);
int		ft_putptr(int fd, unsigned long n);
int		ft_putstr(int fd, char *s);
int		ft_putun(int fd, unsigned int n);

/* operations */
void	do_swap(t_stack *s);
void	swap_a(t_stack *a, t_config *config);
void	swap_b(t_stack *b, t_config *config);
void	swap_ss(t_stack *a, t_stack *b, t_config *config);
void	rotate(t_stack *s);
void	rotate_a(t_stack *a, t_config *config);
void	rotate_b(t_stack *b, t_config *config);
void	rotate_rr(t_stack *a, t_stack *b, t_config *config);
void	do_push(t_stack *src, t_stack *dst);
void	push_a(t_stack *a, t_stack *b, t_config *config);
void	push_b(t_stack *a, t_stack *b, t_config *config);
void	reverse_rotate(t_stack *s);
void	reverse_rotate_a(t_stack *a, t_config *config);
void	reverse_rotate_b(t_stack *b, t_config *config);
void	reverse_rotate_rrr(t_stack *a, t_stack *b, t_config *config);

/* list */
t_node	*lstnew(int n, int i);
void	lstaddfront(t_node **lst, int n, int i);
void	free_stack(t_stack *s);

/* parsing */
int		check_flags(char **argv, t_config *config);
t_stack	*parse_argv(char **argv, int start);
void	process_args(t_stack *a, char **args);
void	free_split(char **args);

/* parsing utils */
void	print_erro(void);
long	convert_num(const char *str);
long	verify_num(const char *str, long num);
void	is_duplicate(t_stack *s, int value);

/* algorithms */
float	disorder(t_stack *a);
void	normalize(t_stack *a);
void	chunk_sort(t_stack *a, t_stack *b, t_config *config);
void	sort_back(t_stack *a, t_stack *b, t_config *config);
int		find_max_pos(t_stack *b, int *max_index);

/* utils */
void	print_bench(t_config *config);

#endif
