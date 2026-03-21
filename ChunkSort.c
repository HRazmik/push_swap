/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ChunkSort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: narehakobyan <narehakobyan@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 12:15:43 by narehakobya       #+#    #+#             */
/*   Updated: 2026/03/21 14:31:59 by narehakobya      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

static t_stack	*find_max_node(t_stack *stack)
{
	t_stack	*max_node;

	if (!stack)
		return (NULL);
	max_node = stack;
	while (stack)
	{
		if (stack->index > max_node->index)
			max_node = stack;
		stack = stack->next;
	}
	return (max_node);
}

void	assign_index(t_stack *a, int size)
{
	t_stack	*ptr;
	t_stack	*highest;
	int		i;

	ptr = a;
	while (ptr)
	{
		ptr->index = -1;
		ptr = ptr->next;
	}

	i = size;
	while (--i >= 0)
	{
		ptr = a;
		highest = NULL;
		while (ptr)
		{
			if (ptr->index == -1 && (highest == NULL || ptr->value > highest->value))
				highest = ptr;
			ptr = ptr->next;
		}
		if (highest)
			highest->index = i;
	}
}

static void	push_back_to_a(t_stack **a, t_stack **b, t_count_opers *op)
{
	t_stack	*max;

	while (*b)
	{
		max = find_max_node(*b);
		if (get_pos(*b, max) <= stack_size(*b) / 2)
			while (*b != max)
				rb(b, op, true);
		else
			while (*b != max)
				rrb(b, op, true);
		pa(a, b, op, true);
	}
}

int	get_chunk_step(int max_index)
{
	if (max_index <= 20)
		return (max_index / 2);
	else if (max_index <= 100)
		return (16);
	else if (max_index <= 500)
		return (38);
	else
		return (max_index / 13);
}

void	medium_sort(t_stack **a, t_stack **b, t_count_opers *op)
{
	int	i;
	int	range;
	int	size;

	i = 0;
	size = stack_size(*a);
	range = get_chunk_step(size); 
	
	while (*a)
	{
		if ((*a)->index <= i)
		{
			pb(a, b, op, true);
			rb(b, op, true);
			i++;
		}
		else if ((*a)->index <= i + range)
		{
			pb(a, b, op, true);
			i++;
		}
		else
			ra(a, op, true);
	}
	push_back_to_a(a, b, op);
}
