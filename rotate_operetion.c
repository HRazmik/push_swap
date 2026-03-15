/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_operetion.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rovnania <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/13 14:35:16 by rovnania          #+#    #+#             */
/*   Updated: 2026/03/13 15:24:09 by rovnania         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack_node	*lstlast(t_stack_node *lst)
{
	t_stack_node	*tmp;

	tmp = lst;
	if (!lst)
		return (NULL);
	while (tmp->next)
		tmp = tmp->next;
	return (tmp);
}

static void	rotate(t_stack_node **stack)
{
	t_stack_node	*first;
	t_stack_node	*last;
	t_stack_node	*new_head;

	first = *stack;
	if (!first || !first->next)
		return ;
	new_head = first->next;
	last = lstlast(first);
	new_head->prev = NULL;
	last->next = first;
	first->prev = last;
	first->next = NULL;
	*stack = new_head;
}

void	ra(t_stack_node **a)
{
	rotate(a);
	write(1, "ra\n", 3);
}

void	rb(t_stack_node **b)
{
	rotate(b);
	write(1, "rb\n", 3);
}

void	rr(t_stack_node **a, t_stack_node **b)
{
	rotate(a);
	rotate(b);
	write(1, "rr\n", 3);
}
