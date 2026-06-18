/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltomas-d <ltomas-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/25 16:07:13 by ltomas-d          #+#    #+#             */
/*   Updated: 2026/06/18 18:30:47 by ltomas-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	ft_check_arg(va_list arg, const char format)
{
	if (format == 'c')
		return (ft_putchar(va_arg(arg, int)));
	else if (format == 's')
		return (ft_putstr(va_arg(arg, char *)));
	else if (format == 'p')
		return (ft_putptr((unsigned long)va_arg(arg, void *)));
	else if (format == 'd' || format == 'i')
		return (ft_putnbr(va_arg(arg, int)));
	else if (format == 'u')
		return (ft_putun(va_arg(arg, unsigned int)));
	else if (format == 'x' || format == 'X')
		return (ft_puthex(va_arg(arg, unsigned int), format));
	else if (format == '%')
		return (ft_putchar('%'));
	return (0);
}

int	ft_printf(const char *str, ...)
{
	va_list	arg;
	int		cont;
	int		i;

	i = 0;
	if (str == NULL)
		return (-1);
	va_start(arg, str);
	cont = 0;
	while (str[i])
	{
		if (str[i] == '%' && str[i + 1])
		{
			cont += ft_check_arg (arg, str[i + 1]);
			i++;
		}
		else
			cont += ft_putchar(str[i]);
		i++;
	}
	va_end(arg);
	return (cont);
}
