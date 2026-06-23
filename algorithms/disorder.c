/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disorder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltomas-d <ltomas-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/19 15:37:30 by ltomas-d          #+#    #+#             */
/*   Updated: 2026/06/23 17:03:52 by ltomas-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

float	disorder(t_stack *a)
{
	float		total_pairs;
	float		mistakes;
	t_node	*current;
	t_node  *next_node;

	total_pairs = 0;
	mistakes = 0;
	if(a->head == NULL || a->size < 2)
		return (0);
	current = a->head;
	while (current != a->head->prev) 
	{
		next_node = current->next;
		while (next_node != a->head) 
		{
			if(current->data > next_node->data)
				mistakes++;
			total_pairs++;
			next_node = next_node->next;
		}
		current = current->next;
	}
	return (mistakes / total_pairs);
}
