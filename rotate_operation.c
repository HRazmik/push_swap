/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_operation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rovnania <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/13 14:35:16 by rovnania          #+#    #+#             */
/*   Updated: 2026/03/19 18:02:16 by rovnania         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*lstlast(t_stack *lst)
{
	t_stack	*tmp;

	tmp = lst;
	if (!lst)
		return (NULL);
	while (tmp->next)
		tmp = tmp->next;
	return (tmp);
}

static void	rotate(t_stack **stack)
{
	t_stack	*first;
	t_stack	*last;
	t_stack	*new_head;

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

void	ra(t_stack **a,t_count_opers *op, bool flag)
{
	rotate(a);
	op->ra++;
	if (flag)
		write(1, "ra\n", 3);
}

void	rb(t_stack **b,t_count_opers *op, bool flag)
{
	rotate(b);
	op->rb++;
	if (flag)
		write(1, "rb\n", 3);
}

void	rr(t_stack **a, t_stack **b,t_count_opers *op, bool flag)
{
	rotate(a);
	rotate(b);
	op->rr++;
	if (flag)
		write(1, "rr\n", 3);
}
