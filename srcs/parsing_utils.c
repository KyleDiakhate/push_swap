/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltomas-d <ltomas-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/25 10:55:57 by ltomas-d          #+#    #+#             */
/*   Updated: 2026/06/25 15:44:48 by ltomas-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void print_erro()
{
	write(2, "Error\n", 6);
	exit(1);
}

long	verify_num(const char *nptr, long num)
{
	int i;

	i = 0;
	while (nptr[i])
	{
		if(nptr[i] < '0' || nptr[i] > '9')
		{
			print_erro();
		}
		num = num * 10 + (nptr[i] - '0');
		i++;
	}
	return (num);
}
long	convert_num(const char *nptr)
{
	int	i;
	long	neg;
	long	num;

	neg = 1;
	i = 0;
	num = 0;
	while ((nptr[i] >= '\t' && nptr[i] <= '\r') || (nptr[i] == ' '))
	{
		i++;
	}
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			neg *= -1;
		i++;
	}
	if(nptr[i] == '\0')
		print_erro();
	num = verify_num(&nptr[i], num);
	if ((neg == 1 && num > INT_MAX) || (neg == -1 && num > -(long)INT_MIN))
		print_erro();
	return (num * neg);
}

void	is_duplicate(t_stack *s, int value)
{
	t_node *current;

	current = s->head;
	if(current == NULL)
		return;
	if(current->data == value)
		print_erro();
	current = s->head->next;
	while (current != s->head)
	{
		if(current->data == value)
			print_erro();
		current = current->next;
	}
}
