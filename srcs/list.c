/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltomas-d <ltomas-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/19 15:34:01 by ltomas-d          #+#    #+#             */
/*   Updated: 2026/06/21 17:09:15 by ltomas-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_node	*lstnew(int n)
{
	t_node *node;

	node = malloc(sizeof(t_node));
	if(!node)
		return (NULL);
	node -> data = n;
	node -> next = node;
	node -> prev = node;
	node -> index = 0;
	return (node);
}

void	lstaddfront(t_node **lst, int n)
{
	t_node *temp;
	t_node *last;
	
	temp = lstnew(n);
	if (!temp)
    	return ;
	if(*lst == NULL)
	{
		*lst = temp;
		return;
	}
	last = (*lst) -> prev;
	temp -> next = *lst;
	temp -> prev = last;
    (*lst) -> prev = temp;
	last -> next = temp; 
	*lst = temp;
}

t_stack	*makelst(int argc, char **argv)
{
	t_stack *stack;
	int		i;

	stack = malloc(sizeof(t_stack));
	if (!stack)
    	return (NULL);
	stack -> head = NULL;
	stack -> size = 0;
	i = argc - 1;
	while (i >= 1)
	{
		lstaddfront(&stack->head, atoi(argv[i]));
		stack -> size++;
		i--;
	}
	return (stack);
}