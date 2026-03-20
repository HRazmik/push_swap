/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mergeSort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rovnania <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 12:45:09 by narehakobya       #+#    #+#             */
/*   Updated: 2026/03/20 18:41:25 by rovnania         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	assign_index(t_stack **a)
{
	t_stack	*tmp;
	t_stack	*cmp;
	int		index;

	tmp = *a;
	while (tmp)
	{
		index = 0;
		cmp = *a;
		while (cmp)
		{
			if (cmp->value < tmp->value)
				index++;
			cmp = cmp->next;
		}
		tmp->index = index;
		tmp = tmp->next;
	}
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

void	radix_sort(t_stack **a, t_stack **b,
			t_count_opers *op, bool flag)
{
	assign_index(a);
	int	size;
	int	max_bits;
	int	i;
	int	j;

	size = stack_size(*a);
	max_bits = get_max_bits(*a);
	i = 0;
	while (i < max_bits)
	{
		j = 0;
		while (j < size)
		{
			if (((*a)->index >> i) & 1)
				ra(a, op, flag);
			else
				pb(a, b, op, flag);
			j++;
		}
		while (*b)
			pa(a, b, op, flag);
		i++;
	}
}
