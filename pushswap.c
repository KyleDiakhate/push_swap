/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltomas-d <ltomas-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/25 15:19:35 by micampos          #+#    #+#             */
/*   Updated: 2026/06/18 19:00:28 by ltomas-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "push_swap.h"

t_list	*lstnew(int n)
{
	t_list *node;

	node = malloc(sizeof(t_list));
	node -> data = n;
	node -> next = NULL;
	return (node);
}

void	lstaddfront(t_list **lst, int n)
{
	t_list *temp;
	temp = lstnew(n);
	temp -> next = *lst;
	*lst = temp;
}

void	lstaddback(t_list **lst, int n)
{
	t_list *temp;
	
	temp = *lst;
	if (*lst == NULL)
	{
		*lst = lstnew(n);
		return ;
	}
	while ((temp) -> next != NULL)
		temp = (temp) -> next;
	(temp) -> next = lstnew(n);
}

t_list	*makelst(char **str)
{
	int		i;
	t_list	*lst;

	lst = NULL;
	i = 1;
	while (str[i] != NULL)
	{
		lstaddback(&lst, atoi(str[i]));
		i++;
	}
	return (lst);
}



float	disorder(t_list *top_a)
{
	float		total_pairs;
	float		mistakes;
	t_list	*next_node;

	total_pairs = 0;
	mistakes = 0;
	next_node = top_a -> next;
	while (next_node != NULL)
	{
		if (top_a -> data > next_node -> data)
			mistakes++;
		total_pairs++;
		top_a = next_node;
		next_node = next_node -> next;
	}
	// printf("mistakes: %d\n", (int)mistakes);
	// printf("total pairs: %d\n", (int)total_pairs);
	return (mistakes / total_pairs);
}
void	print_stacks(t_list *top_a, t_list *top_b)
{
	while (top_a != NULL)
	{
		ft_printf("%d\n", top_a -> data);
		top_a = top_a -> next;
	}
	ft_printf("\n\n");
	while (top_b != NULL)
	{
		ft_printf("%d\n", top_b -> data);
		top_b = top_b -> next;
	}
}

int	reverse_simple(t_list **top_a, t_list **top_b)
{
	t_list	*next_node;
	int	count;

	count = 0;
	next_node = (*top_b) -> next;
	while (next_node != NULL)
	{
		if ((*top_b) -> data > next_node -> data)
		{
			push_a(top_a, top_b);
			next_node = (*top_b) -> next;
			count++;
		}
		else
		{
			swap_b(*top_b);
			count++;
		}
	}
	return (count);
}

int	simple(t_list **top_a, t_list **top_b)
{
	t_list	*next_node;
	int	count;

	count = 0;
	next_node = (*top_a) -> next;
	while (next_node != NULL)
	{
		if ((*top_a) -> data < next_node -> data)
		{
			push_b(top_a, top_b);
			next_node = (*top_a) -> next;
			count++;
		}
		else
		{
			swap_a(*top_a);
			count++;
		}
	}
	return (count);
}

void	algo(t_list *top_a, t_list *top_b)
{
	int	count;

	count = 0;
	if (disorder(top_a) == 0)
	{
		ft_printf("Sorted!\n");
		return ;
	}
	while (disorder(top_a) != 0)
	{
		count = count + simple(&top_a, &top_b);
		count = count + reverse_simple(&top_a, &top_b);	
	}
	push_a(&top_a, &top_b);
	count++;
	print_stacks(top_a, top_b);
	ft_printf("count: %d\n", count);
}



