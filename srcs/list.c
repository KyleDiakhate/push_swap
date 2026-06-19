/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltomas-d <ltomas-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/19 15:34:01 by ltomas-d          #+#    #+#             */
/*   Updated: 2026/06/19 15:35:05 by ltomas-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_list	*lstnew(int n)
{
	t_list *node;

	node = malloc(sizeof(t_list));
	node -> data = n;
	node -> next = NULL;
	return (node);
}

void	lstaddfront(t_list **lst, int n)
{
	t_list *temp;
	temp = lstnew(n);
	temp -> next = *lst;
	*lst = temp;
}

void	lstaddback(t_list **lst, int n)
{
	t_list *temp;
	
	temp = *lst;
	if (*lst == NULL)
	{
		*lst = lstnew(n);
		return ;
	}
	while ((temp) -> next != NULL)
		temp = (temp) -> next;
	(temp) -> next = lstnew(n);
}

t_list	*makelst(char **str)
{
	int		i;
	t_list	*lst;

	lst = NULL;
	i = 1;
	while (str[i] != NULL)
	{
		lstaddback(&lst, atoi(str[i]));
		i++;
	}
	return (lst);
}