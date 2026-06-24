/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltomas-d <ltomas-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/18 18:36:54 by ltomas-d          #+#    #+#             */
/*   Updated: 2026/06/24 15:28:14 by ltomas-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void rotate(t_stack *s)
{
	if(s->size < 2)
		return;
	s->head = s->head->next;
}
void	rotate_a(t_stack *a)
{
	rotate(a);
	ft_printf("ra\n");
}

void	rotate_b(t_stack *b)
{
	rotate(b);
	ft_printf("rb\n");
}

void	rotate_rr(t_stack *a, t_stack *b)
{
	rotate(a);
	rotate(b);
	ft_printf("rr\n");
}