/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putun.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltomas-d <ltomas-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/25 17:02:14 by ltomas-d          #+#    #+#             */
/*   Updated: 2026/07/08 16:51:34 by ltomas-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../push_swap.h"
int	ft_putun(int fd, unsigned int n)
{
	int	cont;

	cont = 0;
	if (n < 10)
	{
		cont += ft_putchar(fd, n + '0');
	}
	else
	{
		cont += ft_putun(fd, n / 10);
		cont += ft_putun(fd, n % 10);
	}
	return (cont);
}
