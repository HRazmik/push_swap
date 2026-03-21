/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   revers_operation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rovnania <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/13 14:39:50 by rovnania          #+#    #+#             */
/*   Updated: 2026/03/21 16:38:23 by rovnania         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	reverse_rotate(t_stack **stack)
{
	t_stack	*first;
	t_stack	*last;

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

void	rra(t_stack **a, t_count_opers *op)
{
	reverse_rotate(a);
	op->rra++;
	op->all_op++;
	write(1, "rra\n", 4);
}

void	rrb(t_stack **b, t_count_opers *op)
{
	reverse_rotate(b);
	op->rrb++;
	op->all_op++;
	write(1, "rrb\n", 4);
}

void	rrr(t_stack **a, t_stack **b, t_count_opers *op)
{
	reverse_rotate(a);
	reverse_rotate(b);
	op->rrr++;
	op->all_op++;
	write(1, "rrr\n", 4);
}
