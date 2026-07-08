/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltomas-d <ltomas-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/25 16:47:19 by ltomas-d          #+#    #+#             */
/*   Updated: 2026/07/08 16:50:35 by ltomas-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../push_swap.h"
int	ft_putnbr(int fd, int n)
{
	int	cont;

	cont = 0;
	if (n == -2147483648)
	{
		write (1, "-2147483648", 11);
		return (11);
	}
	if (n < 0)
	{
		n = -n;
		cont += ft_putchar(fd, '-');
	}
	if (n < 10)
	{
		cont += ft_putchar(fd, n + '0');
	}
	else
	{
		cont += ft_putnbr(fd, n / 10);
		cont += ft_putnbr(fd, n % 10);
	}
	return (cont);
}
