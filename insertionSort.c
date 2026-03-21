/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertionSort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: narehakobyan <narehakobyan@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/15 16:37:19 by narehakobya       #+#    #+#             */
/*   Updated: 2026/03/21 14:31:18 by narehakobya      ###   ########.fr       */
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

#include "push_swap.h"


void	sort_three(t_stack **a, t_count_opers *op)
{
	int	first = (*a)->value;
	int	second = (*a)->next->value;
	int	third = (*a)->next->next->value;

	if (first > second && second < third && first < third)
		sa(a, op, true);
	else if (first > second && second > third)
	{
		sa(a, op, true);
		rra(a, op, true);
	}
	else if (first > second && second < third && first > third)
		ra(a, op, true);
	else if (first < second && second > third && first < third)
	{
		sa(a, op, true);
		ra(a, op, true);
	}
	else if (first < second && second > third && first > third)
		rra(a, op, true);
}


static int	get_pos(t_stack *stack, t_stack *target)
{
	int	pos = 0;
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
	t_stack	*min = stack;
	while (stack)
	{
		if (stack->value < min->value)
			min = stack;
		stack = stack->next;
	}
	return (min);
}


void	insertion_sort(t_stack **a, t_stack **b, t_count_opers *op)
{
	int	size = stack_size(*a);

	if (size <= 1)
		return ;
	if (size == 2)
	{
		if ((*a)->value > (*a)->next->value)
			sa(a, op, true);
		return ;
	}

	while (stack_size(*a) > 3)
	{
		t_stack *min = find_min(*a);
		int pos = get_pos(*a, min);
		int cur_size = stack_size(*a);

		if (pos <= cur_size / 2)
			while (*a != min)
				ra(a, op, true);
		else
			while (*a != min)
				rra(a, op, true);
		pb(a, b, op, true);
	}

	sort_three(a, op);
	while (*b)
		pa(a, b, op, true);
}
