/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltomas-d <ltomas-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/21 17:56:37 by ltomas-d          #+#    #+#             */
/*   Updated: 2026/06/21 18:01:20 by ltomas-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void reverse_rotate(t_stack *s)
{
	if(s->size < 2)
		return;
	s->head = s->head->prev;
}
void	reverse_rotate_a(t_stack *a)
{

	reverse_rotate(a);
	ft_printf("rra\n");
}

void	reverse_rotate_b(t_stack *b)
{
	reverse_rotate(b);
	ft_printf("rrb\n");
}

void	reverse_rotate_rrr(t_stack *a, t_stack *b)
{
	reverse_rotate(a);
	reverse_rotate(b);
	ft_printf("rrr\n");
}