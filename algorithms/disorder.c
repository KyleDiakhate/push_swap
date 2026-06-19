/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disorder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltomas-d <ltomas-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/19 15:37:30 by ltomas-d          #+#    #+#             */
/*   Updated: 2026/06/19 15:37:43 by ltomas-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

float	disorder(t_list *top_a)
{
	float		total_pairs;
	float		mistakes;
	t_list	*next_node;

	total_pairs = 0;
	mistakes = 0;
	next_node = top_a -> next;
	while (next_node != NULL)
	{
		if (top_a -> data > next_node -> data)
			mistakes++;
		total_pairs++;
		top_a = next_node;
		next_node = next_node -> next;
	}
	// printf("mistakes: %d\n", (int)mistakes);
	// printf("total pairs: %d\n", (int)total_pairs);
	return (mistakes / total_pairs);
}
