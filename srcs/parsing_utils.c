/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltomas-d <ltomas-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/25 10:55:57 by ltomas-d          #+#    #+#             */
/*   Updated: 2026/07/15 17:22:52 by ltomas-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	print_error(t_stack *a, char **args)
{
	if (args)
		free_split(args);
	if (a)
		free_stack(a);
	ft_dprintf(2, "Error\n");
	exit(EXIT_FAILURE);
}

int	cmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}

long	verify_num(const char *str, long num)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (LONG_MAX);
		num = num * 10 + (str[i] - '0');
		i++;
	}
	return (num);
}

long	convert_num(const char *str)
{
	int		i;
	long	neg;
	long	num;

	neg = 1;
	i = 0;
	num = 0;
	while ((str[i] >= '\t' && str[i] <= '\r') || (str[i] == ' '))
	{
		i++;
	}
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			neg *= -1;
		i++;
	}
	if (str[i] == '\0')
		return (LONG_MAX);
	num = verify_num(&str[i], num);
	if (num == LONG_MAX)
		return (LONG_MAX);
	if ((neg == 1 && num > INT_MAX) || (neg == -1 && num > -(long)INT_MIN))
		return (LONG_MAX);
	return (num * neg);
}

int	is_duplicate(t_stack *s, int value)
{
	t_node	*current;

	current = s->head;
	if (!current)
		return (0);
	if (current->data == value)
		return (1);
	current = current->next;
	while (current != s->head)
	{
		if (current->data == value)
			return (1);
		current = current->next;
	}
	return (0);
}
