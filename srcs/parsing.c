/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltomas-d <ltomas-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/25 10:56:07 by ltomas-d          #+#    #+#             */
/*   Updated: 2026/07/15 17:52:21 by ltomas-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	set_strategy(char *arg, t_config *config, int *set)
{
	if (*set)
		print_error(NULL, NULL);
	if (cmp(arg, "--simple") == 0)
		config->strategy = 1;
	else if (cmp(arg, "--medium") == 0)
		config->strategy = 2;
	else if (cmp(arg, "--complex") == 0)
		config->strategy = 3;
	else if (cmp(arg, "--adaptive") == 0)
		config->strategy = 4;
	else
		return (0);
	*set = 1;
	return (1);
}

int	check_flags(char **argv, t_config *config)
{
	int	i;
	int	strat_set;

	i = 1;
	strat_set = 0;
	config->strategy = 4;
	config->bench = 0;
	while (argv[i] && argv[i][0] == '-' && argv[i][1] == '-')
	{
		if (cmp(argv[i], "--bench") == 0)
			config->bench = 1;
		else if (set_strategy(argv[i], config, &strat_set))
			(void)0;
		else
			print_error(NULL, NULL);
		i++;
	}
	config->start = i;
	return (i);
}

void	free_split(char **args)
{
	int	i;

	i = 0;
	while (args[i])
	{
		free(args[i]);
		i++;
	}
	free(args);
}

void	process_args(t_stack *a, char **args)
{
	int		i;
	long	num;

	i = 0;
	while (args[i])
		i++;
	i--;
	while (i >= 0)
	{
		num = convert_num(args[i]);
		if (num == LONG_MAX)
			print_error(a, args);
		if (is_duplicate(a, (int)num))
			print_error(a, args);
		lstaddfront(&a->head, (int)num, 0);
		a->size++;
		i--;
	}
}

t_stack	*parse_argv(char **argv, int start)
{
	t_stack	*a;
	char	**args;
	int		i;

	a = malloc(sizeof(t_stack));
	if (!a)
		print_error(NULL, NULL);
	a->head = NULL;
	a->size = 0;
	i = start;
	while (argv[i])
		i++;
	i--;
	while (i >= start)
	{
		if (argv[i][0] == '\0')
			print_error(a, NULL);
		args = ft_split(argv[i], ' ');
		if (!args)
			print_error(a, NULL);
		process_args(a, args);
		free_split(args);
		i--;
	}
	return (a);
}
