/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltomas-d <ltomas-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/06 12:49:17 by kyled             #+#    #+#             */
/*   Updated: 2026/07/07 13:26:55 by ltomas-d         ###   ########.fr       */
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
int	find_max_pos(t_stack *b, int *max_index)
{
	int pos;
	int i;
	t_node *node_b;

	*max_index = b->head->index;
	pos = 0;
	node_b = b->head;
	i = 0;
	while (b->size > i)
	{
		if (node_b->index > *max_index)
		{
			*max_index = node_b->index;
			pos = i;
		}
		node_b = node_b->next;
		i++;
	}
	return (pos);

}
void	sort_back(t_stack *a, t_stack *b)
{
	int	pos;
	int	max_index;

	while (b->size > 0)
	{
		pos = find_max_pos(b, &max_index);
		if (pos <= b->size / 2)
			while (b->head->index != max_index)
				rotate_b(b);
		else
			while (b->head->index != max_index)
				reverse_rotate_b(b);
		push_a(a, b);
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
	while (a->size > 0)
	{
		if (a->head->index < limit)
			push_b(a, b);
		else
			rotate_a(a);
		if(b->size >=  limit)
			limit += chunk_size;
	}
}

