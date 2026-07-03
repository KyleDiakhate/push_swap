/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltomas-d <ltomas-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/25 10:56:07 by ltomas-d          #+#    #+#             */
/*   Updated: 2026/07/03 18:19:16 by ltomas-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	check_flags(char **argv, t_config *config)
{
	int i;
	
	i = 1;
	config->strategy = 4;
	config->bench = 0;
	while (argv[i] && argv[i][0] == '-' && argv[i][1] == '-')
	{
		if (ft_strlen(argv[i]) == 7 && ft_strncmp(argv[i], "--bench", 7) == 0)
			config->bench = 1; 
		else if (ft_strlen(argv[i]) == 8 && ft_strncmp(argv[i], "--simple", 8) == 0)
			config->strategy = 1;
		else if (ft_strlen(argv[i]) == 8 && ft_strncmp(argv[i], "--medium", 8) == 0)
			config->strategy = 2;
		else if (ft_strlen(argv[i]) == 9 && ft_strncmp(argv[i], "--complex", 9) == 0)
			config->strategy = 3;
		else if (ft_strlen(argv[i]) == 10 && ft_strncmp(argv[i], "--adaptive", 10) == 0)
			config->strategy = 4;
		else
			print_erro();
		i++;
	}
	config->start = i;
	return (i);
}