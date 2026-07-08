/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltomas-d <ltomas-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/17 16:28:46 by ltomas-d          #+#    #+#             */
/*   Updated: 2026/07/07 15:27:20 by ltomas-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (s1 == NULL || s2 == NULL)
		return (0);
	if (n == 0)
		return (0);
	while ((s1[i] != '\0') && (s1[i] == s2[i]))
	{
		if (i < n - 1)
			i++;
		else
			return (0);
	}
	return ((unsigned char) s1[i] - (unsigned char) s2[i]);
}
