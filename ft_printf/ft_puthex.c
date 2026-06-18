/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltomas-d <ltomas-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/26 14:49:15 by ltomas-d          #+#    #+#             */
/*   Updated: 2026/06/18 18:30:50 by ltomas-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
int	ft_puthex(unsigned int n, char type)
{
	int		cont;
	char	*base;

	if (type == 'x')
		base = "0123456789abcdef";
	else
		base = "0123456789ABCDEF";
	cont = 0;
	if (n < 16)
	{
		cont += ft_putchar(base[n]);
	}
	else
	{
		cont += ft_puthex(n / 16, type);
		cont += ft_puthex(n % 16, type);
	}
	return (cont);
}
