/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltomas-d <ltomas-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/06 12:49:17 by kyled             #+#    #+#             */
/*   Updated: 2026/07/14 17:04:38 by ltomas-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	normalize(t_stack *a)
{
	t_node	*current;
	t_node	*compare;
	int		i;
	int		j;
	int		cont;

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
	int		pos;
	int		i;
	t_node	*node_b;

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

void	sort_back(t_stack *a, t_stack *b, t_config *config)
{
	int	pos;
	int	max_index;

	while (b->size > 0)
	{
		pos = find_max_pos(b, &max_index);
		if (pos <= b->size / 2)
			while (b->head->index != max_index)
				rotate_b(b, config);
		else
			while (b->head->index != max_index)
				reverse_rotate_b(b, config);
		push_a(a, b, config);
	}
}

static int	sort_small(t_stack *a, t_stack *b, t_config *config)
{
	if (a->size == 2)
	{
		sort_two(a, config);
		return (1);
	}
	if (a->size == 3)
	{
		sort_three(a, config);
		return (1);
	}
	if (a->size <= 5)
	{
		sort_five(a, b, config);
		return (1);
	}
	return (0);
}

void	chunk_sort(t_stack *a, t_stack *b, t_config *config)
{
	int	chunk_size;
	int	i;
	int	limit;

	if (sort_small(a, b, config))
		return ;
	i = 1;
	while (i * i < a->size)
		i++;
	chunk_size = i;
	limit = chunk_size;
	while (a->size > 0)
	{
		if (a->head->index < limit)
			push_b(a, b, config);
		else
			rotate_a(a, config);
		if (b->size >= limit)
			limit += chunk_size;
	}
}
