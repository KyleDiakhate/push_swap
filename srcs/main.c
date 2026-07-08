/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltomas-d <ltomas-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/17 13:29:45 by ltomas-d          #+#    #+#             */
/*   Updated: 2026/07/08 17:05:26 by ltomas-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	init_config(t_config *config)
{
	int	i;

	i = 0;
	while (i < 11)
	{
		config->ops[i] = 0;
		i++;
	}
}

static t_stack	*init_stack_b(void)
{
	t_stack	*b;

	b = malloc(sizeof(t_stack));
	if (!b)
		print_erro();
	b->head = NULL;
	b->size = 0;
	return (b);
}

static void	run_algo(t_stack *a, t_stack *b, t_config *config)
{
	normalize(a);
	config->dis = disorder(a);
	if (config->strategy == 1)
	{
		chunk_sort(a, b, config);
		sort_back(a, b, config);
	}
	else if (config->strategy == 2)
	{
		chunk_sort(a, b, config);
		sort_back(a, b, config);
	}
	else if (config->strategy == 3)
	{
		chunk_sort(a, b, config);
		sort_back(a, b, config);
	}
	else
	{
		chunk_sort(a, b, config);
		sort_back(a, b, config);
	}
}

int	main(int argc, char **argv)
{
	t_config	config;
	t_stack		*a;
	t_stack		*b;

	if (argc == 1)
		return (0);
	check_flags(argv, &config);
	init_config(&config);
	a = parse_argv(argv, config.start);
	if (a->size <= 1)
	{
		free_stack(a);
		return (0);
	}
	b = init_stack_b();
	run_algo(a, b, &config);
	if (config.bench)
		print_bench(&config);
	free_stack(a);
	free_stack(b);
	return (0);
}
