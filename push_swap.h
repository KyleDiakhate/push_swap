/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltomas-d <ltomas-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/18 17:26:20 by ltomas-d          #+#    #+#             */
/*   Updated: 2026/06/21 18:31:47 by ltomas-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP
#define PUSH_SWAP

#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h> 
/* Estrutura dos alterados inves de usar single linked list mudei para circular.*/
typedef struct s_node
{
	int	data;
	int	index; /* usado para normalizar valores nos algoritmos */
	struct s_node *next;
	struct s_node *prev;
} t_node;

/*Estrura das stacks. */ 
typedef struct s_stack
{
	t_node *head; /* <- Aponta para o inicio da stack*/
	int	size; // <- tamanho das stacks.
} t_stack;

int	ft_printf(const char *str, ...);
int	ft_putchar(char c);
int	ft_puthex(unsigned int n, char type);
int	ft_putnbr(int n);
int	ft_putptr(unsigned long n);
int	ft_putstr(char *s);
int	ft_putun(unsigned int n);

void	swap_a(t_stack* a);
void	swap_b(t_stack *b);
void    do_swap(t_stack *s);
void    swap_ss(t_stack *a, t_stack *b);

void	rotate_a(t_stack *a);
void	rotate_b(t_stack *b);
void	rotate(t_stack *s);
void	rotate_rr(t_stack *a, t_stack *b);
void	do_push(t_stack *src, t_stack *dst);
void	push_a(t_stack *a, t_stack *b);
void	push_b(t_stack *a, t_stack *b);
void	reverse_rotate(t_stack *s);
void    reverse_rotate_a(t_stack *a);
void    reverse_rotate_b(t_stack *b);
void	reverse_rotate_rrr(t_stack *a, t_stack *b);

t_node	*lstnew(int n);
void	lstaddfront(t_node **lst, int n);
t_stack	*makelst(int argc, char **argv);

float	disorder(t_stack *a);
void	print_stacks(t_stack *a, t_stack *b);
int	reverse_simple(t_stack *a, t_stack *top_b);
int	simple(t_stack *top_a, t_stack *top_b);
void	algo(t_stack *top_a, t_stack *top_b);
#endif