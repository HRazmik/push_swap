/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_operation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rovnania <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/13 15:00:51 by rovnania          #+#    #+#             */
/*   Updated: 2026/03/20 12:56:15 by rovnania         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push(t_stack **from, t_stack **to)
{
	t_stack	*node;

	if (!from || !*from)
		return ;
	node = *from;
	*from = node->next;
	if (*from)
	(*from)->prev = NULL;
	node->next = *to;
	node->prev = NULL;
	if (*to)
		(*to)->prev = node;
	*to = node;
}

void	pa(t_stack **a, t_stack **b,t_count_opers *op, bool flag)
{
	push(b, a);
	op->pa++;
	op->all_op++;
	if (flag)
		write(1, "pa\n", 3);
}

void	pb(t_stack **a, t_stack **b,t_count_opers *op, bool flag)
{
	push(a, b);
	op->pb++;
	op->all_op++;
	if (flag)
		write(1, "pb\n", 3);
}
