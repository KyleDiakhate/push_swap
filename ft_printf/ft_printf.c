/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltomas-d <ltomas-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/25 16:07:13 by ltomas-d          #+#    #+#             */
/*   Updated: 2026/07/08 16:51:43 by ltomas-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

#include "../push_swap.h"

static int	ft_check_arg(int fd, va_list arg, const char format)
{
	if (format == 'c')
		return (ft_putchar(fd, va_arg(arg, int)));
	else if (format == 's')
		return (ft_putstr(fd, va_arg(arg, char *)));
	else if (format == 'p')
		return (ft_putptr(fd, (unsigned long)va_arg(arg, void *)));
	else if (format == 'd' || format == 'i')
		return (ft_putnbr(fd, va_arg(arg, int)));
	else if (format == 'u')
		return (ft_putun(fd, va_arg(arg, unsigned int)));
	else if (format == 'x' || format == 'X')
		return (ft_puthex(fd, va_arg(arg, unsigned int), format));
	else if (format == '%')
		return (ft_putchar(fd, '%'));
	return (0);
}

int	ft_dprintf(int fd, const char *str, ...)
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
			cont += ft_check_arg(fd, arg, str[i + 1]);
			i++;
		}
		else
			cont += ft_putchar(fd, str[i]);
		i++;
	}
	va_end(arg);
	return (cont);
}
