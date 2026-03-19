/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mergeSort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: narehakobyan <narehakobyan@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 12:45:09 by narehakobya       #+#    #+#             */
/*   Updated: 2026/03/19 17:15:40 by narehakobya      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int stack_size(t_stack *k)
{
    int len = 0;
    while (k)
    {
        len++;
        k = k->next;
    }
    return (len);
}


// void divide(t_stack **a, t_stack **b,t_count_opers *op, bool flag)
// {
//     int i = 0;
//     int size = stack_size(*a);
//     while (i < size / 2)
//     {
//         pb(a, b, op, flag);
//         i++;
//     }
// }

// void merge(t_stack **a, t_stack **b, t_count_opers *op, bool flag)
// {
//     int size;
//     int i;
//     while (*b)
//     {
//         size = stack_size(*a);
//         i = 0;
//         while (i < size && (*a)->value < (*b)->value)
//         {
//             ra(a,op,flag);
//             i++;
//         }
//         pa(b, a,op,flag);
//     }
// }

// void final_rotate(t_stack **a,t_count_opers *op, bool flag)
// {
//     int min = find_min(*a);
//     while ((*a)->value != min)
//         ra(a,op,flag);
// }

// void merge_sort(t_stack **a, t_stack **b,t_count_opers *op, bool flag)
// {
//     int size = stack_size(*a);
//     if (size <= 1)
//         return;
//     divide(a, b,op,flag);
//     merge_sort(a, b,op,flag);
//     merge_sort(b, a,op,flag);
//     merge(a, b,op,flag);
// }

void	assign_index(t_stack *a)
{
	t_stack	*tmp;
	t_stack	*cmp;
	int		index;

	tmp = a;
	while (tmp)
	{
		index = 0;
		cmp = a;
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
			pa(b, a, op, flag);
		i++;
	}
}