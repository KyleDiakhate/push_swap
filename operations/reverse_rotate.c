/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltomas-d <ltomas-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/21 17:56:37 by ltomas-d          #+#    #+#             */
/*   Updated: 2026/07/14 17:12:33 by ltomas-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	reverse_rotate(t_stack *s)
{
	if (s->size < 2)
		return ;
	s->head = s->head->prev;
}

void	reverse_rotate_a(t_stack *a, t_config *config)
{
	reverse_rotate(a);
	ft_dprintf(1, "rra\n");
	config->ops[8]++;
}

void	reverse_rotate_b(t_stack *b, t_config *config)
{
	reverse_rotate(b);
	ft_dprintf(1, "rrb\n");
	config->ops[9]++;
}

void	reverse_rotate_rrr(t_stack *a, t_stack *b, t_config *config)
{
	reverse_rotate(a);
	reverse_rotate(b);
	ft_dprintf(1, "rrr\n");
	config->ops[10]++;
}
