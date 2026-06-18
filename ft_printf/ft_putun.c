/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putun.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltomas-d <ltomas-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/25 17:02:14 by ltomas-d          #+#    #+#             */
/*   Updated: 2026/06/18 18:31:10 by ltomas-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../push_swap.h"
int	ft_putun(unsigned int n)
{
	int	cont;

	cont = 0;
	if (n < 10)
	{
		cont += ft_putchar(n + '0');
	}
	else
	{
		cont += ft_putun(n / 10);
		cont += ft_putun(n % 10);
	}
	return (cont);
}
