/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltomas-d <ltomas-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/18 18:36:54 by ltomas-d          #+#    #+#             */
/*   Updated: 2026/07/08 16:54:45 by ltomas-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void rotate(t_stack *s)
{
	if(s->size < 2)
		return;
	s->head = s->head->next;
}
void	rotate_a(t_stack *a, t_config *config)
{
	rotate(a);
	ft_dprintf(1, "ra\n");
	config->ops[5]++;
}

void	rotate_b(t_stack *b, t_config *config)
{
	rotate(b);
	ft_dprintf(1, "rb\n");
	config->ops[6]++;
}

void	rotate_rr(t_stack *a, t_stack *b, t_config *config)
{
	rotate(a);
	rotate(b);
	ft_dprintf(1, "rr\n");
	config->ops[7]++;
}