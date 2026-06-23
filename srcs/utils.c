/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltomas-d <ltomas-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/19 15:39:17 by ltomas-d          #+#    #+#             */
/*   Updated: 2026/06/23 14:28:28 by ltomas-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"


void	print_one_stack(t_stack *s)
{
	t_node *current;
	if (s->head == NULL)
        return ;
	current = s->head;
	ft_printf("%d\n", current->data);
	current = current->next;
	while(current != s->head)
	{
		ft_printf("%d\n", current->data);
		current = current->next;
	}
	
}
void	print_stacks(t_stack *a, t_stack *b)
{
	print_one_stack(a);
	ft_printf("\n\n");
	print_one_stack(b);
}
