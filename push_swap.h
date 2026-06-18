/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltomas-d <ltomas-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/18 17:26:20 by ltomas-d          #+#    #+#             */
/*   Updated: 2026/06/18 18:46:37 by ltomas-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP
#define PUSH_SWAP

#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h> 

typedef struct node
{
	int data;
	struct node *next;
} t_list;

int	ft_printf(const char *str, ...);
int	ft_putchar(char c);
int	ft_puthex(unsigned int n, char type);
int	ft_putnbr(int n);
int	ft_putptr(unsigned long n);
int	ft_putstr(char *s);
int	ft_putun(unsigned int n);

void	swap_a(t_list *top_a);
void	swap_b(t_list *top_b);
void	rotate_a(t_list **top_a);
void	rotate_b(t_list **top_b);
void	push_a(t_list **top_a, t_list **top_b);
void	push_b(t_list **top_a, t_list **top_b);

t_list	*lstnew(int n);
void	lstaddfront(t_list **lst, int n);
void	lstaddback(t_list **lst, int n);
t_list	*makelst(char **str);

float	disorder(t_list *top_a);
void	print_stacks(t_list *top_a, t_list *top_b);
int	reverse_simple(t_list **top_a, t_list **top_b);
int	simple(t_list **top_a, t_list **top_b);
void	algo(t_list *top_a, t_list *top_b);
#endif