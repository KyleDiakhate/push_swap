/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltomas-d <ltomas-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/19 15:34:01 by ltomas-d          #+#    #+#             */
/*   Updated: 2026/07/09 16:30:16 by ltomas-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_node	*lstnew(int n, int i)
{
	t_node	*node;

	node = malloc(sizeof(t_node));
	if (!node)
		return (NULL);
	node->data = n;
	node->next = node;
	node->prev = node;
	node->index = i;
	return (node);
}

void	lstaddfront(t_node **lst, int n, int i)
{
	t_node	*temp;
	t_node	*last;

	temp = lstnew(n, i);
	if (!temp)
		return ;
	if (*lst == NULL)
	{
		*lst = temp;
		return ;
	}
	last = (*lst)->prev;
	temp->next = *lst;
	temp->prev = last;
	(*lst)->prev = temp;
	last->next = temp;
	*lst = temp;
}

void	free_stack(t_stack *s)
{
	t_node	*current;
	t_node	*next;
	int		i;

	if (!s)
		return ;
	if (s->head)
	{
		current = s->head;
		i = 0;
		while (i < s->size)
		{
			next = current->next;
			free(current);
			current = next;
			i++;
		}
	}
	free(s);
}
