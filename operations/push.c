/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltomas-d <ltomas-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/18 18:38:36 by ltomas-d          #+#    #+#             */
/*   Updated: 2026/06/18 19:08:42 by ltomas-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	push_a(t_list **top_a, t_list **top_b)
{
	t_list	*temp;

	lstaddfront(top_a, (*top_b) -> data);
	temp = *top_b;
	*top_b = (*top_b) -> next;
	free(temp);
	ft_printf("pa\n");
}

void	push_b(t_list **top_a, t_list **top_b)
{
	t_list	*temp;

	lstaddfront(top_b, (*top_a) -> data);
	temp = *top_a;
	*top_a = (*top_a) -> next;
	free(temp);
	ft_printf("pb\n");
}