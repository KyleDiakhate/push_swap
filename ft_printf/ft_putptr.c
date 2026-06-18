/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltomas-d <ltomas-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/26 15:07:06 by ltomas-d          #+#    #+#             */
/*   Updated: 2026/06/18 18:31:03 by ltomas-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../push_swap.h"
static	int	ft_putptr_recursive(unsigned long n)
{
	int		cont;
	char	*base;

	base = "0123456789abcdef";
	cont = 0;
	if (n < 16)
	{
		cont += ft_putchar(base[n]);
	}
	else
	{
		cont += ft_putptr_recursive(n / 16);
		cont += ft_putptr_recursive(n % 16);
	}
	return (cont);
}

int	ft_putptr(unsigned long n)
{
	int	cont;

	cont = 0;
	if (n == 0)
		return (ft_putstr("(nil)"));
	cont += ft_putstr("0x");
	cont += ft_putptr_recursive(n);
	return (cont);
}
