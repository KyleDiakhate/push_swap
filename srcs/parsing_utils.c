/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyled <kyled@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/25 10:55:57 by ltomas-d          #+#    #+#             */
/*   Updated: 2026/07/05 17:01:14 by kyled            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void print_erro()
{
	write(2, "Error\n", 6);
	exit(1);
}

long	verify_num(const char *str, long num)
{
	int i;

	i = 0;
	while (str[i])
	{
		if(str[i] < '0' || str[i] > '9')
		{
			print_erro();
		}
		num = num * 10 + (str[i] - '0');
		i++;
	}
	return (num);
}
long	convert_num(const char *str)
{
	int	i;
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
	if(str[i] == '\0')
		print_erro();
	num = verify_num(&str[i], num);
	if ((neg == 1 && num  > INT_MAX) || (neg == -1 && num > -(long)INT_MIN))
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
