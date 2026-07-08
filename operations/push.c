/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyled <kyled@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/18 18:38:36 by ltomas-d          #+#    #+#             */
/*   Updated: 2026/07/07 18:19:49 by kyled            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	do_push_one(t_stack *src, t_stack *dst, t_node *node)
{
	src->head = NULL;
	src->size--;
	lstaddfront(&dst->head, node->data);
	dst->head->index = node->index;
	dst->size++;
	free(node);
}

void	do_push(t_stack *src, t_stack *dst)
{
	t_node	*node;
	t_node	*new_head;
	t_node	*last;

	if (src->size == 0)
		return ;
	node = src->head;
	if (src->size == 1)
	{
		do_push_one(src, dst, node);
		return ;
	}
	new_head = node->next;
	last = node->prev;
	src->head = new_head;
	new_head->prev = last;
	last->next = new_head;
	src->size--;
	lstaddfront(&dst->head, node->data);
	dst->head->index = node->index;
	dst->size++;
	free(node);
}

void	push_a(t_stack *a, t_stack *b)
{
	do_push(b, a);
	ft_printf("pa\n");
}

void	push_b(t_stack *a, t_stack *b)
{
	do_push(a, b);
	ft_printf("pb\n");
}
