/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltomas-d <ltomas-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/18 18:40:10 by ltomas-d          #+#    #+#             */
/*   Updated: 2026/06/18 19:09:13 by ltomas-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
void	swap_a(t_list *top_a)
{
	t_list	*next_node;
	int		t;

	if (top_a -> next != NULL)
	{
		next_node = top_a -> next;
		t = next_node -> data;
		next_node -> data = top_a -> data;
		top_a -> data = t;
	}
	ft_printf("sa\n");
}

void	swap_b(t_list *top_b)
{
	t_list	*next_node;
	int		t;

	if (top_b -> next != NULL)
	{
		next_node = top_b -> next;
		t = next_node -> data;
		next_node -> data = top_b -> data;
		top_b -> data = t;
	}
	ft_printf("sb\n");
}