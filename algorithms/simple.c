/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltomas-d <ltomas-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/19 15:36:19 by ltomas-d          #+#    #+#             */
/*   Updated: 2026/06/19 15:38:31 by ltomas-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

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
