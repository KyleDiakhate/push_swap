/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyled <kyled@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/06 12:49:17 by kyled             #+#    #+#             */
/*   Updated: 2026/07/06 16:31:48 by kyled            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	normalize(t_stack *a)
{
	t_node *current;
	t_node *compare;
	int i;
	int j;
	int cont;

	i = 0;
	current = a->head;
	while (i < a->size)
	{
		cont = 0;
		j = 0;
		compare = a->head;
		while (j < a->size)
		{	
			if (compare->data < current->data)
				cont++;
			compare = compare->next;
			j++;
		}
		current->index = cont;
		current = current->next;
		i++;
	}
}

void	chunk_sort(t_stack *a, t_stack *b)
{
	int chunk_size;
	int i;
	int limit;
	
	chunk_size = 0;
	i = 1;
	while (i * i < a->size)
		i++;
	chunk_size = i;
	limit = chunk_size;
	i = 0;
	while (a != NULL)
	{
		if (a->head->index < limit)
			push_b(a, b);
		else
			rotate_a(a); 		
	}
}