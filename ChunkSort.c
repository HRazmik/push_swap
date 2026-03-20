/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ChunkSort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: narehakobyan <narehakobyan@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 12:15:43 by narehakobya       #+#    #+#             */
/*   Updated: 2026/03/20 20:38:09 by narehakobya      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_size(t_stack *k)
{
	int	len;

	len = 0;
	while (k)
	{
		len++;
		k = k->next;
	}
	return (len);
}
int	find_max(t_stack *a)
{
	int	max;

	max = a->value;
	while (a)
	{
		if (a->value > max)
			max = a->value;
		a = a->next;
	}
	return (max);
}

int	find_position(t_stack *a, int value)
{
	int	i;

	i = 0;
	while (a)
	{
		if (a->value == value)
			return (i);
		i++;
		a = a->next;
	}
	return (-1);
}

int	exists_in_range(t_stack *a, int min, int max)
{
	while (a)
	{
		if (a->value >= min && a->value <= max)
			return (1);
		a = a->next;
	}
	return (0);
}

int	find_best_direction(t_stack *a, int min, int max)
{
	int		i;
	int		size;
	t_stack	*tmp;

	size = stack_size(a);

	// forward search (ra)
	tmp = a;
	i = 0;
	while (tmp)
	{
		if (tmp->value >= min && tmp->value <= max)
			break ;
		i++;
		tmp = tmp->next;
	}

	// backward distance (rra)
	int back = size - i;

	if (i <= back)
		return (i);        // use ra
	else
		return (-back);    // use rra
}

void	push_chunk(t_stack **a, t_stack **b, int min, int max,
		t_count_opers *op, bool flag)
{
	int	move;

	while (exists_in_range(*a, min, max))
	{
		move = find_best_direction(*a, min, max);

		if (move >= 0)
		{
			while (move-- > 0)
				ra(a, op, flag);
		}
		else
		{
			move = -move;
			while (move-- > 0)
				rra(a, op, flag);
		}

		pb(a, b, op, flag);

		// organize B (important)
		if ((*b)->value < (min + max) / 2)
			rb(b, op, flag);
	}
}

void	push_back_max(t_stack **a, t_stack **b,
		t_count_opers *op, bool flag)
{
	int	max;
	int	pos;
	int	size;

	while (*b)
	{
		max = find_max(*b);
		pos = find_position(*b, max);
		size = stack_size(*b);

		if (pos <= size / 2)
		{
			while ((*b)->value != max)
				rb(b, op, flag);
		}
		else
		{
			while ((*b)->value != max)
				rrb(b, op, flag);
		}
		pa(a, b, op, flag);
	}
}

void	medium_sort(t_stack **a, t_stack **b,
		t_count_opers *op, bool flag)
{
	int	size;
	int	chunk;
	int	min;
	int	start;
	int	end;

	size = stack_size(*a);

	if (size <= 100)
		chunk = 15;
	else
		chunk = 40;

	min = find_min(*a);

	while (*a)
	{
		start = min;
		end = min + chunk;
		push_chunk(a, b, start, end, op, flag);
		min = end + 1;
	}
	push_back_max(a, b, op, flag);
}
// int	chunk_size(int n)
// {
// 	int	i;

// 	i = 1;
// 	while (i * i < n)
// 		i++;
// 	return (i);
// }

// void	push_chunk(t_stack **a, t_stack **b, int min, int max,
// 		t_count_opers *op, bool flag)
// {
// 	int	size;
// 	int	i;

// 	size = stack_size(*a);
// 	i = 0;
// 	while (i < size)
// 	{
// 		if ((*a)->value >= min && (*a)->value <= max)
// 			pb(a, b, op, flag);
// 		else
// 			ra(a, op, flag);
// 		i++;
// 	}
// }

// void	push_back_max(t_stack **a, t_stack **b, t_count_opers *op, bool flag)
// {
// 	int	max;
// 	int	pos;
// 	int	size;

// 	while (*b)
// 	{
// 		max = find_max(*b);
// 		pos = find_position(*b, max);
// 		size = stack_size(*b);
// 		if (pos <= size / 2)
// 		{
// 			while ((*b)->value != max)
// 				rb(b, op, flag);
// 		}
// 		else
// 		{
// 			while ((*b)->value != max)
// 				rrb(b, op, flag);
// 		}
// 		pa(a, b, op, flag);
// 	}
// }

// void	medium_sort(t_stack **a, t_stack **b, t_count_opers *op, bool flag)
// {
// 	int	size;
// 	int	chunk;
// 	int	min;
// 	int	start;
// 	int	end;
// 	size = stack_size(*a);
// 	chunk = chunk_size(size);
// 	min = find_min(*a);
// 	while (*a)
// 	{
// 		start = min;
// 		end = min + chunk;
// 		push_chunk(a, b, start, end, op, flag);
// 		min = end + 1;
// 	}
// 	// write(1, "123\n", 4);
// 	push_back_max(a, b, op, flag);
// }

