/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RadixSort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rovnania <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 12:45:09 by narehakobya       #+#    #+#             */
/*   Updated: 2026/03/21 19:46:05 by rovnania         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_size(t_stack *stack)
{
	int	count;

	count = 0;
	while (stack)
	{
		stack = stack->next;
		count++;
	}
	return (count);
}

int	get_max_bits(t_stack *a)
{
	int	max;
	int	bits;

	max = 0;
	while (a)
	{
		if (a->index > max)
			max = a->index;
		a = a->next;
	}
	bits = 0;
	while ((max >> bits) != 0)
		bits++;
	return (bits);
}

int	radix_sort(t_stack **a, t_stack **b, t_count_opers *op)
{
	int	size;
	int	max_bits;
	int	i;
	int	j;

	size = stack_size(*a);
	if (size <= 5)
		return (medium_sort(a, b, op));
	max_bits = get_max_bits(*a);
	i = 0;
	while (i < max_bits)
	{
		j = 0;
		while (j++ < size)
		{
			if (((*a)->index >> i) & 1)
				ra(a, op);
			else
				pb(a, b, op);
		}
		while (*b)
			pa(a, b, op);
		i++;
	}
	return (0);
}
