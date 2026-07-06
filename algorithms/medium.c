/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyled <kyled@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/06 12:49:17 by kyled             #+#    #+#             */
/*   Updated: 2026/07/06 13:31:31 by kyled            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	normalize(t_stack *a)
{
	t_node *current;
	t_node *compare;
	int i;
	int j;
	int cont;

	i = 0;
	current = a->head;
	while (i < a->size)
	{
		cont = 0;
		j = 0;
		compare = a->head;
		while (j < a->size)
		{	
			if (compare->data < current->data)
				cont++;
			compare = compare->next;
			j++;
		}
		current->index = cont;
		current = current->next;
		i++;
	}
}
