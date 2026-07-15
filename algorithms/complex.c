/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltomas-d <ltomas-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/13 17:02:30 by ltomas-d          #+#    #+#             */
/*   Updated: 2026/07/15 15:25:51 by ltomas-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	radix_round(t_stack *a, t_stack *b, t_config *config, int bit)
{
	int	i;
	int	t;

	i = 0;
	t = a->size;
	while (i < t)
	{
		if ((a->head->index >> bit) & 1)
			rotate_a(a, config);
		else
			push_b(a, b, config);
		i++;
	}
	while (b->size > 0)
		push_a(a, b, config);
}

int	complex(t_stack *a, t_stack *b, t_config *config)
{
	int	n;
	int	order;

	if (a->size <= 5)
	{
		if (a->size == 2)
			sort_two(a, config);
		else if (a->size == 3)
			sort_three(a, config);
		else 
			sort_five(a, b, config);
		return (0);
	}
	order = 0;
	n = a->size - 1;
	while (n >> order)
		order++;
	n = 0;
	while (n < order)
	{
		radix_round(a, b, config, n);
		n++;
	}
	return (0);
}
