/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltomas-d <ltomas-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/19 15:39:17 by ltomas-d          #+#    #+#             */
/*   Updated: 2026/06/19 15:39:51 by ltomas-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	print_stacks(t_list *top_a, t_list *top_b)
{
	while (top_a != NULL)
	{
		ft_printf("%d\n", top_a -> data);
		top_a = top_a -> next;
	}
	ft_printf("\n\n");
	while (top_b != NULL)
	{
		ft_printf("%d\n", top_b -> data);
		top_b = top_b -> next;
	}
}
