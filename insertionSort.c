/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertionSort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rovnania <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/15 16:37:19 by narehakobya       #+#    #+#             */
/*   Updated: 2026/03/22 13:46:25 by rovnania         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_stack **a, t_count_opers *op)
{
	int	first;
	int	second;
	int	third;

	first = (*a)->value;
	second = (*a)->next->value;
	third = (*a)->next->next->value;
	if (first > second && second < third && first < third)
		sa(a, op);
	else if (first > second && second > third)
	{
		sa(a, op);
		rra(a, op);
	}
	else if (first > second && second < third && first > third)
		ra(a, op);
	else if (first < second && second > third && first < third)
	{
		sa(a, op);
		ra(a, op);
	}
	else if (first < second && second > third && first > third)
		rra(a, op);
}

static int	get_pos(t_stack *stack, t_stack *target)
{
	int	pos;

	pos = 0;
	while (stack)
	{
		if (stack == target)
			return (pos);
		stack = stack->next;
		pos++;
	}
	return (pos);
}

t_stack	*find_min(t_stack *stack)
{
	t_stack	*min;

	min = stack;
	while (stack)
	{
		if (stack->value < min->value)
			min = stack;
		stack = stack->next;
	}
	return (min);
}

// samodeytelnost
int	hard_sorting(t_stack **a, t_count_opers *op, int size)
{
	if (size <= 1)
		return (1);
	if (size == 2)
	{
		if ((*a)->value > (*a)->next->value)
			sa(a, op);
		return (1);
	}
	return (0);
}

// inchi ogtagorcel stack_size(*a) erb size-@ arden hachvel es
int	insertion_sort(t_stack **a, t_stack **b, t_count_opers *op, int size)
{
	t_stack	*min;
	int		pos;
	int		cur_size;

	if (hard_sorting(a, op, size))
		return (0);
	while (stack_size(a) > 3)
	{
		min = find_min(*a);
		pos = get_pos(*a, min);
		cur_size = stack_size(a);
		if (pos <= cur_size / 2)
			while (*a != min)
				ra(a, op);
		else
			while (*a != min)
				rra(a, op);
		pb(a, b, op);
	}
	sort_three(a, op);
	while (*b)
		pa(a, b, op);
	return (0);
}
