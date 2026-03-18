/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   revers_operation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rovnania <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/13 14:39:50 by rovnania          #+#    #+#             */
/*   Updated: 2026/03/18 19:35:27 by rovnania         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	reverse_rotate(t_stack_node	**stack)
{
	t_stack_node	*first;
	t_stack_node	*last;

	first = *stack;
	if (!first || !first->next)
		return ;
	last = lstlast(first);
	last->next = first;
	first->prev = last;
	last->prev->next = NULL;
	last->prev = NULL;
	*stack = last;
}

void	rra(t_stack_node **a)
{
	reverse_rotate(a);
	write(1, "rra\n", 4);
}

void	rrb(t_stack_node **b)
{
	reverse_rotate(b);
	write(1, "rrb\n", 4);
}

void	rrr(t_stack_node **a, t_stack_node **b, t_count_opers *op)
{
	reverse_rotate(a);
	op->rrr++;
	op->all_op++;
	reverse_rotate(b);
	write(1, "rrr\n", 4);
}
