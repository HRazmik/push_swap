/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_operetion.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rovnania <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/13 15:00:51 by rovnania          #+#    #+#             */
/*   Updated: 2026/03/13 15:23:37 by rovnania         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push(t_stack_node **from, t_stack_node **to)
{
	t_stack_node	*node;
	t_stack_node	*tmp;

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

void	pa(t_stack_node **a, t_stack_node **b)
{
	push(b, a);
	write(1, "pa\n", 3);
}

void	pb(t_stack_node **a, t_stack_node **b)
{
	push(a, b);
	write(1, "pb\n", 3);
}
