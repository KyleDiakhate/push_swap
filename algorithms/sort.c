/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltomas-d <ltomas-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/11 19:43:54 by ltomas-d          #+#    #+#             */
/*   Updated: 2026/07/11 19:44:14 by ltomas-d         ###   ########.fr       */
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