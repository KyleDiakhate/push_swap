/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltomas-d <ltomas-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/07 15:11:22 by ltomas-d          #+#    #+#             */
/*   Updated: 2026/06/23 17:38:09 by ltomas-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static size_t	ft_count_words(char const *s, char c)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if ((s[i] != c) && (i == 0 || s[i - 1] == c))
		{
			count++;
		}
		i++;
	}
	return (count);
}

static void	ft_free_array(char **array)
{
	char	**tmp;

	tmp = array;
	while (*array != NULL)
	{
		free(*array);
		array++;
	}
	free(tmp);
}

static	char	**ft_fill_array(char **array, char const *s, char c)
{
	size_t	i;
	size_t	j;
	size_t	tmp;

	j = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] == '\0')
			break ;
		tmp = i;
		while (s[i] != c && s[i] != '\0')
			i++;
		array[j] = ft_substr(s, tmp, i - tmp);
		if (array[j] == NULL)
		{
			ft_free_array (array);
			return (NULL);
		}
		j++;
	}
	array[j] = NULL;
	return (array);
}

char	**ft_split(char const *s, char c)
{
	char	**array;
	char	**fill;
	size_t	count;

	if (s == NULL)
		return (NULL);
	count = ft_count_words(s, c);
	array = malloc((count + 1) * sizeof(char *));
	if (array == NULL)
		return (NULL);
	ft_bzero(array, (count + 1) * sizeof(char *));
	fill = ft_fill_array(array, s, c);
	if (fill == NULL)
	{
		return (NULL);
	}
	return (array);
}
