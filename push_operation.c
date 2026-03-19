/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_operation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rovnania <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/13 15:00:51 by rovnania          #+#    #+#             */
/*   Updated: 2026/03/19 18:02:37 by rovnania         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push(t_stack **from, t_stack **to)
{
	t_stack	*node;
	t_stack	*tmp;

	if (!from)
		return ;
	node = *from;
	if (node->next)
		node->next->prev = NULL;
	tmp = node->next;
	node->next = *to;
	if (*to)
	{
		(*to)->prev = node;
	}
	*from = tmp;
	*to = node;
}

void	pa(t_stack **a, t_stack **b,t_count_opers *op, bool flag)
{
	push(b, a);
	op->pa++;
	if (flag)
		write(1, "pa\n", 3);
}

void	pb(t_stack **a, t_stack **b,t_count_opers *op, bool flag)
{
	push(a, b);
	op->pb++;
	if (flag)
		write(1, "pb\n", 3);
}
