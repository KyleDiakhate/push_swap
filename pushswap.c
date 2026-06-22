/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micampos <micampos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/25 15:19:35 by micampos          #+#    #+#             */
/*   Updated: 2026/06/22 15:57:37 by micampos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int data;
	struct node *next;
} t_list;

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

void	push_a(t_list **top_a, t_list **top_b)
{
	t_list	*temp;

	lstaddfront(top_a, (*top_b) -> data);
	temp = *top_b;
	*top_b = (*top_b) -> next;
	free(temp);
	printf("pa\n");
}

void	push_b(t_list **top_a, t_list **top_b)
{
	t_list	*temp;

	lstaddfront(top_b, (*top_a) -> data);
	temp = *top_a;
	*top_a = (*top_a) -> next;
	free(temp);
	printf("pb\n");
}

void	swap_a(t_list *top_a)
{
	t_list	*next_node;
	int		t;

	if (top_a -> next != NULL)
	{
		next_node = top_a -> next;
		t = next_node -> data;
		next_node -> data = top_a -> data;
		top_a -> data = t;
	}
	printf("sa\n");
}

void	swap_b(t_list *top_b)
{
	t_list	*next_node;
	int		t;

	if (top_b -> next != NULL)
	{
		next_node = top_b -> next;
		t = next_node -> data;
		next_node -> data = top_b -> data;
		top_b -> data = t;
	}
	printf("sb\n");
}

void	rotate_a(t_list **top_a)
{
	t_list	*temp;
	int		t;

	if ((*top_a) -> next != NULL)
	{
		t = (*top_a) -> data;
		temp = *top_a;
		*top_a = (*top_a) -> next;
		free(temp);
		lstaddback(top_a, t);
	}
	printf("ra\n");
}

void	rotate_b(t_list **top_b)
{
	t_list	*temp;
	int		t;
	
	
	if ((*top_b) -> next != NULL)
	{
		t = (*top_b) -> data;
		temp = *top_b;
		*top_b = (*top_b) -> next;
		free(temp);
		lstaddback(top_b, t);
	}
	printf("rb\n");
}

float	disorder(t_list *top_a)
{
	float		total_pairs;
	float		mistakes;
	t_list	*next_node;

	total_pairs = 0;
	mistakes = 0;
	next_node = top_a -> next;
	while (next_node != NULL)
	{
		if (top_a -> data > next_node -> data)
			mistakes++;
		total_pairs++;
		top_a = next_node;
		next_node = next_node -> next;
	}
	// printf("mistakes: %d\n", (int)mistakes);
	// printf("total pairs: %d\n", (int)total_pairs);
	return (mistakes / total_pairs);
}
void	print_stacks(t_list *top_a, t_list *top_b)
{
	while (top_a != NULL)
	{
		printf("%d\n", top_a -> data);
		top_a = top_a -> next;
	}
	printf("\n\n");
	while (top_b != NULL)
	{
		printf("%d\n", top_b -> data);
		top_b = top_b -> next;
	}
}

int	reverse_simple(t_list **top_a, t_list **top_b)
{
	t_list	*next_node;
	int	count;

	count = 0;
	next_node = (*top_b) -> next;
	while (next_node != NULL)
	{
		if ((*top_b) -> data > next_node -> data)
		{
			push_a(top_a, top_b);
			next_node = (*top_b) -> next;
			count++;
		}
		else
		{
			swap_b(*top_b);
			count++;
		}
	}
	return (count);
}

int	simple(t_list **top_a, t_list **top_b)
{
	t_list	*next_node;
	int	count;

	count = 0;
	next_node = (*top_a) -> next;
	while (next_node != NULL)
	{
		if ((*top_a) -> data < next_node -> data)
		{
			push_b(top_a, top_b);
			next_node = (*top_a) -> next;
			count++;
		}
		else
		{
			swap_a(*top_a);
			count++;
		}
	}
	return (count);
}

void	algo(t_list *top_a, t_list *top_b)
{
	int	count;

	count = 0;
	if (disorder(top_a) == 0)
	{
		printf("Sorted!\n");
		return ;
	}
	while (disorder(top_a) != 0)
	{
		count = count + simple(&top_a, &top_b);
		count = count + reverse_simple(&top_a, &top_b);	
	}
	push_a(&top_a, &top_b);
	count++;
	print_stacks(top_a, top_b);
	printf("count: %d\n", count);
}

void	radix(t_list **top_a, t_list **top_b)
{
	int	t;
	int i;
	int	j;
	int p;
	int k;
	t_list *temp;

	t = 0;
	j = 0;
	k = 0;
	temp = *top_a;
	while ((*top_a) != NULL)
	{
		if ((*top_a) -> data < 0)
			(*top_a) -> data = (*top_a) -> data * -1;
		if ((*top_a) -> data > t)
			t = (*top_a) -> data;
		*top_a = (*top_a) -> next;
		k++;
	}
	i = 0;
	while (t > 0)
	{
		t = t / 10;
		i++;
	}
	printf("max digit: %d\n", i);
	j = 0;
	p = 10;
	while (j < k)
	{
		if (temp -> data % p == j)
			push_b(&temp, top_b);
		else
			rotate_a(&temp);
		j++;
	}
	print_stacks(*top_a, *top_b);
}

int	main(int argc, char **argv)
{
	t_list	*top_a;
	t_list	*top_b;
	float	ratio;

	top_b = NULL;
	if (argc < 2)
		return (printf("You failed!"), 0);
	top_a = makelst(argv);
	ratio = disorder(top_a);
	printf("ratio: %f\n\n", ratio);
	// algo(top_a, top_b);
	radix(&top_a, &top_b);
	printf("ratio: %f\n\n", ratio);
	return (0);
}

