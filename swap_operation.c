/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_operation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rovnania <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/13 15:00:26 by rovnania          #+#    #+#             */
/*   Updated: 2026/03/18 20:12:12 by rovnania         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap(t_stack **stack)
{
	t_stack	*first;
	t_stack	*second;

	if (!*stack || !(*stack)->next)
		return ;
	first = *stack;
	second = first->next;
	first->next = second->next;
	if (second->next)
		second->next->prev = first;
	second->prev = NULL;
	second->next = first;
	first->prev = second;
	*stack = second;
}

void	sa(t_stack **a,t_count_opers *op, bool flag)
{
	swap(a);
	op->sa++;
	if (flag)
		write(1, "sa\n", 3);
}

void	sb(t_stack **b,t_count_opers *op, bool flag)
{
	swap(b);
	op->sb++;
	if (flag)
		write(1, "sb\n", 3);
}

void	ss(t_stack **a, t_stack **b,t_count_opers *op, bool flag)
{
	swap(a);
	swap(b);
	op->ss++;
	if (flag)
		write(1, "ss\n", 3);
}
