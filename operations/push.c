/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltomas-d <ltomas-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/18 18:38:36 by ltomas-d          #+#    #+#             */
/*   Updated: 2026/07/16 13:16:18 by ltomas-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	do_push_one(t_stack *src, t_stack *dst)
{
	t_node	*node;
	int		idx;

	node = src->head;
	idx = node->index;
	src->head = NULL;
	src->size--;
	lstaddfront(&dst->head, node->data, idx);
	dst->size++;
	free(node);
}

void	do_push(t_stack *src, t_stack *dst)
{
	t_node	*node;
	t_node	*new_head;
	t_node	*last;
	int		idx;

	if (src->size == 0)
		return ;
	node = src->head;
	if (src->size == 1)
	{
		do_push_one(src, dst);
		return ;
	}
	node = src->head;
	idx = node->index;
	new_head = node->next;
	last = node->prev;
	src->head = new_head;
	new_head->prev = last;
	last->next = new_head;
	src->size--;
	lstaddfront(&dst->head, node->data, idx);
	dst->size++;
	free(node);
}

void	push_a(t_stack *a, t_stack *b, t_config *config)
{
	do_push(b, a);
	ft_dprintf(1, "pa\n");
	config->ops[3]++;
}

void	push_b(t_stack *a, t_stack *b, t_config *config)
{
	do_push(a, b);
	ft_dprintf(1, "pb\n");
	config->ops[4]++;
}
