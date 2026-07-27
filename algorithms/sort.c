/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltomas-d <ltomas-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/11 19:43:54 by ltomas-d          #+#    #+#             */
/*   Updated: 2026/07/18 13:01:57 by ltomas-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sort_two(t_stack *a, t_config *config)
{
	if (a->head->index > a->head->next->index)
		swap_a(a, config);
}

void	sort_three(t_stack *a, t_config *config)
{
	int	top;
	int	mid;
	int	bot;

	top = a->head->index;
	mid = a->head->next->index;
	bot = a->head->prev->index;
	if (top > mid && top > bot)
	{
		rotate_a(a, config);
		if (a->head->index > a->head->next->index)
			swap_a(a, config);
	}
	else if (mid > top && mid > bot)
	{
		reverse_rotate_a(a, config);
		if (a->head->index > a->head->next->index)
			swap_a(a, config);
	}
	else if (top > mid)
		swap_a(a, config);
}

static void	push_min_to_b(t_stack *a, t_stack *b, t_config *config, int target)
{
	int		pos;
	int		i;
	t_node	*current;

	pos = 0;
	current = a->head;
	i = 0;
	while (i < a->size)
	{
		if (current->index == target)
			pos = i;
		current = current->next;
		i++;
	}
	if (pos <= a->size / 2)
		while (a->head->index != target)
			rotate_a(a, config);
	else
		while (a->head->index != target)
			reverse_rotate_a(a, config);
	push_b(a, b, config);
}

void	sort_five(t_stack *a, t_stack *b, t_config *config)
{
	if (a->size == 4)
	{
		push_min_to_b(a, b, config, 0);
		sort_three(a, config);
		push_a(a, b, config);
		return ;
	}
	push_min_to_b(a, b, config, 0);
	push_min_to_b(a, b, config, 1);
	sort_three(a, config);
	push_a(a, b, config);
	push_a(a, b, config);
}
