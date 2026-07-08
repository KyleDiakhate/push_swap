/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyled <kyled@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/17 13:29:45 by ltomas-d          #+#    #+#             */
/*   Updated: 2026/07/07 18:20:56 by kyled            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	main(int argc, char **argv)
{
	t_config	config;
	t_stack		*a;
	t_stack		*b;

	if (argc == 1)
	return (0);
	check_flags(argv, &config);
	a = parse_argv(argv, config.start);
	if (a->size <= 1)
	{
		free_stack(a);
		return (0);
	}
	b = malloc(sizeof(t_stack));
	if (!b)
		print_erro();
	b->head = NULL;
	b->size = 0;
	normalize(a);
	chunk_sort(a, b);
	sort_back(a, b);
	free_stack(a);
	free_stack(b);
	return (0);
}
