/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltomas-d <ltomas-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/25 10:56:07 by ltomas-d          #+#    #+#             */
/*   Updated: 2026/07/11 18:41:11 by ltomas-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	check_flags(char **argv, t_config *config)
{
	int	i;

	i = 1;
	config->strategy = 4;
	config->bench = 0;
	while (argv[i] && argv[i][0] == '-' && argv[i][1] == '-')
	{
		if (ft_strlen(argv[i]) == 7 && ft_strncmp(argv[i], "--bench", 7) == 0)
			config->bench = 1;
		else if (ft_strlen(argv[i]) == 8 && ft_strncmp(argv[i], "--simple", 8) == 0)
			config->strategy = 1;
		else if (ft_strlen(argv[i]) == 8 && ft_strncmp(argv[i], "--medium", 8) == 0)
			config->strategy = 2;
		else if (ft_strlen(argv[i]) == 9 && ft_strncmp(argv[i], "--complex", 9) == 0)
			config->strategy = 3;
		else if (ft_strlen(argv[i]) == 10 && ft_strncmp(argv[i], "--adaptive", 10) == 0)
			config->strategy = 4;
		else
			print_erro();
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
		is_duplicate(a, (int)num);
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
		print_erro();
	a->head = NULL;
	a->size = 0;
	i = start;
	while (argv[i])
		i++;
	i--;
	while (i >= start)
	{
		args = ft_split(argv[i], ' ');
		if (!args)
			print_erro();
		process_args(a, args);
		free_split(args);
		i--;
	}
	return (a);
}
