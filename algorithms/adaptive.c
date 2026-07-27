/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adaptive.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltomas-d <ltomas-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/13 17:58:12 by ltomas-d          #+#    #+#             */
/*   Updated: 2026/07/14 17:05:59 by ltomas-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	adaptive(t_stack *a, t_stack *b, t_config *config)
{
	if (config->dis < 0.2)
	{
		simple(a, b, config);
	}
	else if (config->dis < 0.5)
	{
		chunk_sort(a, b, config);
		sort_back(a, b, config);
	}
	else if (config->dis >= 0.5)
	{
		complex(a, b, config);
	}
}
