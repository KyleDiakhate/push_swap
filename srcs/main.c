/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltomas-d <ltomas-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/17 13:29:45 by ltomas-d          #+#    #+#             */
/*   Updated: 2026/06/18 19:08:22 by ltomas-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	main(int argc, char **argv)
{
	t_list	*top_a;
	t_list	*top_b;
	float	ratio;

	top_b = NULL;
	if (argc < 2)
		return (ft_printf("You failed!"), 0);
	top_a = makelst(argv);
	ratio = disorder(top_a);
	ft_printf("ratio: %f\n\n", ratio);
	algo(top_a, top_b);
	algo(top_a, top_b);
	ft_printf("ratio: %f\n\n", ratio);
	return (0);
}