/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltomas-d <ltomas-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/19 15:36:19 by ltomas-d          #+#    #+#             */
/*   Updated: 2026/07/18 15:11:19 by ltomas-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	push_all_to_b(t_stack *a, t_stack *b, t_config *config)
{
	while (a->size > 1)
	{
		if (a->head->data < a->head->next->data)
			push_b(a, b, config);
		else
		{
			swap_a(a, config);
			push_b(a, b, config);
		}
	}
}

static void	push_all_to_a(t_stack *a, t_stack *b, t_config *config)
{
	while (b->size > 0)
	{
		if (b->size == 1)
		{
			push_a(a, b, config);
			break ;
		}
		if (b->head->data > b->head->next->data)
			push_a(a, b, config);
		else
		{
			swap_b(b, config);
			push_a(a, b, config);
		}
	}
}

t_stack	*simple(t_stack *a, t_stack *b, t_config *config)
{
	if (a->size == 2)
	{
		sort_two(a, config);
		return (b);
	}
	if (a->size <= 5)
	{
		if (a->size == 3)
			sort_three(a, config);
		else
			sort_five(a, b, config);
		return (b);
	}
	while (disorder(a) != 0)
	{
		push_all_to_b(a, b, config);
		push_all_to_a(a, b, config);
	}
	return (b);
}
