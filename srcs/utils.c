/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltomas-d <ltomas-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/19 15:39:17 by ltomas-d          #+#    #+#             */
/*   Updated: 2026/07/08 17:06:34 by ltomas-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"


static int	total_ops(t_config *config)
{
	int	total;
	int	i;

	total = 0;
	i = 0;
	while (i < 11)
	{
		total = total + config->ops[i];
		i++;
	}
	return (total);
}

static void	print_dis(int fd, float dis)
{
	int	int_part;
	int	frac_part;

	int_part = (int)(dis * 100);
	frac_part = (int)(dis * 10000) - (int_part * 100);
	if (frac_part < 0)
		frac_part = -frac_part;
	ft_dprintf(fd, "%d.", int_part);
	if (frac_part < 10)
		ft_dprintf(fd, "0");
	ft_dprintf(fd, "%d%%\n", frac_part);
}

static void	print_ops(int fd, t_config *config)
{
	ft_dprintf(fd, "[bench] sa: %d  ", config->ops[0]);
	ft_dprintf(fd, "sb: %d  ", config->ops[1]);
	ft_dprintf(fd, "ss: %d  ", config->ops[2]);
	ft_dprintf(fd, "pa: %d  ", config->ops[3]);
	ft_dprintf(fd, "pb: %d\n", config->ops[4]);
	ft_dprintf(fd, "[bench] ra: %d  ", config->ops[5]);
	ft_dprintf(fd, "rb: %d  ", config->ops[6]);
	ft_dprintf(fd, "rr: %d  ", config->ops[7]);
	ft_dprintf(fd, "rra: %d  ", config->ops[8]);
	ft_dprintf(fd, "rrb: %d  ", config->ops[9]);
	ft_dprintf(fd, "rrr: %d\n", config->ops[10]);
}


void	print_bench(t_config *config)
{
	ft_dprintf(2, "[bench] disorder: ");
	print_dis(2, config->dis);
	ft_dprintf(2, "[bench] strategy: Medium / O(n√n)\n");
	ft_dprintf(2, "[bench] total_ops: %d\n", total_ops(config));
	print_ops(2, config);
}