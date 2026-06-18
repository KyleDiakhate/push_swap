/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltomas-d <ltomas-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/18 18:36:54 by ltomas-d          #+#    #+#             */
/*   Updated: 2026/06/18 19:08:50 by ltomas-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rotate_a(t_list **top_a)
{
	t_list	*temp;
	int		t;

	if ((*top_a) -> next != NULL)
	{
		t = (*top_a) -> data;
		temp = *top_a;
		*top_a = (*top_a) -> next;
		free(temp);
		lstaddback(top_a, t);
	}
	ft_printf("ra\n");
}

void	rotate_b(t_list **top_b)
{
	t_list	*temp;
	int		t;
	
	
	if ((*top_b) -> next != NULL)
	{
		t = (*top_b) -> data;
		temp = *top_b;
		*top_b = (*top_b) -> next;
		free(temp);
		lstaddback(top_b, t);
	}
	ft_printf("rb\n");
}