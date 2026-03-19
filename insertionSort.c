/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertionSort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rovnania <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/15 16:37:19 by narehakobya       #+#    #+#             */
/*   Updated: 2026/03/19 18:51:38 by rovnania         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int find_min(t_stack *a)
{
    int min;

    min = a->value;
    while (a)
    {
        if (a->value < min)
            min = a->value;
        a = a->next;
    }
    return (min);
}

void min_rotate(t_stack **a, t_count_opers *op, bool flag)
{
    int min;

    min = find_min(*a);
    while ((*a)->value != min)
        ra(a,op,flag);
}

void rotate_pos(t_stack **a, int value, t_count_opers *op, bool flag)
{
    t_stack *start;

    if (!a || !*a)
        return;

    start = *a;
    while (1)
    {
        if ((*a)->value >= value)
            break;
        ra(a, op, flag);
        if (*a == start)
            break;
    }
}

void insertion_sort(t_stack **a, t_stack **b, t_count_opers *op, bool flag)
{
    while (*a)
    {

        pb(a,b,op,flag);
    }
    while (*b)
    {
        rotate_pos(a, (*b)->value,op,flag);
        pa(a, b, op, flag);
    }

    min_rotate(a,op,flag);
}
