/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertionSort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: narehakobyan <narehakobyan@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/15 16:37:19 by narehakobya       #+#    #+#             */
/*   Updated: 2026/03/19 17:50:45 by narehakobya      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_min(t_stack *a)
{
	int	min;

	min = a->value;
	while (a)
	{
		if (a->value < min)
			min = a->value;
		a = a->next;
	}
	return (min);
}

void	min_rotate(t_stack **a, t_count_opers *op, bool flag)
{
	int	min;

	min = find_min(*a);
	while ((*a)->value != min)
		ra(a, op, flag);
}

void	rotate_pos(t_stack **a, int value, t_count_opers *op, bool flag)
{
	while (*a && value > (*a)->value)
		ra(a, op, flag);
}

void	insertion_sort(t_stack **a, t_stack **b,
			t_count_opers *op, bool flag)
{
	while (*a)
		pb(a, b, op, flag);
	while (*b)
	{
		rotate_pos(a, (*b)->value, op, flag);
		pa(a, b, op, flag);
	}
	min_rotate(a, op, flag);
}